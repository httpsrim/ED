#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void ordenar(int *v, int n) {
	for (int i=0; i<n-1; i++){
		for (int j=0; j<n-i-1; j++){
			if (v[j]>v[j+1]) {
				int aux = v[j];
				v[j] = v[j+1];
				v[j+1]=aux;
			}
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
	if(argc != 2)
		sintaxis();
	//lectura de los parámetros
	int tam = atoi(argv[1]);
	//Genera el vector aleatorio y reservar memoria:
	int * v=new int[tam];
	for(int i = 0; i < tam; i++){
		//generar mejor caso
		v[i]=i;
	}
	//Anotamos tiempo de inicio	
	clock_t inicio;
	inicio = clock();
	
	ordenar(v,tam);
	
	//Anotamos el tiempo final
	clock_t fin;
	fin = clock(); 
	//Mostramos resultados.
	cout << tam << "\n" << (fin-inicio)/(double)CLOCKS_PER_SEC << endl;
	delete [] v;
}
