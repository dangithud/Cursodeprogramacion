#include <stdio.h>
#include <stdlib.h>

#define PI 3.1416

int main()
{
    int radio;
    float resultado;
    printf("Introduce el radio del circulo");
    scanf("%d",&radio);
    resultado = radio*radio*PI;

    printf("El area del circulo es: %f",resultado);
}
