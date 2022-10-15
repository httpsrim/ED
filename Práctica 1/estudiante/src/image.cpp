/**
 * @file image.cpp
 * @brief Fichero con definiciones para los métodos primitivos de la clase Image
 *
 */

#include <cstring>
#include <cassert>
#include <iostream>
#include <cmath>
#include <image.h>
#include <imageIO.h>

using namespace std;

/**
  @brief T.D.A. Imagen

  Una instancia del tipo de dato abstracto Imagen nos permite almacenar imágenes de intensidades.

  El TDA Imagen proporciona además distintas herramientas para la manipulación de dichas imágenes.

  Para poder usar el TDA Imagen se debe incluir el fichero

  \#include <Imagen.h>

  @author Inés Jiménez Díaz
  @author Haowei Hu
  @date Octubre 2022

**/
/********************************
      FUNCIONES PRIVADAS
********************************/
/**
      @brief Reserva o copia en memoria una imagen.
      @param nrows Número de filas que tendrá la imagen.
      @param ncols Número de colwnnas que tendrá la imagen.
      @param buffer Puntero a un buffer de datos con los que rellenar los píxeles de la imagen. Por defecto, 0.
      @pre nrows >= O y ncols >= O
      @post Reserva memoria para almacenar la imagen y la prepara para usarse.
    **/
void Image::Allocate(int nrows, int ncols, byte * buffer){
    rows = nrows;
    cols = ncols;

    img = new byte * [rows];

    if (buffer != 0)
        img[0] = buffer;
    else
        img[0] = new byte [rows * cols];

    for (int i=1; i < rows; i++)
        img[i] = img[i-1] + cols;
}

 /**
      @brief Initialize una imagen.
      @param nrows Número de filas que tendrá la imagen. Por defecto, 0
      @param ncols Número de colwnnas que tendrá la imagen. Por defecto, 0
      @param buffer Puntero a un buffer de datos con los que rellenar los píxeles de la imagen. Por defecto, 0.
      @pre filas >= O y columnas >= O
      @post Reserva memoria para almacenar la imagen y la prepara para usarse.
    **/
void Image::Initialize (int nrows, int ncols, byte * buffer){
    if ((nrows == 0) || (ncols == 0)){
        rows = cols = 0;
        img = 0;
    }
    else Allocate(nrows, ncols, buffer);
}

  /**
      @brief Copy una imagen .
      @param orig Referencia a la imagen original que vamos a copiar
      @pre Asume que no hay memoria reservada o se ha llamado antes a Destroy()
      @pre Asume this != &orig
    **/
void Image::Copy(const Image & orig){
    Initialize(orig.rows,orig.cols);
    for (int k=0; k<rows*cols;k++)
        set_pixel(k,orig.get_pixel(k));
}

// Función auxiliar para destruir objetos Imagen
bool Image::Empty() const{
    return (rows == 0) || (cols == 0);
}

    /**
      * @brief Destroy una imagen
      *
      * Libera la memoria reservada en la que se almacenaba la imagen que llama a la función.
      * Si la imagen estaba vacía no hace nada .
      */
void Image::Destroy(){
    if (!Empty()){
        delete [] img[0];
        delete [] img;
    }
}
/**
      @brief Lee una imagen PGM desde un archivo.
      @param file_path Ruta del archivo a leer
      @return LoadResult
    **/
LoadResult Image::LoadFromPGM(const char * file_path){
    if (ReadImageKind(file_path) != IMG_PGM)
        return LoadResult::NOT_PGM;

    byte * buffer = ReadPGMImage(file_path, rows, cols);
    if (!buffer)
        return LoadResult::READING_ERROR;

    Initialize(rows, cols, buffer);
    return LoadResult::SUCCESS;
}

/********************************
       FUNCIONES PÚBLICAS
********************************/

 /**
      * @brief Constructor por defecto .
      * @post Genera una instancia de la clase Imagen con O filas y O colunmas.
      * @return Imagen, el objeto imagen creado.
      */

Image::Image(){
    Initialize();
}

/**
      * @brief Constructor con parámetros.
      * @param nrows Número de filas de la imagen.
      * @param ncols Número de columnas de la imagen.
      * @param value defecto Valor con el que inicializar los píxeles de la imagen . Por defecto O.
      * @pre n fils > O Y n_cols > O
      * @post La imagen creada es de n_fils y n_cols columnas. Estará inicializada al valor por defecto.
      * @return Imagen, el objeto imagen creado.
      */
Image::Image (int nrows, int ncols, byte value){
    Initialize(nrows, ncols);
    for (int k=0; k<rows*cols; k++) set_pixel(k,value);
}
/**
      * @brief Carga en memoria una imagen de disco .
      * @param file_path Ruta donde se encuentra el archivo desde el que cargar la imagen.
      * @pre @p file_path debe ser una ruta válida que contenga un fichero . pgm
      * @return Devuelve @b true si la imagen se carga con éxito y @b false en caso contrario.
      * @post La imagen previamente almacenada en el objeto que llama a la función se destruye.
      */
bool Image::Load (const char * file_path) {
    Destroy();
    return LoadFromPGM(file_path) == LoadResult::SUCCESS;
}

/**
      * @brief Constructor de copias.
      * @param orig Referencia a la imagen original que se quiere copiar.
      * @return Imagen, el objeto imagen creado.
      */

Image::Image (const Image & orig){
    assert (this != &orig);
    Copy(orig);
}
    /**
      * @brief Oper ador de tipo destructor.
      * @return void
      * @post El objeto Imagen destruido no puede usarse salvo que se haga sobre él una operacion Imagen().
      */
Image::~Image(){
    Destroy();
}

 /**
      * @brief Operador de asignación .
      * @param orig Referencia a la imagen original que desea copiarse.
      * @return Una referencia al objeto imagen modificado.
      * @post Destroy cualquier información que contuviera previamente la imagen que llama al operador de asignación.
      */

Image & Image::operator= (const Image & orig){
    if (this != &orig){
        Destroy();
        Copy(orig);
    }
    return *this;
}
 /**
      * @brief Filas de la imagen .
      * @return El número de filas de la i magen.
      * @post la imagen no se modifica.
      */
int Image::get_rows() const {
    return rows;
}
 /**
      * @brief Columnas de la imagen.
      * @return El número de columnas de la imagen.
      * @post la imagen no se modifica.
      */
int Image::get_cols() const {
    return cols;
}
/**
      * @brief Devuelve el número de píxeles de la imagen.
      * @return número de píxeles de la imagen.
      * @post la imagen no se modifica.
      */
int Image::size() const{
    return get_rows()*get_cols();
}

/**
  * @brief Asigna el valor valor al píxel (@p i, @p j) de la imagen.
  * @param i Fila de la imagen en la que se encuentra el píxel a escribir .
  * @param j Columna de la imagen en la que se encuentra el píxel a escribir.
  * @param value Valor que se escribirá en el píxel (@p i, @p j) .
  * @pre O <= @p i < get_rows()
  * @pre O <= @p j < get_cols()
  * @pre O <= @p value <= 255
  * @post El píxel (@p i, @p j) de la imagen se modificará y contendrá valor @p value.
  * Los demás píxeles permanecerán iguales.
  */
void Image::set_pixel (int i, int j, byte value) {
    img[i][j] = value;
}
 /**
      * @brief Consulta el valor del píxel (fil, col) de la imagen.
      * @param i Fila de la imagen en la que se encuentra el píxel a consultar.
      * @param j Columna de la imagen en la que se encuentra el píxel a consultar.
      * @pre O <= fil < I.Num_ Filas() II O <= col < I.Num Columnas()
      * @return el valor del píxel contenido en (fil,col)
      * @post La imagen no se modifica.
      */
byte Image::get_pixel (int i, int j) const {
    return img[i][j];
}


 /**
      * @brief Asigna el valor valor al píxel k de la imagen desenrollada.
      * @param k Índice del píxel a escribir .
      * @param value Valor que se escribirá en el píxel k.
      * @pre 0 <= k < filas*columnas && O <= valor <= 255
      * @post El píxel k se modificará con el valor de value.
      */
void Image::set_pixel (int k, byte value) {
int i, j;
    double pos = k;

    i = floor((pos/(double)get_cols()));
    j = (k % (get_cols()));

    set_pixel(i,j,value);
}
    /**
      * @brief Consulta el valor del píxel k de la imagen desenrrollada.
      * @param k Índice del píxel
      * @pre 0 <= k < filas*columnas
      * @return el valor del píxel contenido en (k/filas,k%filas)
      * @post La imagen no se modifica.
      */
byte Image::get_pixel (int k) const {
   int i, j;
    double pos = k;

    i = floor((pos/(double)get_cols()));
    j = (k % (get_cols()));

    return get_pixel(i,j);
}

/**
      * @brief Almacena imágenes en disco.
      * @param file_path Ruta donde se almacenará la imagen.
      * @pre file path debe ser una ruta válida donde almacenar el fichero de salida.
      * @return Devuelve true si la imagen se almacenó con éxito y false en caso contrario.
      * @post La imagen no se modifica.
      */
bool Image::Save (const char * file_path) const {
    byte * p = new byte[size()];
    for (int i = 0; i < size(); i++) {
            p[i] = get_pixel(i);
    }

    return WritePGMImage(file_path, p, rows, cols);
}
/**
 * @brief Genera una subimagen
 * 
 * @param nrow fila inicial para recortar
 * @param ncol columna inicial para recortar
 * @param height número de filas
 * @param width número de columnas
 * @return Imagen con recorte
 * @post El objeto que llama a la función no se modifica
 */
Image Image::Crop(int nrow, int ncol, int height, int width) const{
    Image crop(height, width); 
    for(int i = 0; i < height; i++){
	for(int j = 0; j < width; j++){
            byte valor = this->get_pixel(nrow + i , ncol + j); 
            crop.set_pixel(i,j,valor);
	}
    }

    return crop; 
}

/**
 * @brief Hace el zoom a la imagen
 * 
 * @return Imagen con zoom
 */
Image Image::Zoom2X() const{
    
    int filas = this->get_rows()*2-1;
    int columnas = this->get_cols()*2-1; 
    Image zoom(filas, columnas); 
    
    int x = 0; 
    int y = 0; 
    
    for(int i = 0; i < zoom.get_rows(); i++){ 
        for(int j = 0; j < zoom.get_cols(); j++){ 
            if(i%2 == 0 && j%2 == 0){
                byte aux = this->get_pixel(x,y); 
                zoom.set_pixel(i,j,aux);
            }else if(i%2 == 0 && j%2 != 0){
                double aux = (this->get_pixel(x,y)+this->get_pixel(x,y+1));
                aux = round(aux/2);
                zoom.set_pixel(i,j,aux); 
                y++;  
            }else if(i%2 != 0 && j%2 == 0){
                double aux = (this->get_pixel(x,y)+this->get_pixel(x+1,y));
                aux = round(aux/2); 
                zoom.set_pixel(i,j,aux); 
                y++;  
            }else if(i%2 != 0 && j%2 != 0){
                double aux = (this->get_pixel(x,y-1)+this->get_pixel(x+1,y)+this->get_pixel(x,y)+this->get_pixel(x+1,y-1));
                aux = round(aux/4); 
                zoom.set_pixel(i,j,aux); 
            }
                             
        }
        y = 0; 
        if ( i%2 != 0 ){
            x++;
        }
    } 

    return zoom; 
}

/**
 * @brief Crea una imagen cambiandole el índice de filas 
 * @pre rows < 9973
 * @post El objeto que llama al método contiene ahora una nueva imagen igual que la anterior pero con las filas ordenadas según el siguiente algoritmo: r'=(p*p) mod rows, donde r' es el nuevo índice para la fila r,p es un coprimo de rows y rows es el número de filas de la imagen.
 */
void Image::ShuffleRows() {
    const int p = 9973;
    Image temp(rows,cols);
    int newr;
    for (int r=0; r<rows; r++){
        newr = r*p % rows;
        for (int c=0; c<cols;c++)
            temp.set_pixel(r,c,get_pixel(newr,c));
    }
    Copy(temp);
}

/**
 * @brief Genera un icono como reducción de una imagen
 * 
 * @param factor Factor de reducción de la imagen original con respecto al icono
 * @pre factor>0
 * @return La imagen iconizada
 * @post La imagen no se modifica
 * @post La imagen resultante tendrá tamaño int(filas/factor) X int(columnas/factor). Descartando los decimales de la división 
 */
Image Image::Subsample(int factor) const{
    int filas = (this->get_rows() / factor); 
    int columnas = (this->get_cols() / factor); 
    Image icono(filas, columnas); 
    
    for(int i = 0; i < icono.get_rows(); i++){
        for(int j = 0; j < icono.get_cols(); j++){
            byte aux = ObtenerPixelIcono(i,j,factor);
            icono.set_pixel(i,j,aux);     
        }
    }
    
    return icono; 
}

/**
     * @brief Metodo que obtiene el pixel de la imagen original sobre el factor de reduccion
     * @param fil Numero de fila en la que se encuentra
     * @param col NUmero de columna en la que se encuenta
     * @param factor Factor de reduccion
     * @return Pixel con el factor incluido
     */
byte Image::ObtenerPixelIcono(int fil, int col, int factor)const{
    long double aux = 0;  
    int area = factor*factor; 
    byte aux2;

    for(int i = fil * factor; i < fil * factor + factor; i++){
        for(int j = col * factor; j < col * factor + factor ; j++){
            aux += this->get_pixel(i,j); 
        }
    }
    aux = round(aux/area);  
    
    return aux; 
}

/**
 * @brief Ajusta el contraste de la imagen segun los parametros 
 * 
 * @param in1 Umbral inferior de la imagen de entrada
 * @param in2 Umbral superior de la imagen de entrada
 * @param out1 Umbral inferior de la imagen de salida
 * @param out2 Umbral superior de la imagen de salida
 * @pre 0<=(in1,in2,out1,out2)<=255
 * @pre in1 < in2
 * @pre out1 < out2
 * @post El objeto que llama a la función es modificado
 */
void Image::AdjustContrast(byte in1, byte in2, byte out1, byte out2){
    double v; //nuValue;
    auto Vin1 = double(in1) , Vin2 = double(in2), Vout1 = double(out1), Vout2 = double(out2);
    double c1, c2, c3;
    c1 = (Vout1/Vin1);
    c2 = (Vout2-Vout1)/(Vin2- Vin1);
    c3 = (255 - Vout2)/(255 - Vin2);

    for (int i = 0; i <size(); i++){
        v = (double)get_pixel(i);
        if (v <= in1){          
            this->set_pixel(i,(byte)round(c1*v));
        }
        else if (v <= in2){
            this->set_pixel(i,(byte)round(Vout1+(c2*(v-Vin1))));
        }
        else if(v <= 255){
            this->set_pixel(i,(byte)round(Vout2+(c3*(v-Vin2))));
        }
	else if(v == 0){
		this->set_pixel(i,(byte)0);
        }
	else{
		this->set_pixel(i,(byte)255);
        }
    }
}


