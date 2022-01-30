#ifndef __Ejercito_H__
#define	__Ejercito_H__
#include "Pantalla.h"
#include "Rafagas.h"
#include "Enemigos.h"

/**
    \file Ejercito.h
    \brief Este m�dulo incluye un TDA ej�rcito y varias funciones con las que trabajar con �l. Se apoya en el uso de Pantalla.h, Rafagas.h y Enemigos.h.
*/

/**
    \brief TDA Ejercito.
*/
typedef struct EjercitoRep * Ejercito;

/**
    \brief Crea un ej�rcito vac�o.
    \param img: Imagen de los enemigos del ej�rcito.
    \param max_enemigos: El n�mero m�ximo de enemigos que tiene el ej�rcito.
    \return Un ej�rcito vac�o.
*/
Ejercito crea_ejercito (Imagen img, int max_enemigos);

/**
    \brief Obtiene el n�mero de enemigos que tiene el ej�rcito actualmente (eliminados y no eliminados).
    \param e: Ej�rcito cuyo n�mero de enemigos se quiere saber.
    \return El n�mero de enemigos que tiene el ej�rcito (eliminados y no eliminados).
*/
int get_num_enemigos (Ejercito e);

/**
    \brief Libera la memoria asociada al ej�rcito (excepto la imagen de sus enemigos).
    \param e: Ej�rcito cuya memoria se quiere liberar.
    \param max_enemigos: El n�mero m�ximo de enemigos que tiene el ej�rcito.
*/
void libera_ejercito (Ejercito e, int max_enemigos);

/**
    \brief Inserta un enemigo en el ej�rcito.
    \param e: Ej�rcito donde se quiere insertar el enemigo.
    \param x: Coordenada horizontal de la esquina superior izquierda del enemigo.
    \param y: Coordenada vertical de la esquina superior izquierda del enemigo.
    \param w: Ancho del enemigo.
    \param h: Alto del enemigo.
    \param vx: Velocidad en el eje horizontal del enemigo.
    \param vy: Velocidad en el eje vertical del enemigo.
    \param max_enemigos: El n�mero m�ximo de enemigos que tiene el ej�rcito.
*/
void inserta_enemigo (Ejercito e, double x, double y, int w, int h, double vx, double vy, int max_enemigos);

/**
    \brief Mueve todo el ej�rcito.
    \param e: Ej�rcito que se quiere mover.
*/
void mueve_ejercito (Ejercito e);

/**
    \brief Dibuja todo el ej�rcito
    \param e: Ej�rcito que se quiere dibujar.
*/
void dibuja_ejercito (Ejercito e);

/**
    \brief Detecta si ha habido colisi�n entre un enemigo del ej�rctito y un rect�ngulo y elimina al enemigo en cuesti�n.
    \param e: Ej�rcito del que se quiere saber si ha colisionado.
    \param x: Coordenada horizontal de la esquina superior izquierda del rect�ngulo.
    \param y: Coordenada vertical de la esquina superior izquierda del rect�ngulo.
    \param w: Ancho del rect�ngulo.
    \param h: Alto del rect�ngulo.
    \return 1 si ha habido colisi�n.
    \return 0 si no ha habido colisi�n.
*/
int colision_ejercito_objeto (Ejercito e, double x, double y, int w, int h);

/**
    \brief Detecta si ha habido colisi�n entre un enemigo del ej�rcito y una r�faga de balas, elimina al enemigo en cuesti�n y genera dos enemigos extra.
    \param e: Ej�rcito del que se quiere saber si ha habido colisi�n.
    \param r: R�faga de balas de la que se quiere saber si ha habido colisi�n.
    \param max_enemigos: N�mero m�ximo de enemigos que tiene el ej�rcito.
    \return 1 si ha habido colisi�n.
    \return 0 si no ha habido colisi�n.
*/
int colision_ejercito_rafaga (Ejercito e, Rafaga r, int max_enemigos);

/**
    \brief Hace rebotar a los enemigos del ej�rcito que se choquen con los bordes de la pantalla.
    \param e: Ej�rcito que contiene a los enemigos que se quieren hacer rebotar.
    \param ancho_pantalla: El ancho de la pantalla.
    \param alto_pantalla: El alto de la pantalla.
*/
void rebota_ejercito (Ejercito e, double ancho_pantalla, double alto_pantalla);

#endif
