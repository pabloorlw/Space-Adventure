#include "Enemigos.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct EnemigosRep {                // Creamos una estructura "enemigo" que tiene como campos:
    double x;                       // Posición horizontal del enemigo
    double y;                       // Posición vertical del enemigo
    int w;                          // Anchura del enemigo
    int h;                          // Altura del enemigo
    double vx;                      // Velocidad horizontal del enemigo
    double vy;                      // Velocidad vertical del enemigo
    int Eliminado;                  // 1 si el enemigo está eliminado, 0 si no lo está
};

typedef struct EnemigosRep * Enemigo;

Enemigo crea_enemigo (double x, double y, int w, int h, double vx, double vy) {           // Reserva memoria dinámica y crea un enemigo en la posición (x, y) y de anchura y altura w, h
    Enemigo nuevo = malloc (sizeof (struct EnemigosRep));
    nuevo->x = x;
    nuevo->y = y;
    nuevo->w = w;
    nuevo->h = h;
    nuevo->vx = vx;
    nuevo->vy = vy;
    nuevo->Eliminado = 0;
    return nuevo;
}

void elimina_enemigo (Enemigo enem) {
    enem->Eliminado = 1;
}

int enemigo_eliminado (Enemigo enem) {
    if (enem->Eliminado == 1) {
        return 1;
    } else return 0;
}

void libera_enemigo (Enemigo enem) {                                      // Libera la memoria dinámica asociada al enemigo
    free (enem);
}

void mueve_enemigo (Enemigo enem) {
    if (!enemigo_eliminado(enem)) {
        enem->x = enem->x + enem->vx;
        enem->y = enem->y + enem->vy;
    }
}

double get_x_enemigo (Enemigo enem) {                                   // Devuelve la coordenada x del enemigo
    return enem->x;
}

double get_y_enemigo (Enemigo enem) {                                   // Devuelve la coordenada y del enemigo
    return enem->y;
}

int get_w_enemigo (Enemigo enem) {                                   // Devuelve el ancho del enemigo
    return enem->w;
}

int get_h_enemigo (Enemigo enem) {                                   // Devuelve el alto del enemigo
    return enem->h;
}

double get_vx_enemigo (Enemigo enem) {
    return enem->vx;
}

double get_vy_enemigo (Enemigo enem) {
    return enem->vy;
}

void set_vx_enemigo (Enemigo enem, double vx) {
    enem->vx = vx;
}

void set_vy_enemigo (Enemigo enem, double vy) {
    enem->vy = vy;
}

void set_w_enemigo (Enemigo enem, int w) {
    enem->w = w;
}

void set_h_enemigo (Enemigo enem, int h) {
    enem->h = h;
}


