/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Zoom.cpp
 * Author: mp
 * 
 * Created on 8 de octubre de 2022, 11:21
 */

#include "image.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std; 

/**
 * @brief Genera un icono a partir de la imagen original
 * @param origen Fichero de origen
 * @param destino FIchero en donde se guarda la imagen ampliada
 * @param factor Factor a reducir de la imagen
 * @pre factor > 0
 * @return Icono de la imagen
 */
int main(int argc, char *argv[]){
    
    char *origen, *destino; // nombres de los ficheros
    int factor; 
    Image image;
    Image icono; 
    
    
    //Comprobar validez de la llamada
    if(argc != 4){
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: icono <FichImagenOriginal> <FichImagenDestino><factor>\n";
        exit (1);
    }
    
    // Obtener argumentos
    origen  = argv[1];
    destino = argv[2];
    factor = atoi(argv[3]);
    
      // Mostramos argumentos
    cout << endl;
    cout << "Fichero origen: " << origen << endl;
    cout << "Fichero resultado: " << destino << endl;
    cout << "factor: " << factor << endl; 
    
    // Leer la imagen del fichero de entrada
    if (!image.Load(origen)){
        cerr << "Error: No pudo leerse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }
    
    // Mostrar los parametros de la Imagen
    cout << endl;
    cout << "Dimensiones de " << origen << ":" << endl;
    cout << "Imagen   = " << image.get_rows()  << " filas x " << image.get_cols() << " columnas " << endl;

    //Recortar para realizar el icono
    icono = image.Subsample(factor); 

    // Mostrar los parametros del icono
    cout << endl;
    cout << "Dimensiones del icono: " << endl; 
    cout << "Icono = " << icono.get_rows()  << " filas x " << icono.get_cols() << " columnas " << endl;
    
    //GUardar la imagen final en el fichero
    if (icono.Save(destino))
        cout  << "La imagen se guardo en " << destino << endl;
    else{
        cerr << "Error: No pudo guardarse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
    return 1;
    }

  return 0;
    
    
}

