//
// Created by abelb on 24/10/2024.
//
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>  // Para la función cvtColor
/*
#ifndef NODOCOLAS_H
#define NODOCOLAS_H

#include <iostream>
using namespace std;


class nodos
{
private:
    string valor; // Valor de la estructura
    nodos *siguiente; // Puntero siguiente
    friend class Cola; // Comparte datos con la clase Cola
    friend class Pila; //Comparte datos con la clase Pila
public:
    nodos(string v, nodos *sig = NULL) // Composici�n y creaci�n del nodo
    {
        valor = v;
        siguiente = sig;
    }
};

typedef nodos *pNodos; // Definimos el tipo nodos como puntero
/*

// Cola Simple con Clases, Nodos y Clase Amiga. Ejemplo de laboratorio
#include <iostream>
#include <locale.h> // Librería de configuraciones específicas
using std::cout; using std::cin; using std::endl;
class Nodo {
private:
    int valor; // El elemento del nodo
    Nodo *siguiente; // el puntero siguiente del nodo
    friend class Cola; // La clase amiga para tener acceso a las partes private de la clase
public:
    Nodo(int vv, Nodo *sig = NULL) {
        valor = vv;
        siguiente = sig;
    }
};
typedef Nodo *pnodo; // Variable puntero que es un tipo de variable de tipo Nodo




#endif //NODOCOLAS_H
*/