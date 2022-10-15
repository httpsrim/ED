#include <iostream>
#include <cstring>
#include <cstdlib>

#include <image.h>

using namespace std;
/**
 * @brief 
 * 
 * @param origen fichero de origen
 * @param destino fichero de destino
 * @param e1 Umbral inferior de la imagen de entrada
 * @param e2 Umbral superior de la imagen de entrada
 * @param s1 Umbral inferior de la imagen de salida
 * @param s2 Umbral superior de la imagen de salida
 * 
 */
int main (int argc, char *argv[]){

    char *origen, *destino; // nombres de los ficheros
    Image image;
    int e1, e2, s1, s2;

    // Comprobar validez de la llamada
    if (argc != 7){
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: negativo <FichImagenOriginal> <FichImagenDestino>\n";
        exit (1);
    }

    // Obtener argumentos
    origen  = argv[1];
    destino = argv[2];
    e1 = atoi (argv[3]);
    e2 = atoi (argv[4]);
    s1 = atoi (argv[5]);
    s2 = atoi (argv[6]);

    if (e1 <= 0 || e2 <= 0 || s1 <= 0 || s2 <= 0){
        cerr << "Error: Uno de los umbrales es mas pequeño que el cero." <<endl;
        cerr << "Introduzca un lado mas pequeño que el menor de los lados de la subimagen." << endl;
        return 1;
    }
    if (e1 >= 255 || e2 >= 255 || s1 >= 255 || s2 >= 255){
        cerr << "Error: Uno de los umbrales supera el valor maximo de tono." <<endl;
        cerr << "Introduzca un lado mas pequeño que el menor de los lados de la subimagen." << endl;
        return 1;
    }
    if (e1 >= e2){
        cerr << "Error: El umbral inferior de entrada es mas grande que el superior" <<endl;
        cerr << "Introduzca un lado mas pequeño que el menor de los lados de la subimagen." << endl;
        return 1;
    }
    if (s1 >= s2){
        cerr << "Error: El umbral inferior de salida es mas grande que el superior." <<endl;
        cerr << "Introduzca un lado mas pequeño que el menor de los lados de la subimagen." << endl;
        return 1;
    }

    // Mostramos argumentos
    cout << endl;
    cout << "Fichero origen: " << origen << endl;
    cout << "Fichero resultado: " << destino << endl;

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

    // Calcular el constraste

    image.AdjustContrast((byte)e1,(byte)e2,(byte)s1,(byte)s2);

    // Guardar la imagen resultado en el fichero
    if (image.Save(destino))
        cout  << "La imagen se guardo en " << destino << endl;
    else{
        cerr << "Error: No pudo guardarse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }

    return 0;
}