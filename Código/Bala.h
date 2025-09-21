#ifndef BALA_H_INCLUDED
#define BALA_H_INCLUDED

/**
   \file Bala.h
   \brief Fichero de cabecera para poder usar las funciones relacionadas con una Bala.
*/

/**
    \brief TDA Bala
*/
typedef struct BalaRep * Bala;

/**
    \brief Crea una bala en las coordenadas (x,y) a una velocidad determinada.
    \param x Coordenada horizontal de la bala.
    \param y Coordenada vertical de la bala.
    \param vx Velocidad horizontal de la bala.
    \param vy Velocidad vertical de la bala.
    \return Una nueva bala con coordenadas (x,y) a una velocidad determinada.
*/
Bala crea_bala (double x, double y, double vx, double vy);

/**
    \brief Libera la memoria asociada a una bala.
    \param b Bala cuya memoria queremos liberar.
*/
void libera_bala (Bala b);

/**
    \brief Mueve una bala un determinado espacio.
    \param b Bala que queremos mover.
*/
void mueve_bala (Bala b);

/**
    \brief Dibuja una bala en pantalla.
    \param b Bala que queremos dibujar en pantalla.
*/
void dibuja_bala (Bala b);

/**
    \brief Obtiene la coordenada horizontal de una bala.
    \param b Bala cuya coordenada horizontal queremos obtener.
    \return Coordenada horizontal de una bala.
*/
double get_x_bala (Bala b);

/**
    \brief Obtiene la coordenada vertical de una bala.
    \param b Bala cuya coordenada vertical queremos obtener.
    \return Coordenada vertical de una bala.
*/
double get_y_bala (Bala b);

/**
    \brief Detecta si se ha producido una colisión entre una bala y un objeto rectangular o cuadrado.
    \param b Bala que queremos utilizar para la comprobación.
    \param x Coordenada horizontal del objeto.
    \param y Coordenada vertical del objeto.
    \param w Ancho del objeto.
    \param h Alto del objeto.
    \return En el caso de que se produzca colisión, devuelve 1, si no es así, devuelve 0.
*/
int colision_bala (Bala b, double x, double y, double w, double h);

#endif // BALA_H_INCLUDED
