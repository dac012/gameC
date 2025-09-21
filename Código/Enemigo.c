#include <stdio.h>
#include <stdlib.h>
#include "Pantalla.h"
#include "Colisiones.h"
#include "Rafaga.h"
#include "Enemigo.h"

struct EnemigoRep {
    int x;
    int y;
    int w;
    int h;
    int vx;
    int vy;
    Imagen apple;
    int ax;
    int ay;
};

Enemigo crea_enemigo (int x, int y, int w, int h) {
    Enemigo e = malloc(sizeof(struct EnemigoRep));
    e -> x = x;
    e -> y = y;
    e -> w = w;
    e -> h = h;
    e -> vx = 5;
    e -> vy = 5;
    e -> apple = Pantalla_ImagenLee("apple.bmp", 1);
    e -> ax = x;
    e -> ay = y;
    return e;
}

void libera_enemigo (Enemigo e) {
    Pantalla_ImagenLibera(e -> apple);
    free(e);
}

void mueve_enemigo (Enemigo e) {
    e -> x = e -> x + e -> vx;
    e -> y = e -> y + e -> vy;
}

void dibuja_enemigo (Enemigo e) {
    Pantalla_DibujaImagen(e -> apple, e -> x, e -> y, e -> w, e -> h);
}

void posicion_anterior_enemigo (Enemigo e) {
    e -> ax = e -> x;
    e -> ay = e -> y;
}

void posicion_aleatoria_enemigo (Enemigo e) {
    e -> x = rand() % (Pantalla_Anchura() - e -> w);
    e -> y = rand() % (Pantalla_Altura() - e -> h);
}

int colision_enemigo_heroe (Enemigo e, int x, int y, int w, int h) {
    if(solape_rectangulos(e -> x, e -> y, e -> w, e -> h, x, y, w, h) == 1) {
        posicion_aleatoria_enemigo(e);
        return 1;
    }
    return 0;
}

int colision_enemigo_objeto (Enemigo e, int x, int y, int w, int h) {
    if(solape_rectangulos(e -> x, e -> y, e -> w, e -> h, x, y, w, h) == 1) {
        e -> x = e -> ax;
        e -> y = e -> ay;
        if((e -> y >= 120 + 30 && e -> y + e -> h <= 345) || e -> y >= 345 + 30 || e -> y + e -> h <= 120) {
            e -> vy = e -> vy * -1;
        } else if ((e -> x >= 140 + 30 && e -> x + e -> w <= 640) || e -> x + e -> w <= 140 || e -> x >= 640 + 30) {
            e -> vx = e -> vx * -1;
        } else {
            e -> vx = e -> vx * -1;
            e -> vy = e -> vy * -1;
        }
        return 1;
    }
    return 0;
}

int colision_enemigo_rafaga (Enemigo e, Rafaga r) {
    if(colision_rafaga(r, e -> x, e -> y, e -> w , e -> h) == 1) {
        posicion_aleatoria_enemigo(e);
        return 1;
    } else {
        return 0;
    }
}

int colision_enemigo_pantalla (Enemigo e, int resolucionx, int resoluciony) {
    if(e -> x <= 0) {
        e -> x = e -> x + 5;
        e -> vx = e -> vx * -1;
        return 1;
    }
    if(e -> x + e -> w >= resolucionx) {
        e -> x = e -> x - 5;
        e -> vx = e -> vx * -1;
        return 1;
    }
    if(e -> y <= 0) {
        e -> y = e -> y + 5;
        e -> vy = e -> vy * -1;
        return 1;
    }
    if(e -> y + e -> h >= resoluciony) {
        e -> y = e -> y - 5;
        e -> vy = e -> vy * -1;
        return 1;
    }
    return 0;
}
