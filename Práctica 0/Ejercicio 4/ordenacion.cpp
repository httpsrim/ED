#include <iostream>
#include <ctime>
#include <algorithm>
#include <cstdlib>
using namespace std;

void ordenar(int *v, int n) {
	bool cambio=true;
	for (int i=0; i<n-1 && cambio; i++) {
		cambio=false;
		for (int j=0; j<n-i-1; j++)
		if (v[j]>v[j+1]) {
			cambio=true;
			swap (v[j],v[j+1]);
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
		//generar vector ordenado
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
