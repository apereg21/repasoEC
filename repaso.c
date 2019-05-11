#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[]){
	int op,op1,contFallos=0,acierto=0;
	if(argc!=3){
		printf("Numero incorrecto de argumentos. Recuerde:\n./repaso nombreUser contraseña\n");
	}
	else{
		do{
			if((strcmp(argv[1],"elAlexGame"))&&(atoi(argv[2])!=1234)){
				printf("Acceso denegado\nFin de programa\n");
				exit(-1);
			}
			else{
				acierto=1;
				printf("Bienvenido %s\n",argv[1]);	
			}
		}while(acierto!=1);
		printf("¿Que desea hacer %s?\n",argv[1]);
		printf("1. Factorial\n2. Matrices\n3. Fibonacci\n4.Salir\nOpcion elegida: ");
		scanf("%d",&op);
		printf("%s eligio la opcion %d",argv[1],op);
		switch(op){
			
			case 1:
				printf("1. Factorial con Punteros\n2. Factorial sin Punteros\nOpcion elegida: ");
				scanf("%d",&op1);
				printf("%s eligio la opcion %d\n",argv[1],op);
				switch(op1){
					case 1:
						printf("Vamos alla...");
						break;
					case 2: printf("Vamos alla...");
						break;
				}
				break;
			case 2: 
				printf("1. Diagonales con Punteros\n2. Diagonales\n3. Sopa de letras\nOpcion elegida: ");
				scanf("%d",&op1);
				printf("%s eligio la opcion %d\n",argv[1],op);
				switch(op1){
					case 1:
						printf("Vamos alla...");
						break;
					case 2: printf("Vamos alla...");
						break;
				}
				break;
			case 3:
				printf("1. Fibonacci con Punteros\n2. Fubonacci sin Punteros\nOpcion elegida: ");
				scanf("%d",&op1);
				printf("%s eligio la opcion %d\n",argv[1],op);
				switch(op1){
					case 1:
						printf("Vamos alla...");
						break;
					case 2: printf("Vamos alla...");
						break;
				}
				break;
			case 4: printf("Bye bye\nFin de programa\n");
				break;
		}
	}
	return 0;
}
