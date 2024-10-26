//
// Created by abelb on 24/10/2024.
//

#ifndef LISTAS_H
#define LISTAS_H
#include "nodoListas.h"
#include <iostream>

// archivo Lista.h
class Lista
{
protected:
    Nodo* primero;
public:
    Lista( ) { primero = NULL;}
    void crearLista( );
    void insertarCabezaLista(Dato entrada);
    void insertarUltimo(Dato entrada);
    void insertarLista(Dato entrada);
    Nodo* buscarLista(Dato destino);
    void eliminar(Dato entrada);
    Nodo* ultimo( );
    void visualizar( );
};

#endif //LISTAS_H
