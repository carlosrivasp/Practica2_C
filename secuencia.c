#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "auxiliar.h"

int MaximExit();
int esNumReal(char *arg);
int esNumVal(char *arg);
int main(int argc,char *argv[])
{
	int codigo_salida=0;
	int MaximaSalidas=MaximExit();double Hasta , desde,paso;
	if(argc==4)
	{
		if(esNumReal(argv[1])==1)
		{
			fprintf(stderr,"%s","secuencia: Error(EX_USAGE), uso incorrecto del mandato. ""Success""\n");			
			fprintf(stderr,"%s%c%s%c%s\n","secuencia+.*",'"',"hasta",'"'," no es un numero real");
			return EX_USAGE;
		}
		else if(esNumReal(argv[2])==1)
		{
			fprintf(stderr,"%s","secuencia: Error(EX_USAGE), uso incorrecto del mandato. ""Success""\n");
			fprintf(stderr,"%s%c%s%c%s\n","secuencia+.*",'"',"desde",'"'," no es un numero real");
			return EX_USAGE;
		}
		else if(esNumReal(argv[3])==1)
		{
			fprintf(stderr,"%s","secuencia: Error(EX_USAGE), uso incorrecto del mandato. ""Success""\n");			
			fprintf(stderr,"%s%c%s%c%s\n","secuencia+.*",'"',"paso",'"'," no es un numero real");
			return EX_USAGE;
		}		
	Hasta =strtod(argv[1], &argv[1]);
	desde =strtod(argv[2], &argv[2]);
	paso=strtod(argv[3], &argv[3]);
		
	}
	if(argc>4)
	{
	
		fprintf(stderr,"%s","secuencia: Error(EX_USAGE), uso incorrecto del mandato. ""Success""\n");
		fprintf(stderr,"%s","secuencia+ El número de argumentos no es correcto.\n");
		return EX_USAGE;
	}

	 if(argc==4 && paso==0 )
	{
		fprintf(stderr,"%s","secuencia: Error(EX_USAGE), uso incorrecto del mandato. ""Success""\n");
		fprintf(stderr,"%s%c%s%c%s","secuencia+.*",'"',"paso",'"',"no permitido.\n");
		return EX_USAGE;
	}
	
	if(argc==4 && ((Hasta > desde && paso<0)||(Hasta < desde && paso > 0)||((Hasta == desde) && paso!=0)))
		{

			fprintf(stderr,"%s","secuencia: Error(EX_USAGE), uso incorrecto del mandato. ""Success""\n");
			fprintf(stderr,"%s\n","secuencia+ El signo de paso no permite recorrer el intervalo en el sentido desde");	
			
		return EX_USAGE;
		}

	if(argc==1 )
		{
			Hasta=10;desde=1;paso=1;
			double i;int contador=0;
			for(i=desde;i<= Hasta && contador<MaximaSalidas ;i=i+paso)
				{
					printf("\t%g\n",i);
					contador++;
				}
					if(((Hasta-desde)!=(contador-1)) && contador>=MaximaSalidas)
					{
						fprintf(stderr,"%s\n","secuencia: Error(EX_NOPERM), permiso denegado. Success");
						fprintf(stderr,"%s\n","secuencia+ Se intentó superar el limite de salida.");
						return EX_NOPERM;			
					}
					return EX_OK;
				}
		
	if(argc==2 )
		{
			
			if((strcmp(argv[1],"-h")==0)||(strcmp(argv[1],"--help")==0)){
			fprintf(stdout,"secuencia: USO: secuencia [ hasta[desde [paso ]] ]\n");
			fprintf(stdout,"secuencia: muestra por pantalla la secuencia de numeros que hay desde el parametro ""desde"" hasta el parametro ""hasta"" a saltos del parametro ""paso"".\n");
			return codigo_salida=EX_OK;
			}
			else{
				if(esNumReal(argv[1])==1)
				{
					fprintf(stderr,"%s","secuencia: Error(EX_USAGE), uso incorrecto del mandato. ""Success""\n");
					fprintf(stderr,"%s%c%s%c%s\n","secuencia+.*",'"',"hasta",'"'," no es un numero real");
					return EX_USAGE;
				}
				Hasta=strtod(argv[1], &argv[1]);desde=1;paso=1;
				if(Hasta <= 1)
				{
					fprintf(stderr,"%s","secuencia: Error(EX_USAGE), permiso denegado. ""Success""\n");
					fprintf(stderr,"%s%c%s%c%s\n","secuencia+.*",'"',"desde",'"'," donde empieza, el signo de paso no permite recorrer el intervalo en el sentido desde.");	
					return EX_USAGE;
				}
				
				else 
				{
				double i;
				double contador=0;
				for(i=desde;i<= Hasta && contador<MaximaSalidas ;i=i+paso)
				{
			
					printf("\t%g\n",i);
					contador++;
				}
					if(((Hasta-desde)!=(contador-1)) && contador>=MaximaSalidas)
					{
						fprintf(stderr,"%s","secuencia: Error(EX_NOPERM), permiso denegado. ""Success""\n");
						fprintf(stderr,"%s\n","secuencia+ Se intentó superar el limite de salida.");
						return EX_NOPERM;			
					}
					return EX_OK;
				}
			}
		}
	
	 if(argc==3 )
		{
			if(esNumReal(argv[1])==1)
			{
				fprintf(stderr,"%s","secuencia: Error(EX_USAGE), uso incorrecto del mandato. ""Success""\n");
				fprintf(stderr,"%s%c%s%c%s\n","secuencia+.*",'"',"hasta",'"',"no es un numero real");
				return EX_USAGE;
			}
			if(esNumReal(argv[2])==1)
			{
				fprintf(stderr,"%s","secuencia: Error(EX_USAGE), uso incorrecto del mandato. ""Success""\n");
				fprintf(stderr,"%s%c%s%c%s\n","secuencia+.*",'"',"desde",'"',"no es un numero real");
				return EX_USAGE;
			}
			Hasta=strtod(argv[1],&argv[1]);desde=strtod(argv[2],&argv[2]);paso=1;
			if(Hasta <= desde )
			{
				fprintf(stderr,"%s\n","secuencia: Error(EX_USAGE), permiso denegado. ""Success""");
				fprintf(stderr,"%s\n","secuencia+ Se intentó recorrer un intervalo imposible.");		
				return EX_USAGE;
			}
			
			else
			{
				double i;
				double contador=0;
				for(i=desde;i<= Hasta && contador<MaximaSalidas;i=i+paso)
				{
				printf("\t%g\n",i);
				contador++;
				}
				if(contador>=MaximaSalidas)
				{
					fprintf(stderr,"%s \n","secuencia: Error(EX_USAGE), permiso denegado. ""Success""\n");
					fprintf(stderr,"%s\n","secuencia+ Se intentó superar el limite de salida.");
					return EX_USAGE;
				}
				else{
				return EX_OK;
				}
			}
		}

	 if(argc==4 && codigo_salida==0)
		{
			double i;
			double contador=0;
			
			if(paso > 0)
			{
			
				for(i=desde;i <= Hasta && contador<MaximaSalidas;i=i+paso)
				{
				printf("\t%g\n",i);
				contador++;
				}
				if(((Hasta-desde)!=(contador-1)) && contador>=MaximaSalidas)
				{
					fprintf(stderr,"%s\n","secuencia: Error(EX_NOPERM), permiso denegado. Success");
					fprintf(stderr,"%s","secuencia+ Se intentó superar el limite de salida.");
					return EX_NOPERM;
				}
				else
				{
					return EX_OK;
				}
			}
			else if(paso < 0)
			{
				for(i=desde;i >= Hasta && contador<MaximaSalidas;i=i+paso)
				{
				printf("\t%g\n",i);
				contador++;
				}
			}
				if(((Hasta-desde)!=(contador-1)) && contador>=MaximaSalidas)
				{
					fprintf(stderr,"%s","secuencia: Error(EX_NOPERM), permiso denegado. ""Success""\n");
					fprintf(stderr,"%s\n","secuencia+ Se intentó superar el limite de salida.");
					return EX_NOPERM;
				}
				else{
					return EX_OK;
				}
		}
	return 0;
}



int MaximExit()
{
	
	char* MAXIMO=getenv("MAX_OUTPUT");int valido=esNumVal(MAXIMO);int MaximaSalidas;
	if(MAXIMO==NULL || valido==1 ||(MAXIMO!=NULL && strlen(MAXIMO)==0))
	{
		MaximaSalidas=100;
	}
	else
	MaximaSalidas=strtod(MAXIMO,&MAXIMO);
	return MaximaSalidas;
}

int esNumReal(char *arg)
{
	int j=0;int isDigit =0;int punto=0;
	if(arg[j]=='-')j++;
	while(j<strlen(arg) && isDigit == 0 && punto<=1)
	{
	 if((arg[j] < 58 && arg[j] >47 )||arg[j]=='.')
	{
		if(arg[j]=='.')	{punto++;}    
		isDigit = 0;
	}
	 else
	    isDigit = 1;
	    j++;
	}
	if(punto>1)isDigit=1;
	return isDigit;
}
int esNumVal(char *arg)
{
	
	if(arg==NULL)return 1;
	int isDigit = 0;
	int j=0;
	while(j<strlen(arg) && isDigit == 0)
	{
	 if(arg[j] <= 57 && arg[j] >=48)
	    isDigit = 0;
	 else
	    isDigit = 1;
	    j++;
	}
	return isDigit;
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>

int main ( int argc, char *argv[] ){
	char *p;
	double desde = 1.0;
	double hasta = 10.0;
	double paso = 1.0;
	double n;

	if (argc == 2 && (strcmp (argv[1], "-h") == 0 || (strcmp (argv[1], "--help") == 0) ) ) {
      printf ("%s: Uso: secuencia [ hasta [ desde [ paso ]]]\n", argv[0]);
      printf ("%s: secuencia: Genera la secuencia de numeros en el intervalo y paso indicados.\n", argv[0]);
      return EX_OK;

   	}

	if(argc == 1){
		for(n=desde; n <= hasta;n=n+paso){
			printf("\t%g\n",n);
		}
	return EX_OK;
	}
	else if(argc == 2){
		hasta = strtod(argv[1], &p);
		for(n = desde; n <= hasta; n= n+ paso){
			printf("\t%g\n",n);	
		}
	return EX_OK;
	}
	else if(argc == 3){
		desde= strtod(argv[2],&p);
		hasta = strtod(argv[1],&p);
		for(n = desde; n <= hasta; n= n+ paso){
			printf("\t%g\n",n);
		}
	return EX_OK;
	}
	else if(argc == 4){
		paso= strtod(argv[3],&p);
		desde= strtod(argv[2],&p);
		hasta = strtod(argv[1],&p);
		for(n = desde; n <= hasta; n= n+ paso){
			printf("\t%g\n",n);
		}
	return EX_OK;
}*/
