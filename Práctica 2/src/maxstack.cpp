/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/**
 * @file maxqueue.cpp
 * @brief Instancia del tipo dato MaxStack que nos permite almacenar una serie de valores 
 * @pre Sigue una estructura basada en pila con política LIFO
 * @pre Internamente sigue una estructura basada en cola, con política FIFO
 * @pre Se debe añadir #include<maxqueue.h> para su uso 
 * @authors Haowei Hu e Inés Jiménez
 */
 #include "maxstack.h"
 #include <stack>
 #include <queue> 
 #include <iostream>
 
       
 ostream & operator<<(ostream & os, const element & numero){
    os << numero.value << "," << numero.maximum; 
    return os; 
 }

/**
* @brief Constructor por defecto sin parametros 
*/
 
 MaxStack::MaxStack(){
 }
 
/**
 * @brief Devuelve el ultimo elemento almacenado en pila
 * @return Instancia de tipo element 
 */
 element MaxStack::top(){
    return cola.front();
 }

/**
 * @brief Elimina el ultimo elemento de la pila 
 */
 void MaxStack::pop(){
    cola.pop();
 }
	/**
	 * @brief Almacena en la ultima posicion una instancia elemet
	 * @param num Valor a almacenar
	 * @pre num puede ser el nuvo maximo
	 */
 void MaxStack::push(int numero){
    element num; 
    
    num.value = numero; 
    
    if(!cola.empty() && cola.front().maximum > numero){
    	num.maximum = cola.front().maximum; 
    }else{
    	num.maximum = numero; 
    }
    
    queue <element> aux; 
    aux.push(num); 
       
    while(!cola.empty()){
        aux.push(cola.front());
        cola.pop();
    }
     
    cola.swap(aux); 
 }

 /**
 * @brief Devuelve el tamanño
 * @return tamaño de la pila
 */
 int MaxStack::size(){
     return cola.size();
 }
 
 /**
 * @brief Nos indica si la pila esta vacio
 * @return true si vacia, false en otro caso
 */ 
 bool MaxStack::empty(){
    return cola.empty(); 
 }
             

