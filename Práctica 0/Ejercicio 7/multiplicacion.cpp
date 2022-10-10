#include <iostream>
#include <cstdlib>  // Para generación de números pseudoaleatorios
#include <ctime>
using namespace std;

void multiplicar(int **m, int **n,int t) {
	for(int i = 0; i < t; i++){
			for(int j = 0; j < t; j++){	
				m[i][j]=m[i][j]*n[i][j];
			}
		}
}

void sintaxis()
{
	cerr << "Sintaxis:" << endl;
	cerr << "  TAM: Tamaño del vector (>0)" << endl;
	cerr << "  VMAX: Valor máximo (>0)" << endl;
	cerr << "Se genera un vector de tamaño TAM con elementos aleatorios en [0,VMAX[" << endl;
	exit(EXIT_FAILURE);
}


int main(int argc, char * argv[]){
	if(argc != 3)
		sintaxis();
	int tam=atoi(argv[1]);     // Tamaño del vector
	int vmax=atoi(argv[2]);    // Valor máximo

 	// Genera el vector aleatorio y reservar memoria:
	int **m=new int*[tam];
	int **n=new int*[tam];
	for(int i = 0; i < tam; i++){
		m[i]=new int[tam];
		n[i]=new int[tam];
	}
	//Inicialización generador numeros pseudoaleatorios
	srand(time(0));
	for(int i = 0; i < tam; i++){
		for(int j = 0; j < tam; j++){
			//generar numeros aleatorios entre [0,vmax[
			m[i][j]=rand()%vmax;
			n[i][j]=rand()%vmax;
		}
	}
	//Anotamos tiempo de inicio	
	clock_t inicio;
	inicio = clock();
	multiplicar(m,n,tam);	
	//Anotamos el tiempo final
	clock_t fin;
	fin = clock(); 
	//Mostramos resultados.
	cout << tam << "\n" << (fin-inicio)/(double)CLOCKS_PER_SEC << endl;

	for(int i = 0; i < tam; i++){
		delete[] m[i];
		delete[] n[i];
	}
	delete[] m;
	delete[] n;
}
