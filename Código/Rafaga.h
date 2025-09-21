#ifndef RAFAGA_H_INCLUDED
#define RAFAGA_H_INCLUDED
#include "Bala.h"

/**
    \file Rafaga.h
    \brief Fichero de cabecera para poder utilizar las funciones relacionadas con una ráfaga.
*/

/**
    TDA Simple Nodo.
*/
typedef struct Nodo * NodoPtr;

/**
    TDA Rafaga.
*/
typedef struct RafagaRep * Rafaga;

/**
    \brief Crea un nuevo nodo con una bala dentro.
    \param b Una bala para introducir en el nodo.
    \return Nos devuelve un nuevo nodo con una bala.
*/
NodoPtr nuevo_nodo (Bala b);

/**
    \brief Crea un nueva ráfaga vacía, sin balas, pero preparada para albergarlas.
    \return Una rafaga vacía.
*/
Rafaga crea_rafaga ();

/**
    \brief Esta función libera en memoria a la ráfaga y a todas las balas que contenga.
    \param r Una ráfaga, vacía o no.
*/
void libera_rafaga (Rafaga r);

/**
    \brief Inserta una nueva bala cualquiera en nuestra ráfaga.
    \param r Una ráfaga cualquiera, vacía o no.
    \param b Una bala para ser introducida en la ráfaga.
*/
void inserta_rafaga (Rafaga r, Bala b);

/**
    \pre   Mínimo, la ráfaga debe de contener una bala.
    \brief Mueve todas las balas de una ráfaga que no esté vacía.
    \param r Una ráfaga cualquiera, pero que tenga mínimo una bala.
*/
void mueve_rafaga (Rafaga r);

/**
    \pre   Mínimo, la ráfaga debe de contener una bala.
    \brief Dibuja todas las balas de una ráfaga que no esté vacía.
    \param r Una ráfaga cualquiera, pero que tenga mínimo una bala.
*/
void dibuja_rafaga (Rafaga r);

/**
    \brief Cuenta el total de balas que tiene una ráfaga.
    \param r Una ráfaga cualquiera, vacía o no.
    \return Devuelve el número de balas que tiene una ráfaga.
*/
int longitud_rafaga (Rafaga r);

/**
    \pre   Mínimo, la ráfaga debe de contener una bala.
    \brief Detecta si alguna de las balas de una ráfaga ha colisionado con un objeto rectangular o cuadrado, borrando dicha bala en caso afirmativo.
    \param r Una ráfaga cualquiera, pero que tenga mínimo una bala.
    \param x Coordenada horizontal del objeto.
    \param y Coordenada vertical del objeto.
    \param w Anchura del objeto.
    \param h Altura del objeto.
    \return Devuelve 1 en caso de que se produzca una colisión, si no, devuelve 0.
*/
int colision_rafaga (Rafaga r, double x, double y, double w, double h);

#endif // RAFAGA_H_INCLUDED
