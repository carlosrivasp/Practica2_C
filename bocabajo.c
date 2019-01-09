#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>
#include <errno.h>
#include <libgen.h>
#include "auxiliar.h"

#define MAXLINEA 2048

struct elem_pila
{
	char linea[MAXLINEA];
	struct elem_pila * siguiente;
};


typedef struct elem_pila tPila;
tPila * pila = NULL;

void pushLines(FILE * pf);
void popLines();

int main(int argc, char *argv[])
{
	FILE * pf;
	int arg;
	argv0 = basename(argv[0]);
	if(argc==2 && (strcmp("-h",argv[1])==0||strcmp("--help",argv[1])==0)){
		fprintf(stdout,"bocabajo: USO: bocabajo [ fichero... ]\n");
		fprintf(stdout,"delreves: Invierte el contenido de las líneas de los ficheros (o de la entrada).\n");
		free(argv0);
		exit(EX_OK);
	}
	
	if(argc==1){
		pushLines(stdin);
	}
	else{
		for(arg=1; arg < argc; arg++){
			pf = fopen(argv[arg],"r");
			if(pf == NULL){
				Error(EX_NOINPUT,"El fichero \"%s\" no puede ser leido.",argv[arg]);
			}
			pushLines(pf);
			fclose(pf);
		}
	}
	popLines();
	free(argv0);
	exit(EX_OK);

}
/*FUNCIONES AUXILIARES*/

	void pushLines(FILE * pf){
		char nueva[MAXLINEA];
		while(fgets(nueva,MAXLINEA,pf)!=NULL){
			tPila *q = (tPila *) malloc(sizeof(tPila));
			if(q==NULL){
				Error(EX_OSERR,"No se puede ubicar la memoria dinamica necesaria");
			}
			q->siguiente=pila;
			strcpy(q->linea,nueva);
			pila=q;
		}
	}
	
	void popLines(){
		tPila *q;
		while(pila!=NULL){
			printf("%s",pila->linea);
			q=pila;
			pila=pila->siguiente;
			free(q);
		}
	}

/*struct elem_pila
{
	char linea[MAXLINEA];
	struct elem_pila * siguiente;
};


typedef struct elem_pila tPila;
tPila * pila = NULL;

void pushLines(FILE * pf);
void popLines();

int main(int argc, char *argv[])
{
	FILE * pf;
	int arg;
	argv0 = basename(argv[0]);
	if(argc==2 && ((strcmp("-h",argv[1])==0)||(strcmp("--help",argv[1])==0))){
		fprintf(stdout,"bocabajo: USO: bocabajo [ fichero... ]\n");
		fprintf(stdout,"delreves: Invierte el contenido de las líneas de los ficheros (o de la entrada).\n");
		return EX_OK;
	}
	
	if(argc==1){
		pushLines(stdin);
	}
	else{
		for(arg=1; arg < argc; arg++){
			pf = fopen(argv[arg],"r");
			if(pf==NULL){
				Error(EX_NOINPUT,"El fichero \"%s\" no puede ser leido.",argv[arg]);
			}
			pushLines(pf);
			fclose(pf);
		}
	}
	popLines();
	free(argv0);
	exit(EX_OK);
	return 0;
}
FUNCIONES AUXILIARES

	void pushLines(FILE * pf){
		char nueva[MAXLINEA];
		while(fgets(nueva,MAXLINEA,pf)!=NULL){
			tPila *q = (tPila *) malloc(sizeof(tPila));
			if(q==NULL){
				Error(EX_OSERR,"No se puede ubicar la memoria dinamica necesaria");
			}
			q->siguiente=pila;
			strcpy(q->linea,nueva);
			pila=q;
		}
	}
	
	void popLines(){
		tPila *q;
		while(pila!=NULL){
			printf("%s",pila->linea);
			q=pila;
			pila=pila->siguiente;
			free(q);
		}
	}
*/
