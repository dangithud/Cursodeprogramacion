#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr = malloc(5 * sizeof(int));
if (ptr != NULL) {
    // Trabajar con el bloque de memoria
    for (int i = 0; i < 5; i++) {
        ptr[i] = i * 2;
    }

    // Liberar la memoria cuando ya no se necesita
    free(ptr);
} else {
    // Manejar el caso de error en la asignación de memoria
}

}
