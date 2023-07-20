#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int n_op;
    printf("Introduce numero de operaciones a realizar\n");
    scanf("%d",&n:op);

    for (int i=0; i<n_op; i++){
            int op1, op2;
            printf("Introduce operando 1\n");
            scanf("%d",&op1);
            printf("Introduce operando" 2\n");
            scanf("%d",&op2);
            int s = suma(op1,op2);
            int r = resta(op1,op2);
            printf("suma =%d, resta = %d\n",s,r);
    }

    printf("Fin");
}
