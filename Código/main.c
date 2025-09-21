#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Pantalla.h"
#include "Colisiones.h"
#include "Bala.h"
#include "Rafaga.h"
#include "Enemigo.h"
#include "Ejercito.h"
#include "Heroe.h"

/**
    \file main.c
    \mainpage Este programa se trata de un videojuego, el cual, al iniciar, hace aparecer un menú por pantalla con tres opciones, "Jugar", "Ayuda" y "Salir". Dentro del juego controlaremos a nuestro héroe, Tux, el cual tendrá la habilidad de lanzar balas para luchar contra las manzanas de Apple, cuantas más elimine, más puntos gana. Cuando nos golpean tres veces, el juego termina, y, si hemos conseguido superar el récord de puntos, saldrá un mensaje por pantalla.
*/

struct BloqueRep {
    int x;
    int y;
    int w;
    int h;
};

/**
    \brief Representa un bloque.
*/
typedef struct BloqueRep Bloque;

/**
    \brief Dibuja el escenario entero.
    \param escenario El array con todos los bloques del escenario contenidos.
    \param n El número de bloques del escenario.
*/
void dibuja_escenario (Bloque escenario[], int n) {
    for(int i=0; i<n; i=i+1) {
        Pantalla_DibujaRectangulo(escenario[i].x, escenario[i].y, escenario[i].w, escenario[i].h);
    }
}

/**
    \brief Detecta la colisión de un objeto con el escenario.
    \param Un escenario en forma de array.
    \param n Número de elementos que tiene el array.
    \param x Coordenada horizontal del objeto.
    \param y Coordenada vertical del objeto.
    \param w Anchura del objeto.
    \param h Altura del objeto.
    \return Si se ha producido colisión, devuelve 1, si no, devuelve 0.
*/
int colision_escenario (Bloque escenario[], int n, int x, int y, int w, int h) {
    for(int i=0; i<n; i=i+1) {
        if(solape_rectangulos(escenario[i].x, escenario[i].y, escenario[i].w, escenario[i].h, x, y, w, h) == 1) {
            return 1;
        }
    }
    return 0;
}

/**
    \brief Ejecuta el menú de inicio del videojuego.
    \param rx Puntero a real que guarda la posición horizontal del ratón.
    \param ry Puntero a real que guarda la posición vertical del ratón.
    \return Si se hace click sobre "Jugar", devuelve 0, si se hace sobre "Ayuda", devuelve 1, si se se hace sobre "Salir", devuelve 2, si se produce un error devuelve -1.
*/
int menu (double * rx, double * ry) {
    char j[6] = "Jugar";
    char a[6] = "Ayuda";
    char s[6] = "Salir";
    Pantalla_DibujaRectangulo(-10, -10, 810, 490);
    Pantalla_DibujaRectangulo(170, 222, 55, 30);
    Pantalla_DibujaRectangulo(370, 222, 55, 30);
    Pantalla_DibujaRectangulo(570, 222, 55, 30);
    Pantalla_DibujaTexto(j, 175, 230);
    Pantalla_DibujaTexto(a, 375, 230);
    Pantalla_DibujaTexto(s, 575, 230);
    Pantalla_Actualiza();
    while(Pantalla_Activa()) {
        Pantalla_RatonCoordenadas(rx, ry);
        if(dentro_rectangulo(170, 222, 55, 30, *rx, *ry) && Pantalla_RatonBotonPulsado(SDL_BUTTON_LEFT) == 1) {
            return 0;
        }
        if(dentro_rectangulo(370, 222, 55, 30, *rx, *ry) && Pantalla_RatonBotonPulsado(SDL_BUTTON_LEFT) == 1) {
            return 1;
        }
        if(dentro_rectangulo(570, 222, 55, 30, *rx, *ry) && Pantalla_RatonBotonPulsado(SDL_BUTTON_LEFT) == 1) {
            return 2;
        }
    }
    return -1;
}

/**
    \brief Ejecuta el menú de ayuda del videojuego.
    \param rx Puntero a real que guarda la posición horizontal del ratón.
    \param ry Puntero a real que guarda la posición vertical del ratón.
    \return Si se pulsa en "Jugar", devuelve 0, si se produce un error, devuelve -1.
*/
int ayuda (double * rx, double * ry) {
    char o1[80] = "El objetivo del juego es sencillo, disparar a los enemigos que van saliendo por";
    char o2[73] = "pantalla e intentar acumular la mayor cantidad de puntos antes de morir.";
    char m1[77] = "Nuestro heroe se controla con las flechas de direccion del teclado y dispara";
    char m2[31] = "sus balas pulsando la letra A.";
    char j[6] = "Jugar";
    Pantalla_DibujaRectangulo(-10, -10, 810, 490);
    Pantalla_DibujaTexto(o1, 30, 200);
    Pantalla_DibujaTexto(o2, 30, 220);
    Pantalla_DibujaTexto(m1, 30, 250);
    Pantalla_DibujaTexto(m2, 30, 270);
    Pantalla_DibujaRectangulo(345, 350, 55, 30);
    Pantalla_DibujaTexto(j, 350, 357);
    Pantalla_Actualiza();
    while(Pantalla_Activa()) {
        Pantalla_RatonCoordenadas(rx, ry);
        if(dentro_rectangulo(345, 350, 55, 30, *rx, *ry) && Pantalla_RatonBotonPulsado(SDL_BUTTON_LEFT) == 1) {
            return 0;
        }
    }
    return -1;
}

/**
    \brief Ejecuta el juego, llamando a la función menu.
    \param rx Puntero a real que guarda la posición horizontal del ratón.
    \param ry Puntero a real que guarda la posición vertical del ratón.
    \return Devuelve 1 si se va a jugar, si no, devuelve 2, o -1 si se da un error.
*/
int jugar(double * rx, double * ry) {
    int boton = menu(rx, ry);
    if(boton == 1) {
        boton = ayuda(rx, ry);
    }
    return boton;
}

int main (int argc, char *argv[]) {

    /**
        \brief Hace aparecer la pantalla y se define el color de los trazos.
    */
    Pantalla_Crea("Pantalla", 800, 480);
    Pantalla_ColorTrazo(255, 0, 0, 255);

    /**
        \brief Todo lo relacionado con el menú, declaración de punteros que se usarán con el ratón y su liberación más tarde.
    */
    double * rx = malloc(sizeof(double));
    double * ry = malloc(sizeof(double));
    int boton = jugar(rx, ry);
    free(rx);
    free(ry);

    /**
        \brief Variable que usaremos más tarde para contar el número de iteraciones del bucle principal.
    */
    int contador = 0;

    /**
        \brief La variable terminado, sirve para indicar al bucle while principal que debe parar.
    */
    int terminado = 0;

    /**
        \brief Variables que guardan datos relacionados con la puntuación y la vida.
    */
    int vidas = 3;
    char muestrovidas[80];
    int puntuacion = 0;
    char muestropuntuacion[80];
    int mejorpuntuacion = 0;
    char muestromejorpuntuacion[80];

    /**
        \brief Imágenes utilizadas.
    */
    Imagen desktop = Pantalla_ImagenLee("desktop.bmp", 0);

    /**
        \brief Declaración del héroe.
    */
    Heroe he = crea_heroe(200, 200, 80, 80);

    /**
        \brief Declaración del ejército y la insercción del primer enemigo.
    */
    Ejercito e = crea_ejercito();
    inserta_ejercito(e, 0, 0, 50, 50);

    /**
        \brief Array de estructuras usado para guardar las caracterísicas del escenario y una variable auxiliar que indica su tamaño.
    */
    Bloque escenario[] = {{.x = 140, .y = 120, .w = 30, .h=30},{.x = 640, .y = 120, .w = 30, .h = 30},{.x = 140, .y = 345, .w = 30, .h = 30},{.x = 640, .y = 345, .w = 30, .h = 30}};
    int n = 4;

    /**
        \brief Declaración de nuestra ráfaga utilizada por el héroe.
    */
    Rafaga r = crea_rafaga();

    /**
        \brief Nuestra variable para tratar con ficheros.
    */
    FILE * fp = NULL;

    /**
        \brief Bucle principal, mientras la pantalla esté activa, no nos quedemos sin vidas y hayamos pulsado "Jugar" en el menú, este se mantendrá en ejecución.
    */
    while(Pantalla_Activa() && !terminado && boton == 0) {

        /**
            \brief Cada iteración suma uno a la variable contador, que sirve para spawnear nuevos enemigos en iteraciones concretas.
        */
        contador = contador + 1;
        if(contador == 1000) {
            inserta_ejercito(e, 0, 200, 50, 50);
        }
        if(contador == 2000) {
            inserta_ejercito(e, 0, 400, 50, 50);
        }

        /**
            \brief Movimiento del héroe por la pantalla controlado por las flechas. Choque con el escenario.
        */
        mueve_heroe(he);
        for(int i=0; i<n; i=i+1) {
            colision_heroe_objeto(he, escenario[i].x, escenario[i].y, escenario[i].w, escenario[i].h);
        }

        /**
            \brief Movimiento aleatorio del enemigo por la pantalla, rebotando en los bordes y el escenario.
        */
        mueve_ejercito(e);
        for(int i=0; i<n; i=i+1) {
            colision_ejercito_objeto(e, escenario[i].x, escenario[i].y, escenario[i].w, escenario[i].h);
            colision_ejercito_pantalla(e, Pantalla_Anchura(), Pantalla_Altura());
        }

        /**
            \brief Crea una bala al pulsar la tecla A y la mueve por la pantalla.
        */
        if(Pantalla_TeclaPulsada(SDL_SCANCODE_A) == 1) {
            inserta_rafaga(r, crea_bala((get_x_heroe(he) + get_x_heroe(he) + get_w_heroe(he) - 15) / 2, get_y_heroe(he), 0, -5));
        }

        /**
            \brief Mueve la ráfaga si existe.
        */
        if(longitud_rafaga(r) > 0) {
            mueve_rafaga(r);
        }

        /**
            \brief Si la bala se colisiona con el enemigo, este aparece en otro lado y la bala desaparece.
        */
        if(longitud_rafaga(r) > 0 && colision_ejercito_rafaga(e, r) == 1) {
            puntuacion = puntuacion + 1;
        }

        /**
            \brief Si el héroe y el enemigo se solapan, tienes una vida menos, en el caso que sea tu última vida, el juego termina.
        */
        if(colision_ejercito_heroe(e, get_x_heroe(he), get_y_heroe(he), get_w_heroe(he), get_h_heroe(he)) == 1 && vidas > 0) {
            vidas = vidas - 1;
        } else if (vidas == 0) {
            terminado = 1;
        }

        /**
            \brief Si un enemigo se choca con algo al final de los cálculos, lo vuelve a mover.
        */
        for(int i=0; i<n; i=i+1) {
            if(colision_ejercito_objeto(e, escenario[i].x, escenario[i].y, escenario[i].w, escenario[i].h) == 1) {
                i = 0;
            }
        }

        /**
            \brief Cadenas usadas para guardar el número de vidas y los puntos obtenidos para más tarde imprimirlos por pantalla.
        */
        sprintf(muestrovidas, "Total de vidas restantes: %d", vidas);
        sprintf(muestropuntuacion, "Total de puntos: %d", puntuacion);

        /**
            \brief Comandos pantalla que dibujan teniendo en cuenta todo lo anterior. Muestran el fondo, al héroe, al enemigo, el escenario...
        */
        Pantalla_DibujaRellenoFondo(255, 255, 255, 255);
        dibuja_escenario(escenario, 4);
        Pantalla_DibujaImagen(desktop, 0, 0, Pantalla_Anchura(), Pantalla_Altura());
        dibuja_heroe(he);
        dibuja_ejercito(e);

        /**
            \brief Si existe una ráfaga, la dibuja.
        */
        if(longitud_rafaga(r) > 0) {
            dibuja_rafaga(r);
        }

        /**
            \brief Más comandos pantalla, estos dibujan las vidas que se tienen y la puntuación total.
        */
        Pantalla_DibujaTexto(muestrovidas, 10, 10);
        Pantalla_DibujaTexto(muestropuntuacion, 10, 30);


        /**
            \brief En el caso de no tener vidas restantes, se da por hecho que el juego termina y se ejecuta el siguiente código que proyecta por pantalla si se ha obtenido un nuevo récord.
        */
        if(vidas == 0) {
            fp = fopen("Best Score.txt", "r");
            fscanf(fp, "%d", &mejorpuntuacion);
            fclose(fp);
            if(mejorpuntuacion < puntuacion) {
            fopen("Best Score.txt", "w");
            fprintf(fp, "%d", puntuacion);
            fclose(fp);
            sprintf(muestromejorpuntuacion, "Nuevo record: %d", puntuacion);
            Pantalla_DibujaRectangulo(-10, -10, Pantalla_Anchura() + 10, Pantalla_Altura() + 10);
            Pantalla_DibujaTexto(muestromejorpuntuacion, Pantalla_Anchura()/2 - 70, Pantalla_Altura()/2 - 20);
            Pantalla_Actualiza();
            Pantalla_Espera(5000);
            }
        }

        /**
            \brief Comandos finales de pantalla, después de estos, el bucle termina.
        */
        Pantalla_Actualiza();
        Pantalla_Espera(20);
    }

    /**
        \brief En el caso de existir una ráfaga, la libera.
    */
    libera_rafaga(r);

    /**
        \brief Libera al enemigo.
    */
    libera_ejercito(e);

    /**
        \brief Libera al heroe.
    */
    libera_heroe(he);

    /**
        \brief Liberamos imágenes.
    */
    Pantalla_ImagenLibera(desktop);

    /**
        \brief Libera la pantalla antes de terminar el programa.
    */
    Pantalla_Libera();
    return 0;
}
