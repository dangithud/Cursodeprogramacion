#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f;
    //Lectura
    /*f = fopen("prueba.txt","r");
    char *linea;

    while (feof(f)==0){
            fscanf(f,"%s",linea);
            printf("%s\n",linea);
    }*/
    //Escritura
    /*f = fopen("prueba.txt","w");
    char *cadena = "Esta es una cadena de prueba";
    fprintf(f,"%s\n",cadena);

    fclose(f);*/
    f = fopen("prueba.txt","a");
    char *cadena = "Esta es otra cadena de prueba";
    fprintf(f,"%s\n",cadena);

    fclose(f);


}
