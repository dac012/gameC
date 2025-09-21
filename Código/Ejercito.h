#ifndef EJERCITO_H_INCLUDED
#define EJERCITO_H_INCLUDED

/**
    \file Ejercito.h
    \brief Fichero de cabecera para poder usar las funciones relacionadas con un ej�rcito.
*/

/**
    TDA Ejercito.
*/
typedef struct EjercitoRep * Ejercito;

/**
    \brief Crea un ej�rcito vac�o, pero preparado para ser rellenado, puede tener hasta 3 enemigos.
    \return Devuelve un ej�rcito vac�o.
*/
Ejercito crea_ejercito();

/**
    \brief Libera un ej�rcito y a sus respectivos enemigos, est� vac�o o no.
    \param e Ej�rcito que queremos liberar
*/
void libera_ejercito (Ejercito e);

/**
    \brief Inserta un nuevo enemigo en un ej�rcito.
    \param x Coordenada horizontal del nuevo enemigo.
    \param y Coordenada vertical del nuevo enemigo.
    \param w Anchura del nuevo enemigo.
    \param h Altura del nuevo enemigo.
*/
void inserta_ejercito (Ejercito e, double x, double y, double w, double h);

/**
    \brief Mueve a todo un ej�rcito.
    \param e El ej�rcito que se quiere mover.
*/
void mueve_ejercito (Ejercito e);

/**
    \brief Dibuja a todo un ej�rcito.
    \param e El ej�rcito que se quiere dibujar.
*/
void dibuja_ejercito (Ejercito e);

/**
    \brief Actualiza la posici�n anterior de un ej�rcito.
    \param e El ej�rcito el cual queremos actualizar.
*/
void posicion_anterior_ejercito (Ejercito e);

/**
    \brief Le da un posici�n aleatoria a un ej�rcito.
    \param e El ej�rcito al cual queremos mover aleatoriamente a otra parte.
*/
void posicion_aleatoria_ejercito (Ejercito e);

/**
    \brief Detecta la colisi�n entre un ej�rcito y un h�roe, si alg�n enemigo se topa con el h�roe, este es movido a otra parte aleatoria.
    \param e Ej�rcito para el que queremos comprobar su colisi�n.
    \param x Coordenada horizontal del h�roe.
    \param y Coordenada vertical del h�roe.
    \param w Anchura del h�roe.
    \param h Altura del h�roe.
    \return Devuelve 1 si se produce una colisi�n, devuelve 0 si no es as�.
*/
int colision_ejercito_heroe(Ejercito e, double x, double y, double w, double h);

/**
    \brief Detecta la colisi�n entre un ej�rcito y un objeto, si alg�n enemigo se topa con el objeto, este invertir� su velocidad en funci�n de su posici�n.
    \param e Ej�rcito para el que queremos comprobar su colisi�n.
    \param x Coordenada horizontal del objeto.
    \param y Coordenada vertical del objeto.
    \param w Anchura del objeto.
    \param h Altura del objeto.
    \return Devuelve 1 si se produce una colisi�n, devuelve 0 si no es as�.
*/
int colision_ejercito_objeto (Ejercito e, double x, double y, double w, double h);

/**
    \brief Detecta la colisi�n entre un ej�rcito y una r�faga, si alg�n enemigo se choca con una bala, este se mover� a otra parte aleatoria. La bala desaparece.
    \param e Ej�rcito para el que queremos comprobar su colisi�n.
    \param e R�faga para la que queremos comprobar su colisi�n.
    \return Devuelve 1 si se produce una colisi�n, devuelve 0 si no es as�.
*/
int colision_ejercito_rafaga (Ejercito e, Rafaga r);


/**
    \brief Detecta la colisi�n de un ej�rcito con la pantalla, si un enemigo se choca contra la pantalla, rebotar� en direcci�n contraria.
    \param e Ej�rcito para el que queremos comprobar su colisi�n.
    \param resolucionx Anchura de la pantalla.
    \param resoluciony Altura de la pantalla.
    \return Devuelve 1 si se produce una colisi�n, devuelve 0 si no es as�.
*/
int colision_ejercito_pantalla(Ejercito e, int resolucionx, int resoluciony);

#endif // EJERCITO_H_INCLUDED
