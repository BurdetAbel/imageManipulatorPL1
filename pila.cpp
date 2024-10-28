//
// Created by abelb on 24/10/2024.
//

#include "pila.h"
#include <iostream>

//---------------------------------------------------------------------------------------------------------------------------------------

//Destructor de la Pila
Pila::~Pila()
{
    while(cima) desapilar();
}

//---------------------------------------------------------------------------------------------------------------------------------------

// Meter elemento en la Pila
void Pila::apilar(Mat v)
{
    cout << "apilando" << endl;
    pNodos nuevo; //Var aux para manipular el nuevo nodo

    //Se crea un nodo nuevo
    nuevo = new nodos(v, cima);

    //El comienzo de la pila es el nuevo nodo
    cima = nuevo;
}

//---------------------------------------------------------------------------------------------------------------------------------------

// Sacar elemento de la Pila
Mat Pila::desapilar()
{
    cout << "desapilando" << endl;
    pNodos nodo; // Var aux para manipular el nodo
    Mat v; // Var aux para el retorno del valor del nodo


    string imagen_path_error;
    imagen_path_error = "C:/Users/abelb/CLionProjects/imageManipulatorPL1/images8k/errorimg.jpg";
    if(!cima) return imread(imagen_path_error); // Si no hay nodos en la pila se devuelve 0

    // Nodo apunta al primer elemento de la pila
    nodo = cima;

    // Se asigna a pila toda la pila menos el primer elemento
    cima= nodo->siguiente;

    // Se guarda el retorno del valor del nodo
    v = nodo->valor;

    // Se borra el nodo
    delete nodo;

    return v;
}

//---------------------------------------------------------------------------------------------------------------------------------------

// Mostrar la cima de la pila
void Pila::mostrarCima()
{
    cout<<"-------------------------------"<<endl;
    if(!cima) cout << "Esta vacia" << endl;
    else{
        cout << "imagen: ";
        imshow("imagen", cima->valor);
        }
}

//---------------------------------------------------------------------------------------------------------------------------------------

// Muestra si la pila esta vacia
bool Pila::es__pila_vacia()
{
    bool b;

    if (!cima)
    b = true;
    else{
        b = false;
    }

    return b;
}

//---------------------------------------------------------------------------------------------------------------------------------------

/*
#include "pila.h"

Pila::~Pila() { // Destructor de la Pila
    NodoPi nodo; // Variable auxiliar para manipular el nodo
    int vv; // Variable auxiliar para el retorno del valor del nodo
    nodo = cima; // Nodo apunta al primer elemento de la pila
    cima = nodo -> siguiente; // Se asigna a pila toda la pila menos el primer elemento
    vv = nodo -> valor; // Se guarda el retorno del valor del nodo
    delete nodo; // Se borra el nodo
}


void Pila::apilar(int vv) { // Función para apilar, para meter un elemento en la
    Pila
    pNodo nuevo; // Variable auxiliar para manipular el nuevo nodo
    nuevo = new NodoPi(vv, cima); // Se crea un nodo nuevo usando memoria dinámica
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

*/

