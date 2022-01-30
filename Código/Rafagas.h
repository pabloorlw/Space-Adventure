#ifndef __Rafagas_H_
#define __Rafagas_H_
#include "Bala.h"

/**
    \file Rafagas.h
    \brief Este módulo incluye un TDA que representa una ráfaga de balas y añade varias funciones para trabajar con ella. Se apoya en el uso de Bala.h.
*/


/**
    \brief TDA Ráfaga.
*/
typedef struct RafagaRep * Rafaga;

/**
    \brief Crea una ráfaga de balas vacía.
    \return Una ráfaga de balas vacía.
*/
Rafaga crea_rafaga ();

/**
    \brief Libera la memoria asociada a la ráfaga.
*/
void libera_rafaga (Rafaga r);

/**
    \brief Inserta una bala en la ráfaga.
    \param r: Ráfaga en la que se quiere insertar la bala.
    \param b: Bala que se quiere insertar en la ráfaga.
*/
void inserta_bala_rafaga (Rafaga r,	Bala b);

/**
    \brief Mueve toda la ráfaga por la pantalla.
    \param r: la ráfaga que se quiere mover.
*/
void mueve_rafaga  (Rafaga r);

/**
    \brief Dibuja toda la ráfaga en la pantalla.
    \param r: Ráfaga que se quiere dibujar.
*/
void dibuja_rafaga (Rafaga r);

/**
    \brief Calcula cuántas balas hay en la ráfaga.
    \param r: Ráfaga de la que se quiere saber cuántas balas contiene.
    \return Número de balas que tiene la ráfaga.
*/
int longitud_rafaga (Rafaga r);

/**
    \brief Determina si existe colisión entre una ráfaga y un rectángulo
    \param r: Ráfaga que se quiere saber si colisiona.
    \param x: Coordenada horizontal de la esquina superior superior izquierda del rectángulo.
    \param y: Coordenada vertical de la esquina superior superior izquierda del rectángulo.
    \param w: Ancho del rectángulo.
    \param h: Alto del rectángulo.
    \return 1 si hay choque.
    \return 0 si no hay choque.
*/
int colision_rafaga( Rafaga r, double x, double y, int w, int h );


#endif
