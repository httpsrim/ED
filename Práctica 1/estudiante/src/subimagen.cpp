#include "image.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

/**
 * @brief Genera por copia una imagen PGM a partir de otra imagen
 * @pre El tamaño debe de ser menor o igual que la imagen original.
 * @param fich_orig Fichero de origen
 * @param fich_rdo Fichero al que se le envia la informaciÃ³n.
 * @param fila Fila de inicio
 * @param col Columna de inicio
 * @param filas_sub Nº de filas de la subimagen
 * @param colas_sub Nº de columnas de la subimagen
 */

int main(int argc, char *argv[]){
    Image image;
    Image subimagen; 
     
    char *fich_orig, *fich_rdo; 
    int fila, col; 
    int filas_sub, col_sub; 
    
    //Comprobar validez
    if(argc != 7){
        cerr << "Error: Numero incorrecto de argumentos.\n" ; 
        cerr << "Uso : crop <FicherImagenOriginal><FicheroImagenDestino><Filas><Columnas><Filas_sub><Columnas_sub>\n"; 
        exit(1); 
    }

    //Obtener argumentos
    fich_orig = argv[1];
    fich_rdo = argv[2];
    fila = atoi(argv[3]);
    col = atoi(argv[4]);
    filas_sub = atoi(argv[5]);
    col_sub = atoi(argv[6]); 

    // Mostramos argumentos
    cout << endl;
    cout << "Fichero origen: " << fich_orig << endl;
    cout << "Fichero resultado: " << fich_rdo << endl;
    cout << "filas: " << fila << "columnas: " << col << endl;
    cout << "filas_sub: " << filas_sub << " columas_sub: " << col_sub << endl;
    
    if(!image.Load(fich_orig)){
        cerr << "No se puede abrir la imagen";
        exit(1); 
    }

    // Mostrar los parametros de la Imagen
    cout << endl;
    cout << "Dimensiones de " << fich_orig << ":" << endl;
    cout << "   Imagen   = " << image.get_rows()  << " filas x " << image.get_cols() << " columnas " << endl;

    //Confirmar parametros
    if(filas_sub > image.get_rows() || col_sub > image.get_cols()){
        cerr << "Parametros incorrectos";
        exit(1); 
    }

    subimagen = image.Crop(fila, col, filas_sub, col_sub);  

    // Mostrar los parametros del subimagen
    cout << endl;
    cout << "Dimensiones del subimagen: " << endl;
    cout << "Subimagen = " << subimagen.get_rows()  << " filas x " << subimagen.get_cols() << " columnas " << endl;
    subimagen.Save(fich_rdo); 

return 0; 
}
