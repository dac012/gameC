#include <stdlib.h>
#include <stdio.h>
#include "Pantalla.h"
#include "Colisiones.h"
#include "Bala.h"

struct BalaRep {
    double x;
    double y;
    double vx;
    double vy;
    Imagen ubuntu;
};

Bala crea_bala (double x, double y, double vx, double vy) {
    Bala b = malloc(sizeof(struct BalaRep));
    b -> x = x;
    b -> y = y;
    b -> vx = vx;
    b -> vy = vy;
    b -> ubuntu = Pantalla_ImagenLee("ubuntu.bmp", 1);
    return b;
}

void libera_bala (Bala b) {
    Pantalla_ImagenLibera(b -> ubuntu);
    free(b);
}

void mueve_bala (Bala b) {
    b -> x = b -> x + b -> vx;
    b -> y = b -> y + b -> vy;
}

void dibuja_bala (Bala b) {
    Pantalla_DibujaImagen(b -> ubuntu, b -> x, b -> y, 15, 15);
}

double get_x_bala (Bala b) {
    return b -> x;
}

double get_y_bala (Bala b) {
    return b -> y;
}

int colision_bala (Bala b, double x, double y, double w, double h) {
    if(solape_rectangulos(b -> x, b -> y, 15, 15, x, y, w, h) == 1) {
        return 1;
    } else {
        return 0;
    }
}
