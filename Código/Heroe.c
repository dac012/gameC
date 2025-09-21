#include <stdio.h>
#include <stdlib.h>
#include "Pantalla.h"
#include "Colisiones.h"
#include "Heroe.h"

struct HeroeRep {
    int x;
    int y;
    int w;
    int h;
    Imagen tux;
    int ax;
    int ay;
};

Heroe crea_heroe (int x, int y, int w, int h) {
    Heroe he = malloc(sizeof(struct HeroeRep));
    he -> x = x;
    he -> y = y;
    he -> w = w;
    he -> h = h;
    he -> tux = Pantalla_ImagenLee("tux.bmp", 1);
    he -> ax = x;
    he -> ay = y;
    return he;
}

void libera_heroe (Heroe he) {
    free(he -> tux);
    free(he);
}

void posicion_anterior_heroe (Heroe he) {
    he -> ax = he -> x;
    he -> ay = he -> y;
}

void mueve_heroe (Heroe he) {
    posicion_anterior_heroe(he);
    if(Pantalla_TeclaPulsada(SDL_SCANCODE_RIGHT) && he -> x + he -> w < Pantalla_Anchura() - 1) {
        he -> x = he -> x + 5;
    }
    if(Pantalla_TeclaPulsada(SDL_SCANCODE_LEFT) && he -> x > 0) {
        he -> x = he -> x - 5;
    }
    if(Pantalla_TeclaPulsada(SDL_SCANCODE_UP) && he -> y > 0) {
        he -> y = he -> y - 5;
    }
    if(Pantalla_TeclaPulsada(SDL_SCANCODE_DOWN) && he -> y + he -> h <= Pantalla_Altura() - 1) {
        he -> y = he -> y + 5;
    }
}

void dibuja_heroe (Heroe he) {
    Pantalla_DibujaImagen(he -> tux, he -> x, he -> y, he -> w, he -> h);
}

int colision_heroe_objeto (Heroe he, int x, int y, int w, int h) {
    if(solape_rectangulos(he -> x, he -> y, he -> w, he -> h, x, y, w, h)) {
        he -> x = he -> ax;
        he -> y = he -> ay;
        return 1;
    }
    return 0;
}

int get_x_heroe (Heroe he) {
    return he -> x;
}

int get_y_heroe (Heroe he) {
    return he -> y;
}

int get_w_heroe (Heroe he) {
    return he -> h;
}

int get_h_heroe (Heroe he) {
    return he -> h;
}
