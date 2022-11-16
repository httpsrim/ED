/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/**
 * @file maxqueue.cpp
 * @brief  Archivo de implementación del TDA MaxQueue
 * @author Haowei e Inés
 */
 

 #include <stack>
 #include <queue>
 #include <iostream> 
 #include <maxqueue.h> 
 //#include "../include/maxqueue.h"
 
 /**
 * @brief Ostream para sacar por pantalla los valores 
 * @param os flujo de salida 
 * @param numero Instacia de tipo element que va a ser imprimdida por pantalla
 * @return Devuelve el flujo os
 */
 std::ostream & operator <<(std::ostream & os, const element & numero){
    os << numero.value << "," << numero.maximum; 
    return os; 
 }
/**
 * @brief Constructor sin parámetros
 */
 MaxQueue::MaxQueue(){
 }

/**
* @brief Devuelve el primer elemento guardado en cola
* @return Primer elemento de la cola
*/
 element MaxQueue::front(){
    return pila.top();
 }

/**
* @brief Elimina el primer elemento de la cola
*/
 void MaxQueue::pop(){
    pila.pop();
 }

/**
* @brief Almacena en la ultima posicion una instancia de tipo element
* @param numero Valor a almacenar en la cola
*/  
 void MaxQueue::push(int numero){
    element num; 
    num.value = numero; 
    num.maximum = numero; 
    stack<element> aux; 
     
    while(!pila.empty()){
        aux.push(pila.top());
        pila.pop();
    }
    
    aux.push(num); 
   
    while(!aux.empty()){
        pila.push(aux.top());
         
        if(pila.top().maximum < num.maximum){
            pila.top().maximum = num.maximum;
        }
        
        aux.pop(); 
    }
 }

/**
* @brief Devuelve el tamaño de la cola 
* @return Cantidad de elementos existentes en la cola 
*/
 int MaxQueue::size(){
     return pila.size();
 }
 
/**
* @brief Indica si la cola esta vacia
* @return True si esta vacia
* @return False si la cola posee elementos 
*/
 bool MaxQueue::empty(){
    return pila.empty(); 
 }
             
