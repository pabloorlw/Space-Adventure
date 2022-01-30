#include "Ejercito.h"
#include "Enemigos.h"
#include "Colisiones.h"
#include "Rafagas.h"
#include "Pantalla.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define w_min 25                                     // Este es el ancho mínimo que deben tener los enemigos para poder ser doblados.


struct EjercitoRep {
    int num_enemigos;                                // La variable num_enemigos nos indicará cuántos enemigos hay almacenados actualmente en el array (vacíos o no vacíos)
    Enemigo *array_enemigos;
    Imagen img_enem;
};

typedef struct EjercitoRep * Ejercito;

int get_num_enemigos (Ejercito e) {
    return e->num_enemigos;
}

Ejercito crea_ejercito (Imagen img, int max_enemigos) {
    Ejercito nuevo = malloc (sizeof (struct EjercitoRep));
    nuevo->array_enemigos = (Enemigo *)malloc (max_enemigos * sizeof (Enemigo));            // Reservamos memoria para el array dinámico
    nuevo->img_enem = img;
    nuevo->num_enemigos = 0;
    return nuevo;
}

void libera_ejercito (Ejercito e, int max_enemigos) {
    for (int i = 0; i < max_enemigos; i++) {
        libera_enemigo (e->array_enemigos[i]);
    }
    free (e->array_enemigos);                                                                  // También debemos liberar la memoria asociada al array dinámico
    free (e);
}

void inserta_enemigo (Ejercito e, double x, double y, int w, int h, double vx, double vy, int max_enemigos) {
    if (e->num_enemigos < max_enemigos) {                                                          // Aclaración: como estamos utilizando e->num_enemigos como índice del índice del array y este empieza en 0, si
        e->array_enemigos[e->num_enemigos] = crea_enemigo (x, y, w, h, vx, vy);                    // p.e max_enemigos = 3 el tercer y último enemigo estará almacenado en la posición 2, por eso < en vez de <=
        e->num_enemigos++;
    }
}

void mueve_ejercito (Ejercito e) {
    for (int i = 0; i < e->num_enemigos; i++) {
        mueve_enemigo (e->array_enemigos[i]);
    }

}

void rebota_ejercito (Ejercito e, double ancho_pantalla, double alto_pantalla) {
    for (int i = 0; i < e->num_enemigos; i++) {
        if ((get_x_enemigo (e->array_enemigos[i]) + get_w_enemigo (e->array_enemigos[i]) > ancho_pantalla) || (get_x_enemigo (e->array_enemigos[i]) < 0)) {            // Si el enemigo está fuera de los bordes de la pantalla
            set_vx_enemigo (e->array_enemigos[i], -1 * get_vx_enemigo (e->array_enemigos[i]));                                                                        // cambiamos su velocidad haciendo que rebote
        }
        if ((get_y_enemigo(e->array_enemigos[i]) + get_h_enemigo (e->array_enemigos[i]) > alto_pantalla) || (get_y_enemigo (e->array_enemigos[i]) < 0)) {
            set_vy_enemigo (e->array_enemigos[i], -1 * get_vy_enemigo (e->array_enemigos[i]));
        }
    }
}

void dibuja_ejercito (Ejercito e) {
    for (int i = 0; i < e->num_enemigos; i++) {
        if (!enemigo_eliminado(e->array_enemigos[i])) {                                                   // Antes de dibujar en pantalla el enemigo nos aseguramos de que existe
            Pantalla_DibujaImagen(e->img_enem, get_x_enemigo(e->array_enemigos[i]), get_y_enemigo(e->array_enemigos[i]), get_w_enemigo(e->array_enemigos[i]), get_h_enemigo(e->array_enemigos[i]));
        }
    }
}

int colision_ejercito_objeto (Ejercito e, double x, double y, int w, int h) {
    int i = 0;
    while (i < e->num_enemigos) {
        if ((!enemigo_eliminado(e->array_enemigos[i])) && (solape_rectangulos(get_x_enemigo(e->array_enemigos[i]), get_y_enemigo(e->array_enemigos[i]), get_w_enemigo(e->array_enemigos[i]), get_h_enemigo(e->array_enemigos[i]), x, y, w, h))){
            elimina_enemigo(e->array_enemigos[i]);
            return 1;
        }
        i++;
    }
    return 0;
}

int colision_ejercito_rafaga (Ejercito e, Rafaga r, int max_enemigos) {                             // Implementamos #DoblaEnemigos.
    int contador_colisiones = 0;
    int i = 0;
    while (i < e->num_enemigos) {
        if ((!enemigo_eliminado(e->array_enemigos[i])) && (colision_rafaga (r, get_x_enemigo(e->array_enemigos[i]), get_y_enemigo(e->array_enemigos[i]), get_w_enemigo(e->array_enemigos[i]), get_h_enemigo(e->array_enemigos[i])))) {
            contador_colisiones++;
            elimina_enemigo (e->array_enemigos[i]);
            if ((get_w_enemigo(e->array_enemigos[i]) > w_min) && (i < max_enemigos -1)) {
                inserta_enemigo (e, get_x_enemigo(e->array_enemigos[i]) - 10, get_y_enemigo(e->array_enemigos[i]), get_w_enemigo(e->array_enemigos[i]) / 2, get_h_enemigo(e->array_enemigos[i]) / 2, get_vx_enemigo(e->array_enemigos[i]), get_vy_enemigo(e->array_enemigos[i]), max_enemigos);
                inserta_enemigo (e, get_x_enemigo(e->array_enemigos[i]) + 20, get_y_enemigo(e->array_enemigos[i]), get_w_enemigo(e->array_enemigos[i]) / 2, get_h_enemigo(e->array_enemigos[i]) / 2, get_vx_enemigo(e->array_enemigos[i]), get_vy_enemigo(e->array_enemigos[i]), max_enemigos);
            }

        }
    i++;
    }
    return contador_colisiones;
}

