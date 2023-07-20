#include <stdio.h>
#include <stdlib.h>

int main()
{
    //sizeof
    int n_int = sizeof(int);
    int n_char = sizeof(char);
    int n_long = sizeof(long);

    struct estructura{
        int entero;
        char caracteres[10];
    };

    int n_struct = sizeof(struct estructura);
    float vector[5];
    int n_vector = sizeof(vector);

    printf("Tamayo de 1 entero = %d\n", n_int);
    printf("Tamayo de 1 char = %d\n", n_char);
    printf("Tamayo de 1 long = %d\n", n_long);
    printf("Tamayo de la estructura = %d\n", n_struct);
    printf("Tamayo del vector = %d\n", n_vector);
}
