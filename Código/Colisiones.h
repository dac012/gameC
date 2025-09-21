#ifndef COLISIONES_H_INCLUDED
#define COLISIONES_H_INCLUDED

/**
    \file Colisiones.h
    \brief Fichero de cabecera para usar las funciones relacionadas con las colisiones.
*/

/**
    \brief Comprueba si un punto está dentro de un rectángulo.
    \param x Coordenada horizontal del rectángulo.
    \param y Coordenada vertical del rectángulo.
    \param w Anchura del rectángulo.
    \param h Altura del rectángulo.
    \param px Coordenada horizontal del punto.
    \param py Coordenada vertical del punto.
    \return Si el punto está dentro del rectángulo, devuelve 1, si no, devuelve 0.
*/
int dentro_rectangulo (int x, int y, int w, int h, int px, int py);

/**
    \brief Calcula la distancia entre dos puntos.
    \param x1 Coordenada horizontal del primer punto.
    \param y1 Coordenada vertical del primer punto.
    \param x2 Coordenada horizontal del segundo punto.
    \param y2 Coordenada vertical del segundo punto.
    \return Devuelve la distancia entre dos puntos.
*/
double distancia_punto_punto (double x1, double y1, double x2, double y2);

/**
    \brief Comprueba si dos circunferencias se solapan.
    \param x1 Coordenada horizontal de la primera circunferencia.
    \param y1 Coordenada vertical de la primera circunferencia.
    \param r1 Radio de la primera circunferencia.
    \param x2 Coordenada horizontal de la segunda circunferencia.
    \param y2 Coordenada vertical de la segunda circunferencia.
    \param r2 Radio de la segunda circunferencia.
    \return Devuelve 1 si las dos circunferencias se solapan, si no, devuelve 0.
*/
int solape_circunferencias (int x1, int y1, int r1, int x2, int y2, int r2);

/**
    \brief Comprueba si dos rectángulos se solapan.
    \param x1 Coordenada horizontal del primer rectángulo.
    \param y1 Coordenada vertical del primer rectángulo.
    \param w1 Anchura del primer rectángulo.
    \param h1 Altura del primer rectángulo.
    \param x2 Coordenada horizontal del segundo rectángulo.
    \param y2 Coordenada vertical del segundo rectángulo.
    \param w2 Anchura del segundo rectángulo.
    \param h2 Altura del segundo rectángulo.
    \return Devuelve 1 si los dos rectángulos se solapan, si no, devuelve 0.
*/
int solape_rectangulos (int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);

#endif // COLISIONES_H_INCLUDED
