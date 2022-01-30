#ifndef __Enemigos_H__
#define __Enemigos_H__

/**
    \file Enemigos.h
    \brief Este módulo incluye un TDA que representa a un enemigo rectangular y varias funciones con las que trabajar con él.
*/


/**
    \brief TDA Enemigo
*/
typedef struct EnemigosRep * Enemigo;

/**
    \brief Crea un enemigo.
    \param x: Coordenada horizontal de la esquina superior izquierda del enemigo.
    \param y: Coordenada vertical de la esquina superior izquierda del enemigo.
    \param w: Ancho del enemigo.
    \param h: Alto del enemigo.
    \param vx: Velocidad en el eje horizontal del enemigo.
    \param vy: Velocidad en el eje vertical del enemigo.
    \return Un enemigo.
*/
Enemigo crea_enemigo (double x, double y, int w, int h, double vx, double vy);

/**
    \brief Mueve un enemigo por la pantalla.
    \param enem: Enemigo que se quiere mover.
*/
void mueve_enemigo (Enemigo enem);

/**
    \brief Elimina al enemigo.
    \param enem: enemigo que se quiere eliminar.
*/
void elimina_enemigo (Enemigo enem);

/**
    \brief Determina si el enemigo está eliminado.
    \param enem: Enemigo que se quiere saber si está eliminado.
    \return 1 si está eliminado.
    \return 0 si no está eliminado.
*/
int enemigo_eliminado (Enemigo enem);

/**
    \brief Libera la memoria asociada al enemigo.
    \param enem: Enemigo que se quiere liberar.
*/
void libera_enemigo (Enemigo enem);

/**
    \brief Recupera la coordenada horizontal de la esquina superior izquierda del enemigo.
    \param enem: Enemigo cuya coordenada se quiere recuperar.
    \return La coordenada horizontal de la esquina superior izquierda del enemigo.
*/
double get_x_enemigo (Enemigo enem);

/**
    \brief Recupera la coordenada vertical de la esquina superior izquierda del enemigo.
    \param enem: Enemigo cuya coordenada se quiere recuperar.
    \return La coordenada vertical de la esquina superior izquierda del enemigo.
*/
double get_y_enemigo (Enemigo enem);

/**
    \brief Recupera el ancho del enemigo.
    \param enem: Enemigo cuyo ancho se quiere recuperar.
    \return El ancho del enemigo.
*/
int get_w_enemigo (Enemigo enem);

/**
    \brief Recupera la altura del enemigo.
    \param enem: Enemigo cuya altura se quiere recuperar.
    \return La altura del enemigo.
*/
int get_h_enemigo (Enemigo enem);


/**
    \brief Recupera la velocidad horizontal del enemigo.
    \param enem: Enemigo cuya velocidad horizontal se quiere recuperar.
    \return La velocidad horizontal del enemigo.
*/
double get_vx_enemigo (Enemigo enem);

/**
    \brief Recupera la velocidad vertical del enemigo.
    \param enem: Enemigo cuya velocidad vertical se quiere recuperar.
    \return La velocidad vertical del enemigo.
*/
double get_vy_enemigo (Enemigo enem);

/**
    \brief Cambia la velocidad horizontal actual del enemigo.
    \param enem: Enemigo cuya velocidad horizontal se quiere cambiar.
    \param vx: Velocidad horizontal nueva que se le quiere asignar.
*/
void set_vx_enemigo (Enemigo enem, double vx);

/**
    \brief Cambia la velocidad vertical actual del enemigo.
    \param enem: Enemigo cuya velocidad vertical se quiere cambiar.
    \param vx: Velocidad vertical nueva que se le quiere asignar.
*/
void set_vy_enemigo (Enemigo enem, double vy);

/**
    \brief Cambia el ancho actual del enemigo.
    \param enem: Enemigo cuyo ancho se quiere cambiar.
    \param w: Ancho nuevo que se le quiere asignar.
*/
void set_w_enemigo (Enemigo enem, int w);

/**
    \brief Cambia el alto actual del enemigo.
    \param enem: Enemigo cuyo alto se quiere cambiar.
    \param h: Alto nuevo que se le quiere asignar.
*/
void set_h_enemigo (Enemigo enem, int h);

#endif
