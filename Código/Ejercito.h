#ifndef EJERCITO_H_INCLUDED
#define EJERCITO_H_INCLUDED

/**
    \file Ejercito.h
    \brief Fichero de cabecera para poder usar las funciones relacionadas con un ejército.
*/

/**
    TDA Ejercito.
*/
typedef struct EjercitoRep * Ejercito;

/**
    \brief Crea un ejército vacío, pero preparado para ser rellenado, puede tener hasta 3 enemigos.
    \return Devuelve un ejército vacío.
*/
Ejercito crea_ejercito();

/**
    \brief Libera un ejército y a sus respectivos enemigos, esté vacío o no.
    \param e Ejército que queremos liberar
*/
void libera_ejercito (Ejercito e);

/**
    \brief Inserta un nuevo enemigo en un ejército.
    \param x Coordenada horizontal del nuevo enemigo.
    \param y Coordenada vertical del nuevo enemigo.
    \param w Anchura del nuevo enemigo.
    \param h Altura del nuevo enemigo.
*/
void inserta_ejercito (Ejercito e, double x, double y, double w, double h);

/**
    \brief Mueve a todo un ejército.
    \param e El ejército que se quiere mover.
*/
void mueve_ejercito (Ejercito e);

/**
    \brief Dibuja a todo un ejército.
    \param e El ejército que se quiere dibujar.
*/
void dibuja_ejercito (Ejercito e);

/**
    \brief Actualiza la posición anterior de un ejército.
    \param e El ejército el cual queremos actualizar.
*/
void posicion_anterior_ejercito (Ejercito e);

/**
    \brief Le da un posición aleatoria a un ejército.
    \param e El ejército al cual queremos mover aleatoriamente a otra parte.
*/
void posicion_aleatoria_ejercito (Ejercito e);

/**
    \brief Detecta la colisión entre un ejército y un héroe, si algún enemigo se topa con el héroe, este es movido a otra parte aleatoria.
    \param e Ejército para el que queremos comprobar su colisión.
    \param x Coordenada horizontal del héroe.
    \param y Coordenada vertical del héroe.
    \param w Anchura del héroe.
    \param h Altura del héroe.
    \return Devuelve 1 si se produce una colisión, devuelve 0 si no es así.
*/
int colision_ejercito_heroe(Ejercito e, double x, double y, double w, double h);

/**
    \brief Detecta la colisión entre un ejército y un objeto, si algún enemigo se topa con el objeto, este invertirá su velocidad en función de su posición.
    \param e Ejército para el que queremos comprobar su colisión.
    \param x Coordenada horizontal del objeto.
    \param y Coordenada vertical del objeto.
    \param w Anchura del objeto.
    \param h Altura del objeto.
    \return Devuelve 1 si se produce una colisión, devuelve 0 si no es así.
*/
int colision_ejercito_objeto (Ejercito e, double x, double y, double w, double h);

/**
    \brief Detecta la colisión entre un ejército y una ráfaga, si algún enemigo se choca con una bala, este se moverá a otra parte aleatoria. La bala desaparece.
    \param e Ejército para el que queremos comprobar su colisión.
    \param e Ráfaga para la que queremos comprobar su colisión.
    \return Devuelve 1 si se produce una colisión, devuelve 0 si no es así.
*/
int colision_ejercito_rafaga (Ejercito e, Rafaga r);


/**
    \brief Detecta la colisión de un ejército con la pantalla, si un enemigo se choca contra la pantalla, rebotará en dirección contraria.
    \param e Ejército para el que queremos comprobar su colisión.
    \param resolucionx Anchura de la pantalla.
    \param resoluciony Altura de la pantalla.
    \return Devuelve 1 si se produce una colisión, devuelve 0 si no es así.
*/
int colision_ejercito_pantalla(Ejercito e, int resolucionx, int resoluciony);

#endif // EJERCITO_H_INCLUDED
