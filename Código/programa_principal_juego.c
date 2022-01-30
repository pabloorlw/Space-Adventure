# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include ".\Pantalla.h"
# include ".\Rafagas.h"
# include ".\Ejercito.h"
# include ".\Personaje.h"

/**
    \brief El ancho de la pantalla.
*/
# define ancho_pantalla 1200

/**
    \brief El alto de la pantalla.
*/
# define alto_pantalla 800


/**
    \mainpage Videojuego "Space Adventure"

    El juego consiste en sobrevivir a la incesante lluvia de meteoritos y a los aliens que te acechan en la superficie de un planeta.
    Se te equipa con una pistola capaz de disparar ráfagas de balas láser que pueden destruir a los meteoritos.
    \author Pablo Tadeo Romero Orlowska

    \file programa_principal_juego.c
    \brief Código principal del videojuego.
*/

/**
    \brief Ejecuta el menú principal del juego.
    \param img_fondo_menu: La imagen del fondo del menú.
    \return 1 si se ha elegido la opción "Jugar".
    \return 2 si se ha elegido la opción "Ayuda".
    \return 3 si se ha elegido la opción "Salir".
*/
int menu (Imagen img_fondo_menu) {
    double pos_x_raton;
    double pos_y_raton;
    Pantalla_DibujaImagen (img_fondo_menu, 0, 0, ancho_pantalla, alto_pantalla);
    while (Pantalla_Activa()) {
        Pantalla_ColorTrazo (255, 255, 255, 255);
        Pantalla_DibujaRectangulo (550, 200, 200, 50);
        Pantalla_DibujaTexto ("SPACE ADVENTURE\0", 585, 217);
        Pantalla_DibujaRectangulo (625, 400, 50, 25);
        Pantalla_DibujaTexto ("Jugar\0", 630, 405);
        Pantalla_DibujaRectangulo (625, 450, 50, 25 );
        Pantalla_DibujaTexto ("Ayuda\0", 630, 455);
        Pantalla_DibujaRectangulo (625, 500, 50, 25);
        Pantalla_DibujaTexto ("Salir\0", 630, 505);
        if (Pantalla_RatonBotonPulsado (SDL_BUTTON_LEFT)) {
        Pantalla_RatonCoordenadas (&pos_x_raton, &pos_y_raton);
            if ((pos_x_raton >= 625) && (pos_x_raton <= 725) && (pos_y_raton >= 400) && (pos_y_raton <= 425)) {
                return 1;
            }
            if ((pos_x_raton >= 625) && (pos_x_raton <= 725) && (pos_y_raton >= 450) && (pos_y_raton <= 475)) {
                return 2;
            }
            if ((pos_x_raton >= 625) && (pos_x_raton <= 725) && (pos_y_raton >= 500) && (pos_y_raton <= 525)) {
                return 3;
            }
        }
        Pantalla_Actualiza();
    }
    return 0;
}

/**
    \brief Ejecuta el menú Ayuda.
    \param img_ayuda: La imagen que saldrá como ayuda.
*/

void ayuda (Imagen img_ayuda) {
    while (Pantalla_Activa () && !Pantalla_TeclaPulsada(SDL_SCANCODE_ESCAPE)) {
        Pantalla_DibujaImagen (img_ayuda, 0, 0, ancho_pantalla, alto_pantalla);
        Pantalla_Actualiza();
        Pantalla_DibujaRellenoFondo(0, 0, 0, 0);
    }
}

/**
    \brief Gestiona el desarrollo de la partida y los menús.
    \param img_fondo_menu: La imagen del fondo del menú.
    \param img_ayuda: La imagen que saldrá como ayuda.
    \param img_astronauta: La imagen del personaje principal.
    \param img_bala: La imagen de la bala.
    \param img_meteorito: La imagen de un tipo de enemigo.
    \param img_alien: La imagen de otro tipo de enemigo.
    \param img_fondo_partida: La imagen que servirá como fondo de la partida.
*/
void desarrollo_partida (Imagen img_fondo_menu, Imagen img_ayuda, Imagen img_astronauta, Imagen img_bala, Imagen img_meteorito, Imagen img_alien, Imagen img_fondo_partida) {
    Pantalla_Crea ("Juego", ancho_pantalla, alto_pantalla);
    Pantalla_ColorRelleno (0, 0, 0, 0);
    int salir = 0;
    int opcion_menu;

    while (Pantalla_Activa() && !salir) {
        opcion_menu = menu(img_fondo_menu);
        if (opcion_menu == 1) {
            int record_anterior = 0;                                                                    // Variable que servirá para comparar el record anterior con los puntos de la partida actual
            FILE * fp = NULL;
            fp = fopen ("record_puntuacion.txt", "a+");
            int res = fscanf (fp, "%d", &record_anterior);
            if (res != 0) {                                                                             // Si el fichero no contiene nada, almacenamos como record_anterior = 0
                fprintf (fp, "0\n");
            }
            fclose (fp);

            double x_personaje = 575;                                                                    // Posición horizontal inicial del personaje
            double y_personaje = 780;                                                                    // Posiçión vertical inicial  del personaje
            int w_personaje = 50;                                                                        // Ancho del personaje
            int h_personaje = 80;                                                                        // Alto del personaje
            double vx_personaje = 5;                                                                     // Velocidad horizontal del personaje
            int w_bala = 10;                                                                             // Ancho de la bala
            int h_bala = 40;                                                                             // Alto de la bala
            double vx_bala = 0;                                                                          // Velocidad horizontal de la bala
            double vy_bala = -5;                                                                         // Velocidad vertical de la bala
            double vx_meteoritos = 0;                                                                    // Velocidad horizontal de los meteoritos
            double vy_meteoritos = 5;                                                                    // Velocidad vertical de los meteoritos
            int w_meteoritos = 50;                                                                       // Ancho de los meteoritos
            int h_meteoritos = 100;                                                                      // Alto de los meteoritos
            double vx_aliens = 3;                                                                        // Velocidad horizontal de los aliens
            double vy_aliens = 0;                                                                        // Velocidad vertical de los aliens
            int w_aliens = 30;                                                                           // Ancho de los aliens
            int h_aliens = 50;                                                                           // Alto de los aliens
            int max_meteoritos = 1000;                                                                   // Número máximo de meteoritos que tiene nuestro ejército de meteoritos
            int max_aliens = 10;                                                                         // Número máximo de aliens que tiene nuestro ejército de aliens.

            Personaje p = crea_nuevo_personaje (x_personaje, y_personaje, w_personaje, h_personaje, vx_personaje, img_astronauta);
            Bala b = NULL;
            Rafaga r = crea_rafaga();
            Ejercito ejercito_meteoritos = crea_ejercito (img_meteorito, max_meteoritos);
            inserta_enemigo (ejercito_meteoritos, 0, 0, w_meteoritos, h_meteoritos, vx_meteoritos, vy_meteoritos, max_meteoritos);
            inserta_enemigo (ejercito_meteoritos, 1160, 0, w_meteoritos, h_meteoritos, vx_meteoritos, vy_meteoritos, max_meteoritos);
            Ejercito ejercito_aliens = crea_ejercito (img_alien, max_aliens);
            inserta_enemigo (ejercito_aliens, 0, 800 - h_aliens, w_aliens, h_aliens, vx_aliens, vy_aliens, max_aliens);

            int contador = 0;                                                                           // Variable que servirá para contar las iteracioens del bucle
            int puntos = 0;                                                                             // Variable que servirá para almacenar los puntos de la partida actual
            int contador_invulnerabilidad = 0;                                                          // Variable que usaremos para controlar la invulnerabilidad del personaje tras perder una vida.
            int terminado = 0;                                                                          // Variable que servirá para detener la animación
            int vidas = 10;                                                                             // Variable que almacenará la vida del jugador
            char marcador_puntos[20];
            char marcador_vidas[20];

            srand (time (NULL));

            // Bucle principal:

            while (Pantalla_Activa () && !terminado) {
                Pantalla_DibujaRellenoFondo(0, 0, 0, 0);
                Pantalla_DibujaImagen (img_fondo_partida, 0, 0, ancho_pantalla, alto_pantalla);
                Pantalla_ColorTrazo (255, 0, 0, 255);
                contador++;
                contador_invulnerabilidad--;

                // Movemos al personaje
                mueve_personaje (p, ancho_pantalla);
                salta_personaje (p, alto_pantalla);
                if (contador_invulnerabilidad > 0) {                                    // Cuando estemos en periodo de invulnerabilidad, hacemos que el personaje solo se dibuje cada 5
                    if (contador % 3 == 0) {                                            // iteraciones del bucle, simulando un parpadeo que nos indicará que recientemente ha perdido una vida
                        dibuja_personaje (p);
                    }
                } else {
                    dibuja_personaje (p);
                }

                if (contador % 50 == 0) {
                    inserta_enemigo (ejercito_meteoritos, rand() % (ancho_pantalla - w_meteoritos), 0, w_meteoritos, h_meteoritos, vx_meteoritos, vy_meteoritos, max_meteoritos);                               // 30 es el ancho del meteorito. Ponemos 1400 - 50 para que no se genere fuera de la pantalla
                }
                if (contador % 500 == 0) {
                    inserta_enemigo (ejercito_aliens, rand() % (ancho_pantalla - w_aliens), alto_pantalla - h_aliens , w_aliens, h_aliens, vx_aliens, vy_aliens, max_aliens);
                }
                mueve_ejercito (ejercito_meteoritos);
                mueve_ejercito (ejercito_aliens);
                rebota_ejercito (ejercito_aliens, ancho_pantalla, alto_pantalla);
                dibuja_ejercito (ejercito_aliens);
                dibuja_ejercito (ejercito_meteoritos);

                if (Pantalla_TeclaPulsada (SDL_SCANCODE_SPACE) && contador % 15 == 0)  {
                    b = crea_bala(get_x_personaje (p) + 20, get_y_personaje(p), w_bala, h_bala, vx_bala, vy_bala, img_bala);
                    inserta_bala_rafaga (r, b);
                }
                mueve_rafaga  (r);
                dibuja_rafaga (r);

                puntos = colision_ejercito_rafaga (ejercito_meteoritos, r, max_meteoritos) + puntos;
                if (contador == 5000) {
                    contador = 0;
                }

                if ((contador_invulnerabilidad < 0) && ((colision_ejercito_objeto (ejercito_meteoritos, get_x_personaje(p), get_y_personaje(p), get_w_personaje(p), get_h_personaje(p))) || ((colision_ejercito_objeto (ejercito_aliens, get_x_personaje(p), get_y_personaje(p), get_w_personaje(p), get_h_personaje(p)))))) {
                    vidas--;
                    contador_invulnerabilidad = 300;                                                    // El personaje no podrá perder más vidas durante las 300 primeras iteraciones del bucle tras perder una vida.
                    if (vidas == 0) {
                        terminado = 1;
                    }
                }

                sprintf (marcador_puntos, "Puntos: %d\0", puntos);
                Pantalla_DibujaTexto(marcador_puntos, 0, 760);                                          // Mostramos los puntos
                if (contador_invulnerabilidad > 0) {
                    sprintf (marcador_vidas, "INVULNERABILIDAD ACTIVADA\0");
                    Pantalla_DibujaTexto(marcador_vidas, 0, 780);                                       // Mostramos si estamos en el periodo de invulnerabilidad
                } else {
                    sprintf (marcador_vidas, "Vidas: %d\0", vidas);
                    Pantalla_DibujaTexto(marcador_vidas, 0, 780);                                       // Mostramos las vidas
                }

                Pantalla_Actualiza();
                Pantalla_Espera(5);

            }
            libera_personaje(p);
            libera_rafaga (r);
            libera_ejercito (ejercito_meteoritos, max_meteoritos);
            libera_ejercito (ejercito_aliens, max_aliens);
            if ((record_anterior < puntos)) {
                fopen ("record_puntuacion.txt", "w");
                fprintf (fp, "%d\n", puntos);
                fclose (fp);                                                          // Si obtenemos una puntuación mayor que la almacenada o no hay ningún dato almacenado en el fichero, entonces hacemos record
                Pantalla_DibujaRellenoFondo (0, 0, 0, 0);
                char NuevoRecord[50];
                sprintf (NuevoRecord, "Has conseguido un nuevo record: %d puntos\0", puntos);
                Pantalla_DibujaTexto (NuevoRecord, 400, 400);
                Pantalla_Actualiza();
                Pantalla_Espera (5000);
                Pantalla_DibujaRellenoFondo(0, 0, 0, 0);
            } else {
                Pantalla_DibujaRellenoFondo(0, 0, 0, 0);
                Pantalla_DibujaTexto ("Has Perdido\0", 550, 400);
                Pantalla_Actualiza();
                Pantalla_Espera (5000);
                Pantalla_DibujaRellenoFondo(0, 0, 0, 0);
              }
        }
        else if (opcion_menu == 2) {
            ayuda (img_ayuda);
        }
        else if (opcion_menu == 3) {
            salir = 1;
        }
    }
}


int main (int argc, char *argv[]) {
    Imagen img_fondo_menu = Pantalla_ImagenLee (".\\fondo_menu.bmp", 1);
    Imagen img_ayuda = Pantalla_ImagenLee (".\\ayuda.bmp", 1);
    Imagen img_astronauta = Pantalla_ImagenLee (".\\astronauta.bmp", 1);
    Imagen img_bala =  Pantalla_ImagenLee (".\\bala_laser_azul.bmp", 1);
    Imagen img_meteorito = Pantalla_ImagenLee (".\\meteorito.bmp", 1);
    Imagen img_alien = Pantalla_ImagenLee (".\\alien.bmp", 1);
    Imagen img_fondo_partida = Pantalla_ImagenLee (".\\fondoplaneta.bmp", 1);
    desarrollo_partida (img_fondo_menu, img_ayuda, img_astronauta, img_bala, img_meteorito, img_alien, img_fondo_partida);
    Pantalla_ImagenLibera (img_fondo_menu);
    Pantalla_ImagenLibera (img_ayuda);
    Pantalla_ImagenLibera (img_astronauta);
    Pantalla_ImagenLibera (img_bala);
    Pantalla_ImagenLibera (img_meteorito);
    Pantalla_ImagenLibera (img_alien);
    Pantalla_ImagenLibera (img_fondo_partida);
    Pantalla_Libera();
    return 0;
}


