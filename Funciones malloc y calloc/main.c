#include <stdio.h>
#include <stdlib.h>

int main()
{
 int *ptr = malloc(5 * sizeof(int));
// ... trabajar con el bloque de memoria
int *temp_ptr = realloc(ptr, 10 * sizeof(int));
if (temp_ptr != NULL) {
    ptr = temp_ptr;
    // Continuar trabajando con el bloque de memoria redimensionado
} else {
    // Manejar el caso de fallo en la redimensión
}

}
