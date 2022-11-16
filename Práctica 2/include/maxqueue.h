/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/**
 * @file maxqueue.h
 * @brief  Archivo de especificación del TDA MaxQueue
 * @author Haowei e Inés
 */

#ifndef MAXQUEUE_H
#define MAXQUEUE_H

 
#include <iostream> 
#include <stack>
 
using namespace std; 
 
/**
 * @brief struct del tipo de dato element para almacenar dos valores distintos
 * @pre Tiene dos atributos, value y maximum
 * 
 * @pre Value almacena un valor
 * @pre Maximum guarda el valr maximo de todos los valores introducidos
 */
struct element{
    int value; 
    int maximum; 
};
 
/**
 * @brief Ostream para sacar por pantalla los valores 
 * @param os flujo de salida 
 * @param numero Instacia de tipo element que va a ser imprimdida por pantalla
 * @return Devuelve el flujo os
 */
ostream & operator << (ostream & os, const element & numero);
 
/**
 * @brief Instancia del tipo dato MaxQueue que nos permite almacenar una serie de valores 
 * @pre Sigue una estructura basada en cola con política FIFO
 * @pre Internamente sigue una estructura basada en pila, con política LIFO
 * @pre Se debe añadir #include<maxqueue.h> para su uso 
 */
class MaxQueue{
    private:
        stack <element> pila; 
        
    public:
        /**
         * @brief Constructor por defecto sin parametros 
         */
        MaxQueue(); 
         
        /**
         * @brief Devuelve el primer elemento guardado en cola
         * @return Primer elemento de la cola
         */
        element front(); 
        
        /**
         * @brief Elimina el primer elemento de la cola
         */
        void pop(); 
        
        /**
         * @brief Almacena en la ultima posicion una instancia de tipo element
         * @param numero Valor a almacenar en la cola
         */
        void push(int numero); 
         
        /**
         * @brief Devuelve el tamaño de la cola 
         * @return Cantidad de elementos existentes en la cola 
         */
        int size(); 
         
        /**
         * @brief Indica si la cola esta vacia
         * @return True si esta vacia
         * @return False si la cola posee elementos 
         */
        bool empty(); 
        
};

#endif /* MAXQUEUE_H */

