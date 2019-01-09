#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auxiliar.h"
#include <sysexits.h>
#include <errno.h>

char *invertir_linea(char  * linea);
void delRevesFichero(FILE * abierto);

int main(int argc, char * argv[])
{

	int codigo_salida = EX_OK;
	int i;
	
	if(argc==2 && ((strcmp(argv[1],"-h")==0)||(strcmp(argv[1],"--help")==0)))
	{
		fprintf(stdout,"delreves: USO: delreves [ fichero... ]\n");
		fprintf(stdout,"delreves: Invierte el contenido de las líneas de los ficheros (o de la entrada).\n");
		return codigo_salida;
	}
	
	if(argc==1)
	{
		//delRevesFichero(stdin);
		return codigo_salida;
	}
	else 
	{
		for(i=1;i<argc;i++)
		{
			FILE * abierto = fopen(argv[i], "r");
			if (abierto == NULL) 
			{
				fprintf(stderr,"%s\n","delreves: Error(EX_NOINPUT), no se puede abrir la entrada. 'Success'");
				if(errno == ENOENT)
				{
					fprintf(stderr,"%s%c%s%c%s\n","delreves+.*",'"',"no_existe",'"',"el fichero");
				}
				else
				{
					fprintf(stderr,"%s%c%s%c%s\n","delreves+.*",'"',"no_legible",'"',"el fichero");
				}
				
				return EX_NOINPUT;
			}		
		}
	
		for(i=1;i<argc;i++)
		{
			FILE * abierto = fopen(argv[i], "r");
			delRevesFichero(abierto);
			fclose(abierto);		
		}
	}
		
	return codigo_salida;
}


void delRevesFichero(FILE * abierto)
{
	char linea[2048];
	while(fgets(linea,2048,abierto))
	{
		char * invertida=invertir_linea(linea);
		if(invertida[0]=='\n')
		{
			int i;
			for(i=1;i<strlen(invertida);i++)
			{
				invertida[i-1]=invertida[i];
			}
			invertida[strlen(invertida)-1]='\n';
		}
		printf("%s",invertida);
	}
}

char * invertir_linea(char * linea)
{
	char auxiliar[strlen(linea)];int cont=0;int i;	
	for(i=strlen(linea)-1;i>=0;i--)
	{	
		auxiliar[cont]=linea[i];
		cont++;
	}
	auxiliar[cont]=linea[strlen(linea)];
	linea=auxiliar;	
	return linea;
}

