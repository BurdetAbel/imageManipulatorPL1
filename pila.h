//
// Created by abelb on 24/10/2024.
//



#ifndef PILA_H
#define PILA_H
#include "nodoPilas.h"





using namespace std;

class Pila
{
private:
    pNodos cima; // Puntero cima
public:
    Pila() : cima(NULL) {}       // Constructor de Pila:  -> pila
    ~Pila();                     // Destructor de pila:  pila -> void
    void apilar(string v);     // Apilar elemento: elemento pila -> pila(devuelve un void pero el resultado interno es que modifica la pila que le das)
    string desapilar();        // Desapilar pila: pila -> elemento
    void mostrarCima();          // Mostrar cima : pila -> elemento
    bool es__pila_vacia();       // Es_pila_vacia?: pila -> bool
    string DarZonaVehiculo(Pila c); // DarZonaVehiculo: pila -> string
};

#endif // PILA_H
