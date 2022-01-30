#ifndef __Colisiones_H__
#define __Colisiones_H__

/**
    \file Colisiones.h
    \brief Este m�dulo incluye dos funciones que permiten determinar si existe solape entre figuras geom�tricas.
*/

/**
    \brief Determina si existe solape entre dos rect�ngulos.
    \param x1: Coordenada horizontal de la esquina superior izquierda del primer rect�ngulo.
    \param y1: Coordenada vertical de la esquina superior izquierda del primer rect�ngulo.
    \param w1: Anchura del primer rect�ngulo.
    \param h1: Altura del primer rect�ngulo.
    \param x2: Coordenada horizontal de la esquina superior izquierda del segundo rect�ngulo.
    \param y2: Coordenada vertical de la esquina superior izquierda del primer rect�ngulo.
    \param w2: Anchura del segundo rect�ngulo.
    \param h2: Altura del segundo rect�ngulo.
    \return 1 si hay solape.
    \return 0 si no hay solape.
*/

int	solape_rectangulos (double x1, double y1, int w1, int h1, double x2, double y2, int w2, int h2);

/**
    \brief Determina si existe solape entre dos circunferencias.
    \param x1: Coordenada horizontal del centro de la primera circunferencia.
    \param y1: Coordenada vertical del centro de la segunda circunferencia.
    \param r1: Radio de la primera circunferencia..
    \param x2: Coordenada horizontal del centro de la segunda circunferencia.
    \param y2: Coordenada vertical del centro de la segunda circunferencia.
    \param r2: Radio de la segunda circunferencia.
    \return 1 si hay solape.
    \return 0 si no hay solape.
*/
int	solape_circunferencias (double x1, double y1, double r1, double	x2,	double y2, double r2);

#endif
