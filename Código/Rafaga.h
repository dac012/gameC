#ifndef RAFAGA_H_INCLUDED
#define RAFAGA_H_INCLUDED
#include "Bala.h"

/**
    \file Rafaga.h
    \brief Fichero de cabecera para poder utilizar las funciones relacionadas con una r�faga.
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
    \brief Crea un nueva r�faga vac�a, sin balas, pero preparada para albergarlas.
    \return Una rafaga vac�a.
*/
Rafaga crea_rafaga ();

/**
    \brief Esta funci�n libera en memoria a la r�faga y a todas las balas que contenga.
    \param r Una r�faga, vac�a o no.
*/
void libera_rafaga (Rafaga r);

/**
    \brief Inserta una nueva bala cualquiera en nuestra r�faga.
    \param r Una r�faga cualquiera, vac�a o no.
    \param b Una bala para ser introducida en la r�faga.
*/
void inserta_rafaga (Rafaga r, Bala b);

/**
    \pre   M�nimo, la r�faga debe de contener una bala.
    \brief Mueve todas las balas de una r�faga que no est� vac�a.
    \param r Una r�faga cualquiera, pero que tenga m�nimo una bala.
*/
void mueve_rafaga (Rafaga r);

/**
    \pre   M�nimo, la r�faga debe de contener una bala.
    \brief Dibuja todas las balas de una r�faga que no est� vac�a.
    \param r Una r�faga cualquiera, pero que tenga m�nimo una bala.
*/
void dibuja_rafaga (Rafaga r);

/**
    \brief Cuenta el total de balas que tiene una r�faga.
    \param r Una r�faga cualquiera, vac�a o no.
    \return Devuelve el n�mero de balas que tiene una r�faga.
*/
int longitud_rafaga (Rafaga r);

/**
    \pre   M�nimo, la r�faga debe de contener una bala.
    \brief Detecta si alguna de las balas de una r�faga ha colisionado con un objeto rectangular o cuadrado, borrando dicha bala en caso afirmativo.
    \param r Una r�faga cualquiera, pero que tenga m�nimo una bala.
    \param x Coordenada horizontal del objeto.
    \param y Coordenada vertical del objeto.
    \param w Anchura del objeto.
    \param h Altura del objeto.
    \return Devuelve 1 en caso de que se produzca una colisi�n, si no, devuelve 0.
*/
int colision_rafaga (Rafaga r, double x, double y, double w, double h);

#endif // RAFAGA_H_INCLUDED
