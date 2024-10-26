//
// Created by abelb on 24/10/2024.
//

#include "pila.h"

Pila::~Pila() { // Destructor de la Pila
    Nodo nodo; // Variable auxiliar para manipular el nodo
    int vv; // Variable auxiliar para el retorno del valor del nodo
    nodo = cima; // Nodo apunta al primer elemento de la pila
    cima = nodo -> siguiente; // Se asigna a pila toda la pila menos el primer elemento
    vv = nodo -> valor; // Se guarda el retorno del valor del nodo
    delete nodo; // Se borra el nodo
}


void Pila::apilar(int vv) { // Función para apilar, para meter un elemento en la
    Pila
    pNodo nuevo; // Variable auxiliar para manipular el nuevo nodo
    nuevo = new Nodo(vv, cima); // Se crea un nodo nuevo usando memoria dinámica
    cima = nuevo; // El comienzo de la pila es el nuevo nodo
    top++;
    arregloPila[top] = vv;
    cout << "\n Apilando el " << vv;
    tam++;
    cout << " ## Tamaño de la Pila: " << tam << endl;
    for(int ii = top; ii >= 0; ii--) { // Ciclo para mostrar los elementos del arreglo
        cout << " Índice: " << ii << " Elemento: " << arregloPila[ii] << endl;
    }
}
int Pila::desapilar() { // Función para desapilar, o sea, sacar un elemento de la Pila
    if(!cima) { // Si no hay nodos en la cima de la pila se devuelve 0
        cout << "\n Subderbordamiento de la pila, o sea, la pila está vacía !!!";
        return 0;
    }
    pNodo nodo; // Variable auxiliar para manipular el nodo
    int vv; // Variable auxiliar para el retorno del valor del nodo
    nodo = cima; // Nodo apunta al primer elemento de la pila
    cima = nodo -> siguiente; // Se asigna a pila toda la pila menos el primer elemento
    vv = nodo -> valor; // Se guarda el retorno del valor del nodo
    cout << "\n Desapilando el " << vv;
    delete nodo; // Se borra el nodo
    tam--;
    cout << " ## Tamaño de la Pila: " << tam << endl;
    top--;
    for(int ii = top; ii >= 0; ii--) { // Ciclo para mostrar los elementos del arreglo
        cout << " Índice: " << ii << " Elemento: " << arregloPila[ii] << endl;
    }
    return vv;
}

void Pila::mostrar() { // Función para mostrar los elementos de la Pila
    int ii;
    if(top == -1) {
        cout << "\n Subderbordamiento de la pila, o sea, la pila está vacía !!!\n";
        }
    else if(top > 0) {
        cout << "\n Los elementos de la pila son: \n";
        for(ii = top; ii >= 0; ii--) { // Ciclo para mostrar los elementos del arreglo
            cout << " Índice: " << ii << " Elemento: " << arregloPila[ii] <<
            endl;
        }
    }
}

