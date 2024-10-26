//
// Created by abelb on 24/10/2024.
//

#ifndef COLAS_H
#define COLAS_H

#include "nodoColas.h"


class Cola {
    private:
    pnodo ultimo, primero;
    public:
    Cola() : ultimo(NULL), primero(NULL) {} // Contructor de dos nodos vacío
    ~Cola(); // Destructor
    void encolar(int vv);
    int desencolar();
};
Cola::~Cola() { // Para destruir los nodos
    while(primero) desencolar();
}


#endif //COLAS_H
