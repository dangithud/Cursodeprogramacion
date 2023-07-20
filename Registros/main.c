#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct mi_registro{
        int dato_entero;
        float dato_float;
        float dato_cadena[30];
        int dato_vector[10];
    };

    struct mi_registro variable;

    variable.dato_entero = 20;
    variable.dato_float = 5.5;
    strcpy(variable.dato_cadena,"nueva cadena");
    variable.dato_vector[0] = 4;

    printf("El dato de tipo float de mi registro es: %f", variable.dato_float);

    struct mi_registro vector[10];

    vector[0].dato_entero = 7;
    printf("El dato de tipo entero del primer elemento del vector es: &d", vector[0].dato_entero);
}
