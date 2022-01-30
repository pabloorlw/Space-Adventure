#ifndef __Personaje_H__
#define	__Personaje_H__
#include "Pantalla.h"

/**
    \file Personaje.h
    \brief Este módulo incluye un TDA que representa a un personaje rectangular y varias funciones con las trabajar con él. Se apoya en el uso de Pantalla.h.
*/

/**
    \brief TDA Personaje.
*/
typedef struct PersonajeRep * Personaje;

/**
    \brief Recupera la coordenada horizontal de la esquina superior izquierda del personaje.
    \param p: Personaje cuya coordenada se quiere recuperar.
    \return La coordenada horizontal de su esquina superior izquierda.
*/
double get_x_personaje (Personaje p);

/**
    \brief Recupera la coordenada vertical de la esquina superior izquierda del personaje.
    \param p: Personaje cuya cordenada se quiere recuperar.
    \return La coordenada vertical de su esquina superior izquierda.
*/
double get_y_personaje (Personaje p);

/**
    \brief Recupera el ancho del personaje.
    \param p: Personaje cuyo ancho se quiere recuperar.
    \return El ancho del personaje.
*/
int get_w_personaje (Personaje p);

/**
    \brief Recupera el alto del personaje.
    \param p: Personaje cuyo alto se quiere recuperar.
    \return El alto del personaje.
*/
int get_h_personaje (Personaje p);

/**
    \brief Crea un nuevo personaje.
    \param x: Coordenada horizontal de la esquina superior izquierda del personaje que se quiere crear.
    \param y: Coordenada vertical de la esquina superior izquierda del personaje que se quiere crear.
    \param w: Ancho del personaje que se quiere crear.
    \param h: Alto del personaje que se quiere crear.
    \param vx: Velocidad en el eje horizontal del personaje que se quiere crear.
    \param vy: Velocidad en el eje vertical del personaje que se quiere crear.
    \param img: Imagen del personaje que se quiere crear.
    \return Un nuevo personaje.
*/
Personaje crea_nuevo_personaje (double x, double y, int w, int h, double vx, Imagen img);

/**
    \brief Libera la memoria asociada al personaje (excepto a la de su imagen).
    \param p: Personaje cuya memoria se quiere liberar.
*/
void libera_personaje (Personaje p);

/**
    \brief Mueve al personaje a la izquierda si pulsamos la flecha izquierda y a la derecha si pulsamos la tecla derecha.
    \param p: Personaje que se quiere mover.
    \param ancho_pantalla: Ancho de la pantalla.
*/
void mueve_personaje (Personaje p, double ancho_pantalla);

/**
    \brief Hace saltar al personaje simulando la gravedad.
    \param p: Personaje que se quiere hacer saltar.
    \param alto_pantalla: El alto de la pantalla.
*/
void salta_personaje (Personaje p, double alto_pantalla);

/**
    \brief Dibuja al personaje en la pantalla.
    \param p: Personaje que se quiere dibujar.
*/
void dibuja_personaje (Personaje p);

#endif
