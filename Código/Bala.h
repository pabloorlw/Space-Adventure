#ifndef __Bala_H__
#define __Bala_H__
#include "Colisiones.h"
#include "Pantalla.h"

/**
    \file Bala.h
    \brief Este módulo incluye un TDA que representa una bala rectangular y añade varias funciones para trabajar con ella. Se apoya en el uso de Pantalla.h.
*/

/**
    \brief TDA Bala.
*/
typedef struct BalaRep * Bala;

/**
    \brief Crea una bala en las coordenadas (x, y) de la pantalla.
    \param x: Coordenada horizontal de la esquina superior izquierda de la bala.
    \param y: Coordenada vertical de la esquina superior izquierda de la bala.
    \param w: Ancho de la bala.
    \param h: Alto de la bala.
    \param vx: Velocidad en el eje horizontal de la bala.
    \param vy: Velocidad en el eje vertical de la bala.
    \param img: Imagen de la bala.
    \return Una bala.
*/
Bala crea_bala (double x, double y, int w, int h, double vx, double vy, Imagen img);

/**
    \brief Libera la memoria asociada a la Bala b (excepto la de su imagen).
    \param b: Bala cuya memoria se quiere liberar.
*/
void libera_bala (Bala b);

/**
    \brief Mueve la bala por la pantalla.
    \param b: Bala que se quiere mover.
*/
void mueve_bala (Bala b);

/**
    \brief Dibuja la bala en la pantalla.
    \param b: Bala que se quiere dibujar.
*/
void dibuja_bala (Bala b);

/**
    \brief Detecta si ha habido colisión entre la Bala b y un rectángulo.
    \param b: Bala que se quiere saber si colisona.
    \param x: Coordenada horizontal de la esquina superior izquierda del rectángulo.
    \param y: Coordenada vertical de la esquina superior izquierda del rectángulo.
    \param w: Ancho del rectángulo.
    \param h: Alto del rectángulo.
    \return 1 si ha habido colisión.
    \return 0 si no ha habido colisión.
*/
int colision_bala (Bala b, double x, double y, int w, int h);

/**
    \brief Recupera la coordenada horizontal de la esquina superior izquierda de la bala.
    \param b: Bala cuya coordenada se quiere recuperar.
    \return La coordenada horizontal de la esquina superior izquierda de la bala.
*/
double get_x_bala (Bala b);

/**
    \brief Recupera la coordenada vertical de la esquina superior izquierda de la bala.
    \param b: Bala cuya coordenada se quiere recuperar.
    \return La coordenada vertical de la esquina superior izquierda de la bala.
*/
double get_y_bala (Bala b);

/**
    \brief Recupera el ancho de la bala.
    \param b: Bala de la que se quiere recuperar el ancho.
    \return El ancho de la bala.
*/
int get_w_bala (Bala b);

/**
    \brief Recupera el alto de la bala.
    \param b: Bala de la que se quiere recuperar el alto.
    \return El alto de la bala.
*/
int get_h_bala (Bala b);

#endif
