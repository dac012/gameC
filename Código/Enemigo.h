#ifndef ENEMIGO_H_INCLUDED
#define ENEMIGO_H_INCLUDED
#include "Rafaga.h"

/**
    \file Enemigo.h
    \brief Fichero de cabecera para poder usar las funciones relacionadas con un enemigo.
*/

/**
    TDA Enemigo.
*/
typedef struct EnemigoRep * Enemigo;

/**
    \brief Crea un nuevo enemigo.
    \param x Coordenada horizontal del enemigo.
    \param y Coordenada vertical del enemigo.
    \param w Anchura del enemigo.
    \param h Altura del enemigo.
    \return Un enemigo con sus datos introducidos.
*/
Enemigo crea_enemigo (int x, int y, int w, int h);

/**
    \brief Libera la memoria asociada a un enemigo.
    \param e Enemigo cuya memoria queremos liberar.
*/
void libera_enemigo (Enemigo e);

/**
    \brief Mueve un enemigo.
    \param e Enemigo que queremos mover.
*/
void mueve_enemigo (Enemigo e);

/**
    \brief Dibuja un enemigo.
    \param e Enemigo que queremos dibujar.
*/
void dibuja_enemigo (Enemigo e);

/**
    \brief Actualiza la anterior posición de un enemigo.
    \param e Enemigo que queremos utilizar.
*/
void posicion_anterior_enemigo (Enemigo e);

/**
    \brief Le da al enemigo una posición aleatoria.
    \param e Enemigo que queremos utilizar.
*/
void posicion_aleatoria_enemigo (Enemigo e);

/**
    \brief Detecta la colisión de un enemigo con un héroe, si se produce manda al enemigo a una posición aleatoria.
    \param e Enemigo al cual queremos comprobar su colisión.
    \param x Coordenada horizontal del héroe.
    \param y Coordenada vertical del héroe.
    \param w Anchura del héroe.
    \param h Altura del héroe.
    \return Devuelve 1 si se produce una colisión, devuelve 0 si no se produce.
*/
int colision_enemigo_heroe (Enemigo e, int x, int y, int w, int h);

/**
    \brief Detecta la colisión de un enemigo con un objeto, modificando la dirección de su velocidad en función de dónde choque.
    \param e Enemigo al cual queremos comprobar su colisión.
    \param x Coordenada horizontal del objeto.
    \param y Coordenada vertical del objeto.
    \param w Anchura del objeto.
    \param h Altura del objeto.
    \return Devuelve 1 si se produce una colisión, devuelve 0 si no se produce.
*/
int colision_enemigo_objeto (Enemigo e, int x, int y, int w, int h);

/**
    \brief Detecta la colisión de un enemigo con una ráfaga, haciendo aparecer al enemigo en una posición aleatoria.
    \param e Enemigo al cual queremos comprobar su colisión.
    \param r Ráfaga a la cual queremos comprobar su colisión.
    \return Devuelve 1 si se produce una colisión con alguna ráfaga, devuelve 0 si no se produce.
*/
int colision_enemigo_rafaga (Enemigo e, Rafaga r);

/**
    \brief Detecta la colisión de un enemigo con la pantalla y lo devuelve a su posición anterior.
    \param e Enemigo al cual queremos comprobar su colisión.
    \param resolucionx Ancho de la pantalla, empezando desde (0,0).
    \param resoluciony Altura de la pantalla, empezando desde (0,0).
    \return Devuelve 1 si se produce una colisión con alguna ráfaga, devuelve 0 si no se produce.
*/
int colision_enemigo_pantalla (Enemigo e, int resolucionx, int resoluciony);

#endif // ENEMIGO_H_INCLUDED
