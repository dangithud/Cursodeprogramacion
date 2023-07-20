#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para obtener una carta aleatoria del mazo (valores del 2 al 11)
int obtener_carta() {
    return rand() % 10 + 2;
}

// Función para calcular la puntuación total de una mano
int calcular_puntuacion(int mano[], int num_cartas) {
    int puntuacion = 0;
    int num_ases = 0;

    for (int i = 0; i < num_cartas; i++) {
        puntuacion += mano[i];
        if (mano[i] == 11) {
            num_ases++;
        }
    }

    while (puntuacion > 21 && num_ases > 0) {
        puntuacion -= 10;
        num_ases--;
    }

    return puntuacion;
}

int main() {
    srand(time(NULL)); // Inicializar la semilla para los números aleatorios

    int mazo[52]; // El mazo contiene cartas del 2 al 11 (2 a 10, J, Q, K)
    for (int i = 0; i < 52; i++) {
        mazo[i] = obtener_carta();
    }

    int mano_jugador[10]; // Array para almacenar las cartas del jugador
    int num_cartas_jugador = 0;
    int mano_crupier[10]; // Array para almacenar las cartas del crupier
    int num_cartas_crupier = 0;

    // Inicializar el juego repartiendo dos cartas al jugador y al crupier
    mano_jugador[num_cartas_jugador++] = mazo[rand() % 52];
    mano_jugador[num_cartas_jugador++] = mazo[rand() % 52];
    mano_crupier[num_cartas_crupier++] = mazo[rand() % 52];
    mano_crupier[num_cartas_crupier++] = mazo[rand() % 52];

    printf("Bienvenido a Blackjack!\n\n");

    // Mostrar las cartas del jugador
    printf("Tu mano: ");
    for (int i = 0; i < num_cartas_jugador; i++) {
        printf("%d ", mano_jugador[i]);
    }
    printf("\n");

    // Mostrar una de las cartas del crupier
    printf("Carta del crupier: %d\n\n", mano_crupier[0]);

    // Juego del jugador
    while (1) {
        int opcion;
        printf("¿Quieres pedir otra carta (1) o plantarte (0)? ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            mano_jugador[num_cartas_jugador++] = mazo[rand() % 52];

            printf("Tu mano: ");
            for (int i = 0; i < num_cartas_jugador; i++) {
                printf("%d ", mano_jugador[i]);
            }
            printf("\n");

            if (calcular_puntuacion(mano_jugador, num_cartas_jugador) > 21) {
                printf("¡Te has pasado de 21! Has perdido.\n");
                return 0;
            }
        } else {
            break;
        }
    }

    // Juego del crupier
    printf("\nTurno del crupier:\n");
    printf("Mano del crupier: ");
    for (int i = 0; i < num_cartas_crupier; i++) {
        printf("%d ", mano_crupier[i]);
    }
    printf("\n");

    while (calcular_puntuacion(mano_crupier, num_cartas_crupier) < 17) {
        mano_crupier[num_cartas_crupier++] = mazo[rand() % 52];
        printf("Mano del crupier: ");
        for (int i = 0; i < num_cartas_crupier; i++) {
            printf("%d ", mano_crupier[i]);
        }
        printf("\n");
    }

    // Determinar el ganador
    int puntuacion_jugador = calcular_puntuacion(mano_jugador, num_cartas_jugador);
    int puntuacion_crupier = calcular_puntuacion(mano_crupier, num_cartas_crupier);

    printf("\nPuntuación del jugador: %d\n", puntuacion_jugador);
    printf("Puntuación del crupier: %d\n\n", puntuacion_crupier);

    if (puntuacion_jugador > puntuacion_crupier || puntuacion_crupier > 21) {
        printf("¡Ganaste!\n");
    } else if (puntuacion_jugador < puntuacion_crupier) {
        printf("El crupier gana.\n");
    } else {
        printf("Empate.\n");
    }

    return 0;
}
