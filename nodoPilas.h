//
// Created by abelb on 24/10/2024.
//



#ifndef NODOPILAS_H
#define NODOPILAS_H

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>  // Para la función cvtColor
#include <iostream>
#include <filesystem>


using std::string, std::cout, std::endl, std::cerr;
using namespace cv;
namespace fs = std::filesystem;  // Alias para el espacio de nombres


class nodos
{

    string valor; // Valor de la estructura
    nodos *siguiente; // Puntero siguiente
    friend class Cola; // Comparte datos con la clase Cola
    friend class Pila; //Comparte datos con la clase Pila
public:
    nodos(string v, nodos *sig = NULL) // Composicion y creaci�n del nodo
    {
        valor = v;
        siguiente = sig;
    }
};

typedef nodos *pNodos; // Definimos el tipo nodos como puntero


#endif //NODOPILAS_H

