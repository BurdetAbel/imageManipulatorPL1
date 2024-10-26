//
// Created by abelb on 24/10/2024.
//



#ifndef PILA_H
#define PILA_H
#include "nodoPilas.h"
class Pila {
private:
    pNodo cima;
public:
    Pila() : cima(NULL) {} // Constructor de Pila1
    ~Pila(); // Destructor de la pila
    int arregloPila[200]; // Implementación del arreglo arregloPila
    int top = -1; // Control de pila vacía del arregloPila
    int tam = 0;
    void apilar(int);
    int desapilar();
    void mostrar();
};
#endif //PILA_H
