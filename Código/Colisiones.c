#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Colisiones.h"

int dentro_rectangulo (int x, int y, int w, int h, int px, int py) {
    if(px >= x && px <= x+w && py >= y && py <= y + h) {
        return 1;
    } else {
        return 0;
    }
}

double distancia_punto_punto (double x1, double y1, double x2, double y2) {
    return sqrt(abs(pow(x2-x1,2)+pow(y2-y1,2)));
}

int solape_circunferencias (int x1, int y1, int r1, int x2, int y2, int r2) {
    if(distancia_punto_punto(x1,y1,x2,y2) < r1+r2) {
        return 1;
    } else {
        return 0;
    }
}

int solape_rectangulos (int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2) {
    if(x1>=x2+w2 || y1>=y2+h2 || x1+w1<=x2 || y1+w1<=y2) {
        return 0;
    } else {
        return 1;
    }
}
