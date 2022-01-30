#ifndef __Rafagas_H_
#define __Rafagas_H_
#include "Bala.h"

/**
    \file Rafagas.h
    \brief Este m�dulo incluye un TDA que representa una r�faga de balas y a�ade varias funciones para trabajar con ella. Se apoya en el uso de Bala.h.
*/


/**
    \brief TDA R�faga.
*/
typedef struct RafagaRep * Rafaga;

/**
    \brief Crea una r�faga de balas vac�a.
    \return Una r�faga de balas vac�a.
*/
Rafaga crea_rafaga ();

/**
    \brief Libera la memoria asociada a la r�faga.
*/
void libera_rafaga (Rafaga r);

/**
    \brief Inserta una bala en la r�faga.
    \param r: R�faga en la que se quiere insertar la bala.
    \param b: Bala que se quiere insertar en la r�faga.
*/
void inserta_bala_rafaga (Rafaga r,	Bala b);

/**
    \brief Mueve toda la r�faga por la pantalla.
    \param r: la r�faga que se quiere mover.
*/
void mueve_rafaga  (Rafaga r);

/**
    \brief Dibuja toda la r�faga en la pantalla.
    \param r: R�faga que se quiere dibujar.
*/
void dibuja_rafaga (Rafaga r);

/**
    \brief Calcula cu�ntas balas hay en la r�faga.
    \param r: R�faga de la que se quiere saber cu�ntas balas contiene.
    \return N�mero de balas que tiene la r�faga.
*/
int longitud_rafaga (Rafaga r);

/**
    \brief Determina si existe colisi�n entre una r�faga y un rect�ngulo
    \param r: R�faga que se quiere saber si colisiona.
    \param x: Coordenada horizontal de la esquina superior superior izquierda del rect�ngulo.
    \param y: Coordenada vertical de la esquina superior superior izquierda del rect�ngulo.
    \param w: Ancho del rect�ngulo.
    \param h: Alto del rect�ngulo.
    \return 1 si hay choque.
    \return 0 si no hay choque.
*/
int colision_rafaga( Rafaga r, double x, double y, int w, int h );


#endif
