#include <stdio.h>
#include <stdlib.h>

int main()
{
    //int vector[10];

    int vector[10] = {0,1,2,3,4,5,6,7,8,9};

    //printf("%d\n",vector[3]);

    vector[9] = 100;
    vector[5] = 500;

    for(int i=0; i<10; i++){
        printf("%d\n",vector[i]);
    }
}
