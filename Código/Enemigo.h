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
    \brief Actualiza la anterior posici�n de un enemigo.
    \param e Enemigo que queremos utilizar.
*/
void posicion_anterior_enemigo (Enemigo e);

/**
    \brief Le da al enemigo una posici�n aleatoria.
    \param e Enemigo que queremos utilizar.
*/
void posicion_aleatoria_enemigo (Enemigo e);

/**
    \brief Detecta la colisi�n de un enemigo con un h�roe, si se produce manda al enemigo a una posici�n aleatoria.
    \param e Enemigo al cual queremos comprobar su colisi�n.
    \param x Coordenada horizontal del h�roe.
    \param y Coordenada vertical del h�roe.
    \param w Anchura del h�roe.
    \param h Altura del h�roe.
    \return Devuelve 1 si se produce una colisi�n, devuelve 0 si no se produce.
*/
int colision_enemigo_heroe (Enemigo e, int x, int y, int w, int h);

/**
    \brief Detecta la colisi�n de un enemigo con un objeto, modificando la direcci�n de su velocidad en funci�n de d�nde choque.
    \param e Enemigo al cual queremos comprobar su colisi�n.
    \param x Coordenada horizontal del objeto.
    \param y Coordenada vertical del objeto.
    \param w Anchura del objeto.
    \param h Altura del objeto.
    \return Devuelve 1 si se produce una colisi�n, devuelve 0 si no se produce.
*/
int colision_enemigo_objeto (Enemigo e, int x, int y, int w, int h);

/**
    \brief Detecta la colisi�n de un enemigo con una r�faga, haciendo aparecer al enemigo en una posici�n aleatoria.
    \param e Enemigo al cual queremos comprobar su colisi�n.
    \param r R�faga a la cual queremos comprobar su colisi�n.
    \return Devuelve 1 si se produce una colisi�n con alguna r�faga, devuelve 0 si no se produce.
*/
int colision_enemigo_rafaga (Enemigo e, Rafaga r);

/**
    \brief Detecta la colisi�n de un enemigo con la pantalla y lo devuelve a su posici�n anterior.
    \param e Enemigo al cual queremos comprobar su colisi�n.
    \param resolucionx Ancho de la pantalla, empezando desde (0,0).
    \param resoluciony Altura de la pantalla, empezando desde (0,0).
    \return Devuelve 1 si se produce una colisi�n con alguna r�faga, devuelve 0 si no se produce.
*/
int colision_enemigo_pantalla (Enemigo e, int resolucionx, int resoluciony);

#endif // ENEMIGO_H_INCLUDED
