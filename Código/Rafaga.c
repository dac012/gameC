#include <stdio.h>
#include <stdlib.h>
#include "Rafaga.h"
#include "Bala.h"

struct Nodo {
    Bala b;
    struct Nodo * sig;
};

struct RafagaRep {
    NodoPtr cabecera;
};

NodoPtr nuevo_nodo (Bala b) {
    NodoPtr n = malloc(sizeof(struct Nodo));
    n -> b = b;
    n -> sig = NULL;
    return n;
}

Rafaga crea_rafaga () {
    Rafaga r = malloc(sizeof(struct RafagaRep));
    r -> cabecera = nuevo_nodo(NULL);
    return r;
}

void libera_rafaga (Rafaga r) {
    NodoPtr borrar;
    while(r -> cabecera -> sig != NULL) {
        borrar = r -> cabecera -> sig;
        r -> cabecera -> sig = r -> cabecera -> sig -> sig;
        libera_bala(borrar -> b);
        free(borrar);
    }
    free(r -> cabecera);
    free(r);
}

void inserta_rafaga (Rafaga r, Bala b) {
    NodoPtr nuevo = nuevo_nodo(b);
    nuevo -> sig = r -> cabecera -> sig;
    r -> cabecera -> sig = nuevo;
}

void mueve_rafaga (Rafaga r) {
    NodoPtr aux = r -> cabecera;
    while(aux -> sig != NULL) {
        mueve_bala(aux -> sig -> b);
        if(get_y_bala(aux -> sig -> b) + 15 < 0) {
            NodoPtr borrar;
            borrar = aux -> sig;
            aux -> sig = aux -> sig -> sig;
            libera_bala(borrar -> b);
            free(borrar);
        } else {
            aux = aux -> sig;
        }
    }
}

void dibuja_rafaga (Rafaga r) {
    NodoPtr aux = r -> cabecera;
    while(aux -> sig != NULL) {
        dibuja_bala(aux -> sig -> b);
        aux = aux -> sig;
    }
}

int longitud_rafaga (Rafaga r) {
    NodoPtr aux = r -> cabecera;
    int contador = 0;
    while(aux -> sig != NULL) {
        contador = contador + 1;
        aux = aux -> sig;
    }
    return contador;
}

int colision_rafaga (Rafaga r, double x, double y, double w, double h) {
    NodoPtr aux = r -> cabecera;
    while(aux -> sig != NULL) {
        if(colision_bala(aux -> sig -> b, x, y , w, h) == 1) {
            NodoPtr borrar;
            borrar = aux -> sig;
            aux -> sig = aux -> sig -> sig;
            libera_bala(borrar -> b);
            free(borrar);
            return 1;
        }
        aux = aux -> sig;
    }
    return 0;
}
