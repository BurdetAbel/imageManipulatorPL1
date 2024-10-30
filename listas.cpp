//
// Created by abelb on 24/10/2024.
//
/*
#include "listas.h"
using std::string, std::cout, std::endl, std::cerr;
using std::cin;
using std::cout;
using std::endl;

void Lista::crearLista( )
{
    int x;
    Mat ej;
    primero = NULL;
    cout << "Termina con −1" << endl;
    do {
        cin >> x;
        if (x != -1)
        {
            primero = new Nodo(ej,primero);
        }
    }while (x != -1);
}

void Lista::insertarCabezaLista(Dato entrada)
{
    Nodo* nuevo ;
    nuevo = new Nodo(entrada);
    nuevo -> ponerEnlace(primero); // enlaza nuevo con primero
    primero = nuevo; // mueve primero y apunta al nuevo nodo
}

void Lista::insertarUltimo(Dato entrada)
{
    Nodo* ultimo = this -> ultimo( );
    ultimo -> ponerEnlace(new Nodo(entrada));
}
Nodo* Lista::ultimo( )
{
    Nodo* p = primero;
    if (p == NULL ) throw "Error, lista vacía";
    while (p -> enlaceNodo( )!= NULL) p = p -> enlaceNodo( );
    return p;
}
Nodo* Lista:: buscarLista(Dato destino)
{
    Nodo* indice;
    for (indice = primero; indice!= NULL; indice=indice->enlaceNodo( ))
        if (destino == indice -> datoNodo( ))
            return indice;
    return NULL;
}

void Lista::eliminar(Dato entrada)
{
    Nodo *actual, *anterior;
    bool encontrado;
    actual = primero;
    anterior = NULL;
    encontrado = false;
    // búsqueda del nodo y del anterior
    while ((actual != NULL) && !encontrado)
    {
        encontrado = (actual -> datoNodo( ) == entrada);
        if (!encontrado)
        {
            anterior = actual;
            actual = actual -> enlaceNodo( );
        }
    }
    // enlace del nodo anterior con el siguiente
    if (actual != NULL)
    {
        // distingue entre cabecera y resto de la lista
        if (actual == primero)
        {
            primero = actual -> enlaceNodo( );
        }
        else
        {
            anterior -> ponerEnlace(actual -> enlaceNodo( ));
        }
        delete actual;
    }
}
*/