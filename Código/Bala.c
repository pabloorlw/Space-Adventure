#include "Bala.h"
#include "Colisiones.h"
#include "Pantalla.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct BalaRep {
    double x;
    double y;
    int w;
    int h;
    double vx;
    double vy;
    Imagen img;
};

typedef struct BalaRep * Bala;

Bala crea_bala (double x, double y, int w, int h, double vx, double vy, Imagen img) {
    Bala NuevaBala = malloc (sizeof (struct BalaRep));
    NuevaBala->x       =   x;
    NuevaBala->y       =   y;
    NuevaBala->w       =   w;
    NuevaBala->h       =   h;
    NuevaBala->vx      =   vx;
    NuevaBala->vy      =   vy;
    NuevaBala->img     =   img;
    return NuevaBala;
}

void libera_bala (Bala b) {
    free (b);
}

void mueve_bala (Bala b) {
    b->x = b->x + b->vx;
    b->y = b->y + b->vy;
}

void dibuja_bala (Bala b) {
    Pantalla_DibujaImagen (b->img, b->x , b->y, b->w, b->h);
}

double get_x_bala (Bala b) {
    return b->x;
}

double get_y_bala (Bala b) {
    return b->y;
}

int get_w_bala (Bala b) {
    return b->w;
}

int get_h_bala (Bala b) {
    return b->h;
}

int	colision_bala (Bala b, double x, double	y, int w, int	h) {
    if (solape_rectangulos (b->x, b->y, b->w, b->h, x, y, w, h)) {
        return 1;
    } else {
        return 0;
    }
}
