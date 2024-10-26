//
// Created by abelb on 24/10/2024.
//

/*

#include "colas.h"

#include <stdlib.h>
#include <iostream>

//---------------------------------------------------------------------------------------------------------------------------------------
//Variable contador para metodo mostrar
int contador;
// Destructor
Cola::~Cola()
{
    while(primero) desencolar();
}

//---------------------------------------------------------------------------------------------------------------------------------------

void Cola::encolar(string v)
{
    pNodos nuevo; // Crear un nodo nuevo
    nuevo = new nodos(v);

    // Si la cola no estaba vac�a, a�adimos el nuevo a continuaci�n de �ltimo
    if(ultimo) ultimo->siguiente = nuevo;

    // Ahora, el �ltimo elemento de la cola es el nuevo nodo
    ultimo = nuevo;

    // Si primero es NULL, la cola estaba vac�a, ahora primero apuntar� tambi�n al nuevo nodo
    if(!primero) primero = nuevo;
}

//---------------------------------------------------------------------------------------------------------------------------------------

string Cola::desencolar()
{
    pNodos nodo; // variable auxiliar para manipular nodo
    string v; // variable auxiliar para retorno

    // Nodo apunta al primer elemento de la pila
    nodo = primero;

    if(!nodo) return generaCocheVacio(); // Si no hay nodos en la pila retornamos 0

    // Asignamos a primero la direcci�n del segundo nodo
    primero = nodo->siguiente;

    // Guardamos el valor de retorno
    v = nodo->valor;

    // Borrar el nodo
    delete nodo;

    // Si la cola qued� vac�a, ultimo debe ser NULL tambi�n
    if(!primero) ultimo = NULL;

    return v;
}

//---------------------------------------------------------------------------------------------------------------------------------------

// Muestra los valores de la cola
void Cola::mostrar()
{
    pNodos aux = primero;//nodo aux apunta a primero

    //mientras aux exista se muestran los valores que hay dentro de la cola
    while(aux)
    {
            cout<< " -------------------------------------------    "<<endl;
            cout <<"Vehiculo: "<<aux->valor.color<<", "<<aux->valor.zona<<""<<aux->valor.num_concesionario<<", "<<aux->valor.modelo<<", "<<aux->valor.num_bastidor<<", "<<aux->valor.dig_camion<<endl;
            aux = aux->siguiente;//aux apunta al siguiente valor en la cola
            contador += 1;
    }
    cout <<""<<endl;
}

//---------------------------------------------------------------------------------------------------------------------------------------

// Observa si la cola est� vacia
bool Cola::es__cola_vacia()
{
    bool b;
    pNodos nodo;
    nodo = primero; // Nodo apunta a primero

    if (!nodo) // Si nodo no existe
        b = true; // Variable toma el valor de true
    else{ // Si existe
        b = false; // Variable toma el valor de false
    }

    return b; // Devuelve el valor de la variable
}
//---------------------------------------------------------------------------------------------------------------------------------------


*/