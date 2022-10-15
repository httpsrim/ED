/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Zoom.cpp
 * Author: haowei
 * 
 * Created on 8 de octubre de 2022, 11:21
 */

#include <image.h>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std; 

/**
 * @brief Genera una imagen ampliada por 2 a partir de otra imagen
 * @param origen Fichero de origen
 * @param destino FIchero en donde se guarda la imagen ampliada
 * @param fil Fila de inicio
 * @param col Columna de inicio
 * @param tam tamanyio de la imagen
 * @return Imagen ampliada
 */
int main(int argc, char *argv[]){
    
    char *origen, *destino; // nombres de los ficheros
    Image image;
    int fil, col, tam; 
    
    
    //Comprobar validez de la llamada
    if(argc != 6){
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: zoom <FichImagenOriginal> <FichImagenDestino><fila><columna><tam>\n";
        exit (1);
    }
    
    // Obtener argumentos
    origen  = argv[1];
    destino = argv[2];
    fil = atoi(argv[3]);
    col = atoi(argv[4]);
    tam = atoi(argv[5]);
    
      // Mostramos argumentos
    cout << endl;
    cout << "Fichero origen: " << origen << endl;
    cout << "Fichero resultado: " << destino << endl;
    cout << "filas: " << fil; 
    cout << "columnas: " << col; 
    cout << "tamanio: " << tam << endl; 
    
    // Leer la imagen del fichero de entrada
    if (!image.Load(origen)){
        cerr << "Error: No pudo leerse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }

    // Mostrar los parametros de la Imagen
    cout << endl;
    cout << "Dimensiones de " << origen << ":" << endl;
    cout << "   Imagen   = " << image.get_rows()  << " filas x " << image.get_cols() << " columnas " << endl;
    
    
    //Recortar para realizar el zoom
    image = image.Crop(fil, col, tam, tam);

    Image zoom(2*tam-1, 2*tam-1);
    
    zoom = image.Zoom2X(); 

    // Mostrar los parametros del zoom
    cout << endl;
    cout << "Dimensiones de zoom:" << endl;
    cout << "zoom   = " << zoom.get_rows()  << " filas x " << zoom.get_cols() << " columnas " << endl;
    
    //GUardar la imagen final en el fichero
    if (zoom.Save(destino))
        cout  << "La imagen se guardo en " << destino << endl;
    else{
        cerr << "Error: No pudo guardarse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
    return 1;
    }

  return 0;
    
    
}


