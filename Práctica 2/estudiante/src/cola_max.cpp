/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   cola_max.cpp
 * Author: haowe
 */

#include <iostream>
#include <queue>
#include <stack>
#include <maxqueue.h> 
//#include "../include/maxqueue.h"

using namespace std;

int main(int argc, char *argv[]){

    // // Run the current exercise
     MaxQueue queue;

     for(int i = 1; i < argc; i++){
         if (argv[i][0] == '.'){
             cout << queue.front() << endl;
             queue.pop();
         } else {
             queue.push(atoi(argv[i]));
         }
     }
     return 0;
}

