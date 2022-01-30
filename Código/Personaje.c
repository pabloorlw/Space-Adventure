#include "Pantalla.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct PersonajeRep {
    double x;
    double y;
    double w;
    int h;
    int vx;
    double vy;
    Imagen img;
};

typedef struct PersonajeRep * Personaje;

double get_x_personaje (Personaje p) {
    return p->x;
}

double get_y_personaje (Personaje p) {
    return p->y;
}

int get_w_personaje (Personaje p) {
    return p->w;
}

int get_h_personaje (Personaje p) {
    return p->h;
}

Personaje crea_nuevo_personaje (double x, double y, int w, int h, double vx, Imagen img) {
    Personaje nuevo = malloc (sizeof (struct PersonajeRep));
    nuevo->x = x;
    nuevo->y = y;
    nuevo->w = w;
    nuevo->h = h;
    nuevo->vx = vx;
    nuevo->vy = 0;                                                   // La velocidad vertical la iniciaremos a 0 pues la necesitaremos para simular los saltos
    nuevo->img = img;
    return nuevo;
}

void libera_personaje (Personaje p) {
    free (p);
}

void mueve_personaje (Personaje p, double ancho_pantalla) {
    if (Pantalla_TeclaPulsada (SDL_SCANCODE_RIGHT) && p->x < ancho_pantalla - p->w) {
        p->x = p->x + p->vx;
    }
    if (Pantalla_TeclaPulsada (SDL_SCANCODE_LEFT) && p->x > 0) {
        p->x = p->x - p->vx;
    }
}

void salta_personaje (Personaje p, double alto_pantalla) {
    p->y = p->y + p->vy;
    if ((Pantalla_TeclaPulsada(SDL_SCANCODE_UP)) && (p->y == alto_pantalla - p->h)) {
        p->vy = -5;
    }
    if (p->y <= alto_pantalla - 3*p->h) {               // Salta hasta llegar a una altura como máximo de 3 veces la altura del personaje
        p->vy = 1.5;
    }
    if (p->y > alto_pantalla - p->h) {
        p->y = alto_pantalla - p->h;
        p->vy = 0;
    }
}

void dibuja_personaje (Personaje p) {
    Pantalla_DibujaImagen(p->img, p->x, p->y, p->w, p->h);
}

