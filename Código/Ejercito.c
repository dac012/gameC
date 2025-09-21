#include <stdlib.h>
#include <stdio.h>
#include "Rafaga.h"
#include "Pantalla.h"
#include "Enemigo.h"
#include "Ejercito.h"

struct EjercitoRep {
    Enemigo ejer[3];
    int n;
};

Ejercito crea_ejercito () {
    Ejercito ejer = malloc(sizeof(struct EjercitoRep));
    ejer -> n = 0;
    return ejer;
}

void libera_ejercito (Ejercito e) {
    for(int i=0; i<e -> n; i=i+1) {
        libera_enemigo(e -> ejer[i]);
    }
    free(e);
}

void inserta_ejercito (Ejercito e, double x, double y, double w, double h) {
    if(e -> n < 3) {
        e -> ejer[e -> n] = crea_enemigo(x, y, w, h);
        e -> n = e -> n + 1;
    }
}

void mueve_ejercito (Ejercito e) {
    for(int i=0; i<e -> n; i=i+1) {
        posicion_anterior_enemigo(e -> ejer[i]);
        mueve_enemigo(e -> ejer[i]);
    }
}

void dibuja_ejercito (Ejercito e) {
    for(int i=0; i<e -> n; i=i+1) {
        dibuja_enemigo(e -> ejer[i]);
    }
}

void posicion_anterior_ejercito (Ejercito e) {
    for(int i=0; i<e -> n; i=i+1) {
        posicion_anterior_enemigo(e -> ejer[i]);
    }
}

void posicion_aleatoria_ejercito (Ejercito e) {
    for(int i=0; i<e -> n; i=i+1) {
        posicion_aleatoria_enemigo(e -> ejer[i]);
    }
}

int colision_ejercito_heroe (Ejercito e, double x, double y, double w, double h) {
    for(int i=0; i<e -> n; i=i+1) {
        if(colision_enemigo_heroe(e -> ejer[i], x, y, w, h) == 1) {
            return 1;
        }
    }
    return 0;
}

int colision_ejercito_objeto (Ejercito e, double x, double y, double w, double h) {
    for(int i=0; i<e -> n; i=i+1) {
        if(colision_enemigo_objeto(e -> ejer[i], x, y, w, h) == 1) {
            return 1;
        }
    }
    return 0;
}

int colision_ejercito_rafaga (Ejercito e, Rafaga r) {
    for(int i=0; i<e -> n; i=i+1) {
        if(colision_enemigo_rafaga(e -> ejer[i], r) == 1) {
            return 1;
        }
    }
    return 0;
}

int colision_ejercito_pantalla(Ejercito e, int resolucionx, int resoluciony) {
    for(int i=0; i<e -> n; i=i+1) {
        if(colision_enemigo_pantalla(e -> ejer[i], resolucionx, resoluciony) == 1) {
            return 1;
        }
    }
    return 0;
}
