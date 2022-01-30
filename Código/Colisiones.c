#include "Colisiones.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int	dentro_rectangulo(	double	x,	double	y,	int	w,	int	h,	double	px,	double	py	){
    if ( px >= x && px <= x + w && py >= y && py <= y + h ){
        return 1;
    } else {
        return 0;
    }
}

double	distancia_punto_punto(	double	x1,	double	y1,	double	x2,	double	y2	) {
    return (sqrt ( pow( (x1 - x2), 2) +  pow( (y1 - y2), 2)));
}

int	solape_circunferencias( double	x1,	double	y1,	double	r1,	double	x2,	double	y2,	double	r2	){
    if (distancia_punto_punto(x1, y1, x2, y2) < (r1 + r2) ){
        return 1;
    } else {
        return 0;
    }
}

int	solape_rectangulos(	double	x1,	double	y1,	int	w1,	int	h1,	double	x2, double	y2,	int	w2,	int	h2	) {
  if ((x1 > x2 + w2) || (x1 + w1 < x2) || (y1 > y2 + h2) || (y1 + h1 < y2)) {
    return 0;
  } else {
    return 1;
  }
}


