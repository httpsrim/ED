#include "image.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
/**
 * @brief Crea una imagen cambiandole el índice de filas 
 * @pre rows < 9973
 * @post El objeto que llama al método contiene ahora una nueva imagen igual que la anterior pero con las filas ordenadas según el siguiente algoritmo: r'=(p*p) mod rows, donde r' es el nuevo índice para la fila r,p es un coprimo de rows y rows es el número de filas de la imagen.
 *
 * @param fich_origen fichero de origen
 * @param fich_rdo fichero de destino
 * 
 */
int main(int argc, char *argv[]){
    Image image;
   
    char *fich_orig, *fich_rdo; 
    
    //Comprobar validez
    if(argc != 3){
        cerr << "Error: Numero incorrecto de argumentos.\n" ; 
        cerr << "Uso : crop <FicherImagenOriginal><FicheroImagenDestino><Filas><Columnas><Filas_sub><Columnas_sub>\n"; 
        exit(1); 
    }

    //Obtener argumentos
    fich_orig = argv[1];
    fich_rdo = argv[2];

    
    //leer imagen de fichero de entrada
    if(!image.Load(fich_orig)){
        cerr << "No se puede abrir el archivo";
        exit(1);
    }

    image.ShuffleRows(); 
    
    //GUardar la imagen final en el fichero
    if (image.Save(fich_rdo))
        cout  << "La imagen se guardo en " << fich_rdo << endl;
    else{
        cerr << "Error: No pudo guardarse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
    return 1;
    }


return 0; 
}
