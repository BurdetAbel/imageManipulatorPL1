//
// Created by abelb on 24/10/2024.
//

#include "colas.h"
void Cola::encolar(int vv) {
pnodo nuevo; // Crear el nodo nuevo
nuevo = new Nodo(vv);
/* Si la cola no estaba vacía, añadimos el nuevo a continuación de último */
if(ultimo) ultimo -> siguiente = nuevo;
ultimo = nuevo;/* Ahora, el último elemento de la cola es el nuevo nodo */
/* Si primero es NULL, la cola estaba vacía, ahora primero apuntará también 
al nuevo nodo */
if(!primero) primero = nuevo;
}


int Cola::desencolar() {
pnodo nodoaux; /* variable auxiliar para manipular nodo */
int vv; /* variable auxiliar para retorno */
nodoaux = primero;/* Nodo apunta al primer elemento de la pila */
if(!nodoaux) return 0; /* Si no hay nodos en la pila, retornamos 0 */
primero = nodoaux -> siguiente; /* Asignamos a primero la dirección del
segundo nodo */
vv = nodoaux -> valor; /* Guardamos el valor de retorno */
delete nodoaux; /* Borrar el nodo */
if(!primero) ultimo = NULL; /* Si la cola quedó vacía, ultimo debe ser NULL
también*/
return vv;
}