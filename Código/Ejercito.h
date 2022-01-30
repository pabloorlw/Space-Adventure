#ifndef __Ejercito_H__
#define	__Ejercito_H__
#include "Pantalla.h"
#include "Rafagas.h"
#include "Enemigos.h"

/**
    \file Ejercito.h
    \brief Este módulo incluye un TDA ejército y varias funciones con las que trabajar con él. Se apoya en el uso de Pantalla.h, Rafagas.h y Enemigos.h.
*/

/**
    \brief TDA Ejercito.
*/
typedef struct EjercitoRep * Ejercito;

/**
    \brief Crea un ejército vacío.
    \param img: Imagen de los enemigos del ejército.
    \param max_enemigos: El número máximo de enemigos que tiene el ejército.
    \return Un ejército vacío.
*/
Ejercito crea_ejercito (Imagen img, int max_enemigos);

/**
    \brief Obtiene el número de enemigos que tiene el ejército actualmente (eliminados y no eliminados).
    \param e: Ejército cuyo número de enemigos se quiere saber.
    \return El número de enemigos que tiene el ejército (eliminados y no eliminados).
*/
int get_num_enemigos (Ejercito e);

/**
    \brief Libera la memoria asociada al ejército (excepto la imagen de sus enemigos).
    \param e: Ejército cuya memoria se quiere liberar.
    \param max_enemigos: El número máximo de enemigos que tiene el ejército.
*/
void libera_ejercito (Ejercito e, int max_enemigos);

/**
    \brief Inserta un enemigo en el ejército.
    \param e: Ejército donde se quiere insertar el enemigo.
    \param x: Coordenada horizontal de la esquina superior izquierda del enemigo.
    \param y: Coordenada vertical de la esquina superior izquierda del enemigo.
    \param w: Ancho del enemigo.
    \param h: Alto del enemigo.
    \param vx: Velocidad en el eje horizontal del enemigo.
    \param vy: Velocidad en el eje vertical del enemigo.
    \param max_enemigos: El número máximo de enemigos que tiene el ejército.
*/
void inserta_enemigo (Ejercito e, double x, double y, int w, int h, double vx, double vy, int max_enemigos);

/**
    \brief Mueve todo el ejército.
    \param e: Ejército que se quiere mover.
*/
void mueve_ejercito (Ejercito e);

/**
    \brief Dibuja todo el ejército
    \param e: Ejército que se quiere dibujar.
*/
void dibuja_ejercito (Ejercito e);

/**
    \brief Detecta si ha habido colisión entre un enemigo del ejérctito y un rectángulo y elimina al enemigo en cuestión.
    \param e: Ejército del que se quiere saber si ha colisionado.
    \param x: Coordenada horizontal de la esquina superior izquierda del rectángulo.
    \param y: Coordenada vertical de la esquina superior izquierda del rectángulo.
    \param w: Ancho del rectángulo.
    \param h: Alto del rectángulo.
    \return 1 si ha habido colisión.
    \return 0 si no ha habido colisión.
*/
int colision_ejercito_objeto (Ejercito e, double x, double y, int w, int h);

/**
    \brief Detecta si ha habido colisión entre un enemigo del ejército y una ráfaga de balas, elimina al enemigo en cuestión y genera dos enemigos extra.
    \param e: Ejército del que se quiere saber si ha habido colisión.
    \param r: Ráfaga de balas de la que se quiere saber si ha habido colisión.
    \param max_enemigos: Número máximo de enemigos que tiene el ejército.
    \return 1 si ha habido colisión.
    \return 0 si no ha habido colisión.
*/
int colision_ejercito_rafaga (Ejercito e, Rafaga r, int max_enemigos);

/**
    \brief Hace rebotar a los enemigos del ejército que se choquen con los bordes de la pantalla.
    \param e: Ejército que contiene a los enemigos que se quieren hacer rebotar.
    \param ancho_pantalla: El ancho de la pantalla.
    \param alto_pantalla: El alto de la pantalla.
*/
void rebota_ejercito (Ejercito e, double ancho_pantalla, double alto_pantalla);

#endif
