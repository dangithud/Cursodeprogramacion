#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct tipo1{
        int entero;
        char caracter1;
    };

    struct tipo2{
        float real1;
        struct tipo1 variable1;
    };

    struct tipo2 variable2 = {5.5,{7,'c'}};

    printf("%d",variable2.variable1.entero1);


}
