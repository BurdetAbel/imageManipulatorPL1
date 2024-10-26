//
// Created by abelb on 24/10/2024.
//

#ifndef NODOCOLAS_H
#define NODOCOLAS_H




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
