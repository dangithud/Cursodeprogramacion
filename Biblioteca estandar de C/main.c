#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <time.h>

int main()
{
    //stype.h: indigit
    printf("%d\n",isdigit('r'));
    //math.h: sqrt
    printf("%.2f\n",sqrt(7));
    //limits.h: INT_MAX
    printf("%d\n",INT_MAX);
    //stdlib.h: rand
    srand(time(NULL));
    printf("%d\n",rand() % 11);
    //string.h: strlen
    printf("%d\n",strlen("cadena de prueba"));
    //time.h: time, difftime
    time_t comienza,final;
    comienza = time ( NULL );
    for (int i=0; i<100000; i++){
            printf("-");
    }
    final = time ( NULL );
    printf("%f\n", difftime(comienza,final));

}
