#include "Rafagas.h"
#include "Colisiones.h"
#include "Pantalla.h"
#include "Bala.h"
#include <stdio.h>
#include <stdlib.h>

struct RafagaRep {
    Bala dato;
    struct RafagaRep * sig;
};

typedef struct RafagaRep * Rafaga;

Rafaga nuevo_nodo (Bala b) {
    Rafaga nuevo = malloc (sizeof (struct RafagaRep));
    nuevo->dato = b;
    nuevo->sig = NULL;
    return nuevo;
}

void inserta_bala_rafaga (Rafaga r, Bala b) {
    Rafaga nuevo = nuevo_nodo (b);
    nuevo->sig = r->sig;
    r->sig = nuevo;
}

void libera_rafaga (Rafaga r) {
    Rafaga aux = r;
    while (aux->sig != NULL) {
        Rafaga borrar = r->sig;
        r->sig = borrar->sig;
        libera_bala (borrar->dato);
        free (borrar);
    }
    free (r);
}

void mueve_rafaga (Rafaga r) {
    Rafaga aux = r;
    while (aux->sig != NULL) {
        mueve_bala (aux->sig->dato);
        if (get_y_bala(aux->sig->dato) + get_h_bala(aux->sig->dato) < 0) {
            Rafaga borrar = aux->sig;
            aux->sig = borrar->sig;
            libera_bala (borrar->dato);
            free (borrar);
        } else {
        aux = aux->sig;
        }
    }
}

void dibuja_rafaga (Rafaga r) {
    Rafaga aux = r;
    while (aux->sig != NULL) {
        dibuja_bala (aux->sig->dato);
        aux = aux->sig;
    }
}

Rafaga crea_rafaga () {
    Rafaga r = malloc (sizeof (struct RafagaRep));
    r->dato = NULL;
    r->sig = NULL;
    return r;
}

int colision_rafaga(Rafaga r, double x, double y, int w, int h) {                                       // EJ 3 SESION 6 (Lo resolvemos con una búsqueda)
    Rafaga aux = r;
    while ((aux->sig != NULL) && (colision_bala (aux->sig->dato, x, y, w, h) == 0)){
        aux = aux->sig;
    }
        if (aux->sig != NULL) {
        Rafaga borrar = aux->sig;
        aux->sig = borrar->sig;
        libera_bala (borrar->dato);
        free (borrar);
        return 1;
    } else  {
        return 0;
    }
}

int longitud_rafaga (Rafaga r) {
    Rafaga aux = r;
    int contador = 0;
    while (aux->sig != NULL) {
        contador = contador + 1;
        aux = aux->sig;
    }
    return contador;
}
