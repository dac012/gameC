#ifndef HEROE_H_INCLUDED
#define HEROE_H_INCLUDED

/**
    \file Heroe.h
    \brief Fichero de cabecera para poder usar las funciones relacionadas con un héroe.
*/

/**
    \brief TDA Heroe
*/
typedef struct HeroeRep * Heroe;

/**
    \brief Crea un heroe en las coordenadas (x,y) con una anchura w y una altura h.
    \param x Coordenada horizontal del héroe.
    \param y Coordenada vertical del héroe.
    \param w Anchura del héroe.
    \param Altura del héroe.
    \return Un héroe en una posición y un tamaño determinados.
*/
Heroe crea_heroe (int x, int y, int w, int h);

/**
    \brief Libera la memoria asociada a un héroe.
    \param he Héroe del cual queremos liberar su memoria.
*/
void libera_heroe (Heroe he);

/**
    \brief Actualiza la posición anterior del héroe.
    \param he Héroe que queremos actualizar.
*/
void posicion_anterior_heroe (Heroe he);

/**
    \brief Mueve un héroe.
    \param he Héroe que queremos mover.
*/
void mueve_heroe (Heroe he);

/**
    \brief Dibuja un héroe.
    \param he Héroe que queremos dibujar.
*/
void dibuja_heroe (Heroe he);

/**
    \brief Detecta la colisión del héroe con un objeto.
    \param he Héroe al que queremos comprobrar su colisión.
    \param x Coordenada horizontal del objeto.
    \param y Coordenada vertical del objeto.
    \param w Anchura del objeto.
    \param h Altura del objeto.
    \return Devuelve 1 si se produce una colisión, devuelve 0 si no.
*/
int colision_heroe_objeto (Heroe he, int x, int y, int w, int h);

/**
    \brief Obtiene la coordenada horizontal de un héroe.
    \param he Héroe del cual queremos su coordenada horizontal.
    \return La coordenada horizontal del héroe.
*/
int get_x_heroe (Heroe he);

/**
    \brief Obtiene la coordenada vertical de un héroe.
    \param he Héroe del cual queremos su coordenada vertical.
    \return La coordenada vertical del héroe.
*/
int get_y_heroe (Heroe he);

/**
    \brief Obtiene la anchura de un héroe.
    \param he Héroe del cual queremos su anchura.
    \return La anchura del héroe.
*/
int get_w_heroe (Heroe he);

/**
    \brief Obtiene la altura de un héroe.
    \param he Héroe del cual queremos su altura.
    \return La altura del héroe.
*/
int get_h_heroe (Heroe he);

#endif // HEROE_H_INCLUDED
