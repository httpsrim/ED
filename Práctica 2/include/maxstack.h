/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/**
 * @file maxstack.h
 * @brief  Archivo de especificación del TDA MaxStack
 * @author Haowei e Ines Jimenez 
 */


#ifndef MAXSTACK_H
#define MAXSTACK_H

#include <iostream>
#include <queue>
#include <stack> 

using namespace std; 

/**
 * @brief struct del tipo de dato element para almacenar dos valores distintos
 * @pre Tiene dos atributos, value y maximum
 * 
 * @pre Value almacena un valor
 * @pre Maximum guarda el valr maximo de todos los valores introducidos
 */
struct element {
    int value; // Current value to store
    int maximum; // Current max value in the structure
};

/**
 * @brief Ostream para sacar por pantalla los valores 
 * @param os flujo de salida 
 * @param numero Instacia de tipo element que va a ser imprimdida por pantalla
 * @return Devuelve el flujo os
 */
ostream & operator << (ostream & os, const element & numero);


/**
 * @brief Instancia del tipo dato MaxStack que nos permite almacenar una serie de valores 
 * @pre Sigue una estructura basada en pila con política LIFO
 * @pre Internamente sigue una estructura basada en cola, con política FIFO
 * @pre Se debe añadir #include<maxqueue.h> para su uso 
 */
class  MaxStack{
	private:
	
	    queue<element> cola;
	    
	public:
	
	/**
	 * @brief Constructor sin parametros
	 */
	MaxStack(); 
	
	/**
	 * @brief Devuelve el ultimo elemento almacenado en pila
	 * @return Instancia de tipo element 
	 */
	element top(); 
	

	void push(int num); 
	
	/**
	 * @brief Devuelve el tamanño
	 * @return tamaño de la pila
	 */
	int size(); 

	/**
	 * @brief Nos indica si la pila esta vacio
	 * @return true si vacia, false en otro caso
	 */
	bool empty(); //return valor tamaño
        
        /**
         * @brief Elimina el ultimo elemento de lla pila 
         */
        void pop();  // eliminar uno 
};

#endif /* MAXSTACK_H */

