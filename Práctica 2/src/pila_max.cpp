/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   pila_max.cpp
 * Author: haowe
 */

#include <iostream>
#include <queue>
#include <stack>
#include "maxstack.h"
//#include "../include/maxstack.h"

using namespace std;

int main(int argc, char *argv[]){

    // Run the current exercise
     MaxStack stack;

     for(int i = 1; i < argc; i++){
         if (argv[i][0] == '.'){
             cout << stack.top() << endl;
             stack.pop();
         } else {
             stack.push(atoi(argv[i]));
         }
     }
     return 0;
}


