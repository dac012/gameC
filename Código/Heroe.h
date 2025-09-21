#ifndef HEROE_H_INCLUDED
#define HEROE_H_INCLUDED

/**
    \file Heroe.h
    \brief Fichero de cabecera para poder usar las funciones relacionadas con un h�roe.
*/

/**
    \brief TDA Heroe
*/
typedef struct HeroeRep * Heroe;

/**
    \brief Crea un heroe en las coordenadas (x,y) con una anchura w y una altura h.
    \param x Coordenada horizontal del h�roe.
    \param y Coordenada vertical del h�roe.
    \param w Anchura del h�roe.
    \param Altura del h�roe.
    \return Un h�roe en una posici�n y un tama�o determinados.
*/
Heroe crea_heroe (int x, int y, int w, int h);

/**
    \brief Libera la memoria asociada a un h�roe.
    \param he H�roe del cual queremos liberar su memoria.
*/
void libera_heroe (Heroe he);

/**
    \brief Actualiza la posici�n anterior del h�roe.
    \param he H�roe que queremos actualizar.
*/
void posicion_anterior_heroe (Heroe he);

/**
    \brief Mueve un h�roe.
    \param he H�roe que queremos mover.
*/
void mueve_heroe (Heroe he);

/**
    \brief Dibuja un h�roe.
    \param he H�roe que queremos dibujar.
*/
void dibuja_heroe (Heroe he);

/**
    \brief Detecta la colisi�n del h�roe con un objeto.
    \param he H�roe al que queremos comprobrar su colisi�n.
    \param x Coordenada horizontal del objeto.
    \param y Coordenada vertical del objeto.
    \param w Anchura del objeto.
    \param h Altura del objeto.
    \return Devuelve 1 si se produce una colisi�n, devuelve 0 si no.
*/
int colision_heroe_objeto (Heroe he, int x, int y, int w, int h);

/**
    \brief Obtiene la coordenada horizontal de un h�roe.
    \param he H�roe del cual queremos su coordenada horizontal.
    \return La coordenada horizontal del h�roe.
*/
int get_x_heroe (Heroe he);

/**
    \brief Obtiene la coordenada vertical de un h�roe.
    \param he H�roe del cual queremos su coordenada vertical.
    \return La coordenada vertical del h�roe.
*/
int get_y_heroe (Heroe he);

/**
    \brief Obtiene la anchura de un h�roe.
    \param he H�roe del cual queremos su anchura.
    \return La anchura del h�roe.
*/
int get_w_heroe (Heroe he);

/**
    \brief Obtiene la altura de un h�roe.
    \param he H�roe del cual queremos su altura.
    \return La altura del h�roe.
*/
int get_h_heroe (Heroe he);

#endif // HEROE_H_INCLUDED
