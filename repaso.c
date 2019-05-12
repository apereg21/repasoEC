#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TAM 7
#define NUMC 5
#define NUMF 5

void inicializaPunteroVect(int *vect,int tam);
void inicializaVect(int vect[TAM]);
void imprimeVectPuntero(int *vect,int tam);
void imprimeVect(int vect[TAM]);
void factorialPuntero(int *vect,int tam);
void factorialVect(int vect[TAM]);

void inicializarMartizPuntero(int *matriz,int numFi, int numCo);
void diagonalPrincipal(int *matriz,int numFi, int numCo);
void diagonalSecundaria(int *matriz,int numFi, int numCo);
void cruzetaMatriz(int *matriz,int numFi, int numCo);
void imprimirMatriz(int *matriz,int numFi, int numCo);

void inicializarMartizSinPuntero(int matriz[NUMF][NUMC]);
void diagonalPrincipalSinPuntero(int matriz[NUMF][NUMC]);
void diagonalSecundariaSinPuntero(int matriz[NUMF][NUMC]);
void cruzetaMatrizSinPuntero(int matriz[NUMF][NUMC]);
void imprimirMatrizSinPuntero(int matriz[NUMF][NUMC]);

void imprimirMatrizCharPuntero(char *matriz,int numFi, int numCo);
void inicializarMartizCharPuntero(char *matriz,int numFi, int numCo);
char seleccionLetraMartizCharPuntero(char *matriz, char nuevaPalabra[5], int numFi, int numCo, int x, int y, int z);
void imprimirPalabraNueva(char nuevaPalabra[5]);

int main(int argc, char *argv[]){
	int op,op1,opSN=0,contador=0,contFallos=0,acierto=0,*vector,tamV,vectorS[TAM],numF,numC,*matrizIni,matrizS[NUMF][NUMC],cx,cy;
	char *matrizChar,newPalabra[5];
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
		printf("%s eligio la opcion %d\n",argv[1],op);
		switch(op){
			case 1:
				printf("1. Factorial con Punteros\n2. Factorial sin Punteros\nOpcion elegida: ");
				scanf("%d",&op1);
				printf("%s eligio la opcion %d\n",argv[1],op);
				switch(op1){
					case 1:
						printf("Vamos alla...\nDime el tamaño del vector: ");
						scanf("%d",&tamV);
						printf("Inicializando Matriz\n");
						vector=(int*)malloc(tamV*sizeof(int));
						inicializaPunteroVect(vector,tamV);
						imprimeVectPuntero(vector,tamV);
						printf("\n");
						factorialPuntero(vector,tamV);
						imprimeVectPuntero(vector,tamV);
						printf("\nFin del Algoritmo\n");
						free(vector);
						break;
					case 2: printf("Vamos alla...\n");
						printf("Inicializando Matriz\n");
						inicializaVect(vectorS);
						imprimeVect(vectorS);
						printf("\n");
						factorialVect(vectorS);
						imprimeVect(vectorS);
						printf("\nFin del Algoritmo\n");
						break;
				}
				break;
			case 2: 
				printf("1. Diagonales con Punteros\n2. Diagonales sin Punteros\n3. Sopa de letras\nOpcion elegida: ");
				scanf("%d",&op1);
				printf("%s eligio la opcion %d\n",argv[1],op);
				switch(op1){
					case 1:
						printf("Vamos alla...\nDime el tamaño de las filas de la matriz: ");
						scanf("%d",&numF);
						printf("Dime el tamaño de las columnas de la matriz: ");
						scanf("%d",&numC);
						matrizIni=(int*)malloc(numF*numC*sizeof(int));
						inicializarMartizPuntero(matrizIni,numF,numC);
						diagonalPrincipal(matrizIni,numF,numC);
						diagonalSecundaria(matrizIni,numF,numC);
						cruzetaMatriz(matrizIni,numF,numC);
						imprimirMatriz(matrizIni,numF,numC);
						free(matrizIni);
						break;
					case 2: printf("Vamos alla...\n");
						inicializarMartizSinPuntero(matrizS);
						diagonalPrincipalSinPuntero(matrizS);
						diagonalSecundariaSinPuntero(matrizS);
						cruzetaMatrizSinPuntero(matrizS);
						imprimirMatrizSinPuntero(matrizS);
						break;
					case 3: printf("Vamos alla...\nDime el tamaño de las filas de la matriz: ");
						scanf("%d",&numF);
						printf("Dime el tamaño de las columnas de la matriz: ");
						scanf("%d",&numC);
						matrizChar=(char*)malloc(numF*numC*sizeof(char));
						do{
							srand(time(NULL));
							inicializarMartizCharPuntero(matrizChar,numF,numC);
							imprimirMatrizCharPuntero(matrizChar,numF,numC);
							printf("\n¿Quiere un nuevo tablero?\n1.Si\n2.No\n");
							scanf("%d",&opSN);
							if(opSN==1){
								contador=1;
							}
							else{
								contador=0;
							}
						}while(contador!=0);
						int i;						
						for(i=0;i<5;i++){
							printf("\n¿Coordenada fila?:");
							scanf("%d",&cx);
							printf("\n¿Coordenada columna?: ");
							scanf("%d",&cy);
							seleccionLetraMartizCharPuntero(matrizChar, newPalabra, numF, numC, cx, cy, i);
						}
						printf("\n");
						imprimirPalabraNueva(newPalabra);
						printf("\n");
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

void inicializaPunteroVect(int *vect,int tam){
	int i;
	for(i=0;i<tam;i++){
		*(vect+i)=0;
	}
}

void inicializaVect(int vect[TAM]){
	int i;
	for(i=0;i<TAM;i++){
		vect[i]=0;
	}
}

void imprimeVect(int vect[TAM]){
	int i;
	for(i=0;i<TAM;i++){
		printf("%d\n",vect[i]);
	}
}

void imprimeVectPuntero(int *vect,int tam){
	int i;
	for(i=0;i<tam;i++){
		printf("%d\n",*(vect+i));
	}
}

void factorialPuntero(int *vect,int tam){
	int i,res=1;
	for(i=tam;i>0;i--){
		if(i==1){
			res=res*1;
		}
		else{
			res=res*i;
			
		}
		*(vect+(tam-i))=res;
	}
}

void factorialVect(int vect[TAM]){
	int i,res=1;
	for(i=TAM;i>0;i--){
		if(i==1){
			res=res*1;
		}
		else{
			res=res*i;
			
		}
		vect[TAM-i]=res;
	}
}

void diagonalPrincipal(int *matriz,int numFi, int numCo){
	int i,j;
	for(i=0;i<numFi;i++){
		for(j=0;j<numCo;j++){
			if(i==j){
				*(matriz+i*numCo+j)=0;
			}
		}
	}
}

void diagonalSecundaria(int *matriz,int numFi, int numCo){
	int i,j;
	for(j=numCo-1;j>=0;j--){
		for(i=numFi-1;i>=0;i--){
			if((numCo-1-j==i)){
				*(matriz+i*numCo+j)=1;	
			}
		}
	}
}

void cruzetaMatriz(int *matriz,int numFi, int numCo){
	int i,j,mitadF,mitadC;
	if(numFi%2!=0){
		mitadF=1+(numFi/2);
	}
	else{
		mitadF=(numFi/2);
	}
	if(numCo%2!=0){
		mitadC=1+(numCo/2);
	}
	else{
		mitadC=(numCo/2);
	}
	for(i=0;i<numFi;i++){
		for(j=0;j<numCo;j++){
			if(i==mitadF-1){
				*(matriz+i*numCo+j)=8;
			}
			if(j==mitadC-1){
				*(matriz+i*numCo+j)=8;
			}
		}
	}
}

void imprimirMatriz(int *matriz,int numFi, int numCo){
	int i,j;
	for(i=0;i<numFi;i++){
		for(j=0;j<numCo;j++){
				printf("%d\t",*(matriz+i*numCo+j));
		}
	printf("\n");
	}
}

void inicializarMartizPuntero(int *matriz,int numFi, int numCo){
	int i,j;
	for(i=0;i<numFi;i++){
		for(j=0;j<numCo;j++){
			*(matriz+i*numCo+j)=7;
		}
	}
}

//////////////////////////////////////////////////////////////////////

void diagonalPrincipalSinPuntero(int matriz[NUMF][NUMC]){
	int i,j;
	for(i=0;i<NUMF;i++){
		for(j=0;j<NUMC;j++){
			if(i==j){
				matriz[i][j]=0;
			}
		}
	}
}

void diagonalSecundariaSinPuntero(int matriz[NUMF][NUMC]){
	int i,j;
	for(j=NUMC-1;j>=0;j--){
		for(i=NUMF-1;i>=0;i--){
			if((NUMC-1-j==i)){
				matriz[i][j]=1;	
			}
		}
	}
}

void cruzetaMatrizSinPuntero(int matriz[NUMF][NUMC]){
	int i,j,mitadF,mitadC;
	if(NUMF%2!=0){
		mitadF=1+(NUMF/2);
	}
	else{
		mitadF=(NUMF/2);
	}
	if(NUMC%2!=0){
		mitadC=1+(NUMC/2);
	}
	else{
		mitadC=(NUMC/2);
	}
	for(i=0;i<NUMF;i++){
		for(j=0;j<NUMC;j++){
			if(i==mitadF-1){
				matriz[i][j]=8;
			}
			if(j==mitadC-1){
				matriz[i][j]=8;
			}
		}
	}
}

void imprimirMatrizSinPuntero(int matriz[NUMF][NUMC]){
	int i,j;
	for(i=0;i<NUMF;i++){
		for(j=0;j<NUMC;j++){
				printf("%d\t",matriz[i][j]);
		}
	printf("\n");
	}
}

void inicializarMartizSinPuntero(int matriz[NUMF][NUMC]){
	int i,j;
	for(i=0;i<NUMF;i++){
		for(j=0;j<NUMC;j++){
			matriz[i][j]=7;
		}
	}
}

/////////////////////////////////////////////////////////////////

void imprimirMatrizCharPuntero(char *matriz,int numFi, int numCo){
	int i,j;
	for(i=0;i<numFi;i++){
		for(j=0;j<numCo;j++){
				printf("%c\t",*(matriz+i*numCo+j));
		}
	printf("\n");
	}
}

void inicializarMartizCharPuntero(char *matriz,int numFi, int numCo){
	int i,j;
	for(i=0;i<numFi;i++){
		for(j=0;j<numCo;j++){
			*(matriz+i*numCo+j)=rand()%(122-97+1)+97;
		}
	}
}

char seleccionLetraMartizCharPuntero(char *matriz, char nuevaPalabra[5], int numFi, int numCo, int x, int y, int z){
	return nuevaPalabra[z]=*(matriz+x*numCo+y);
}

void imprimirPalabraNueva(char nuevaPalabra[5]){
	int i;
	for(i=0;i<5;i++){
		printf("%c",nuevaPalabra[i]);
	}
}
