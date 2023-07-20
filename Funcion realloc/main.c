#include <stdio.h>
#include <stdlib.h>

int main()
{
    //malloc
    int *vector, n;
    printf("Introduce el numero de elementos del vector\n");
    scanf("%d",&n);

    vector = malloc(n*sizeof(int));

    if (vector == NULL){
            printf("Error al intentar reservar la memoria\n");
    }
    else{
            for(int i=0; i<n; i++){
                printf("Elemento en la posicion %d es %d",i,vector[i]);
            }
    }
}
