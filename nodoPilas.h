//
// Created by abelb on 24/10/2024.
//

#ifndef NODOPILAS_H
#define NODOPILAS_H



// Práctica de Pilas
#include <iostream>
#include <locale.h> // Librería de configuraciones específicas
using std::cout; using std::cin; using std::endl;
class Nodo {
private:
    int valor;
    Nodo *siguiente;
    friend class Pila;
public:
    Nodo(int vv, Nodo *sig = NULL) { //Constructor de Nodo
        valor = vv;
        siguiente = sig;
    }
};
typedef Nodo *pNodo;



#endif //NODOPILAS_H
