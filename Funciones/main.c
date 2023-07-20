#include <stdio.h>
#include <stdlib.h>

int suma(int num1, int num2);

int main()
{
    int num1,num2;
    printf("Introduce un numero\n");
    scanf("%d",&num1);
    printf("Introduce un numero\n");
    scanf("%d",&num2);
    int result = suma(num1,num2);
    printf("La suma es: %d\n",result);

}
int suma(int num1, int num2){

    int result = num1+num2;
    return result;
}
