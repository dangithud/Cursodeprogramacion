#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main() {
	char op;
	char matriz[40][100][100],aux,a1,a2,a3,a4,a5;
	int letras[100],temporal;
	int menu,i,j,val=0,menuarea,posc=-1,vali=0,bandera=0,acum=0,k,l;
	char nombre[40],busq[40],mensaje[40],consultArea[40];
	char usuario[40],contra[40];
	i=0;
	j=0;
	int b=0;
	do{
        system("cls");
        printf("Ingrese Usuario\n");
        scanf("%s",&usuario);
        printf("Ingrese Contrasena\n");
        scanf("%s",&contra);
        if(strcmp(usuario,"admin")==0 && strcmp(contra,"admin")==0){
            printf("Bienvenidos!!\n");
            getch();
            b=1;
        }else{
            printf("Usuario y Contrasena Incorrectos!!\n");
            getch();
        }
     }
    while(b==0);
    system("cls");
	do{
		system("color 71");
		printf("\t\t\tMENU\n");
		printf("1.- Registrar datos del paciente\n");
		printf("2.- Registrar area de atencion y costo por paciente\n");
		printf("3.- Rectificar el area donde se encuentra el paciente\n");
		printf("4.- Reporte resumen hospitalario ordenados por edad\n");
		printf("5.- Reporte de pacientes\n");
		printf("6.- Reporte de paciente ordenado por area totalizando el costo\n");
		printf("7.- Salir\n");
		scanf("%d",&menu);
		switch(menu){
			case 1:
				val=1;
				printf("INGRESO DE DATOS DEL PACIENTE\n");
				printf("Ingresar cedula\n");
				scanf("%s",&matriz[i][j]);
				j++;
				fflush(stdin);
			    printf("Ingrese nombre\n");
   				gets(matriz[i][j]);
   				//strcpy(,nombre);
				j++;
				printf("Ingresar edad\n");
				scanf("%s",&matriz[i][j]);
				i++;
				break;
			case 2:
				fflush(stdin);
				if(val==1){
					printf("LISTA PACIENTES\n");
					printf("Cedula\tNombre\tEdad\n");
					for(k=0;k<i;k++){
						for(l=0;l<3;l++){

							printf("%s\t",matriz[k][l]);
						}
						printf("\n");
					}

					printf("\n\nEscoja el paciente para registrar area\n");
					printf("Ingresar cedula\n");
					scanf("%s",&busq);


					for(k=0;k<i;k++){
						fflush(stdin);
						if(strcmp(matriz[k][0],busq)==0){
							posc=k;
							vali=1;
						}
					}
					fflush(stdin);
					if(vali==1){
						do{

						printf("Escoja codigo de area\n");
						printf("1.- Emergencia\n");
						printf("2.- Traumatologia\n");
						printf("3.- Medicina general\n");
						printf("4.- Obstetricia\n");
						scanf("%d",&menuarea);

						if(menuarea>0 && menuarea<5){
							bandera=1;
							switch(menuarea){
								case 1:
										strcpy(matriz[posc][3],"1");										
										break;
								case 2:
										strcpy(matriz[posc][3],"2");										
										
										break;
								case 3:
										strcpy(matriz[posc][3],"3");										
										
										break;
								case 4:
										strcpy(matriz[posc][3],"4");										
										
										break;

							}
							printf("Ingresar costo\n");
							scanf("%s",&matriz[posc][4]);
						}
						else{
							printf("Codigo de area no existe\n");
						}

						}while(bandera!=1);
					}
					else{
						printf("Cedula no encontrada\n");
					}



				}
				else{
					printf("Primero debe ingresar pacientes\n");
				}
				break;
			case 3:
				fflush(stdin);
				if(val==1){

					printf("\n\nIngresar numero de cedula del paciente, para modificar area:\n");

					scanf("%s",&busq);


					for(k=0;k<i;k++){
						fflush(stdin);
						if(strcmp(matriz[k][0],busq)==0){
							posc=k;
							vali=1;
						}
					}
					fflush(stdin);

					if(vali==1){
						do{
							printf("Nombre Area\n");
							if(strcmp(matriz[posc][3],"1")==0){
								strcpy(mensaje,"Emergencia");
							}else if(strcmp(matriz[posc][3],"2")==0){
								strcpy(mensaje,"Traumatologia");
							} else if(strcmp(matriz[posc][3],"3")==0){
								strcpy(mensaje,"Medicina General");
							} else if(strcmp(matriz[posc][3],"4")==0){
								strcpy(mensaje,"Obstetricia");
							}
							printf("%s  %s  %s",matriz[posc][1],matriz[posc][3],mensaje);
							printf("Escoja el codigo de la nueva area:\n");
							printf("1.- Emergencia\n");
							printf("2.- Traumatologia\n");
							printf("3.- Medicina general\n");
							printf("4.- Obstetricia\n");

							scanf("%d",&menuarea);
							int confirm=0;

							printf("Confirma el cambio 1/0:\n");
							scanf("%d",&confirm);


							if(menuarea>0 && menuarea<5 && confirm==1){
								bandera=1;
								switch(menuarea){
								case 1:
										strcpy(matriz[posc][3],"1");										
										break;
								case 2:
										strcpy(matriz[posc][3],"2");										
										
										break;
								case 3:
										strcpy(matriz[posc][3],"3");										
										
										break;
								case 4:
										strcpy(matriz[posc][3],"4");										
										
										break;

								}
							}
						else{
							printf("Actualizacion incorrecta\n");
						}

						}while(bandera!=1);
					}
					else{
						printf("Cedula no encontrada\n");
					}



				}
				else{
					printf("Primero debe ingresar pacientes\n");
				}
				getch();
				break;
			case 4:
				fflush(stdin);
				int numero;
				printf("\n\n\nPacientes mayores de edad >= 21\n");
				printf("\nCedula Nombre Edad Area Hospital\n");
				for(k=0;k<i;k++){
					fflush(stdin);
					numero = atoi(matriz[k][2]);
					getch();
					if(numero>=21){
						if(matriz[k][3]=="1"){
								strcpy(mensaje,"Emergencia");
							}else if(matriz[k][3]=="2"){
								strcpy(mensaje,"Traumatologia");
							} else if(matriz[k][3]=="3"){
								strcpy(mensaje,"Medicina General");
							} else if(matriz[k][3]=="4"){
								strcpy(mensaje,"Obstetricia");
							}
							printf("%s  %s  %s  %s  %s",matriz[k][0],matriz[k][1],matriz[k][2],matriz[k][3],mensaje);

						}
					}

					printf("\n\nPacientes menores de edad < 21\n");
					printf("\nCedula Nombre Edad Area Hospital\n");
					for(k=0;k<i;k++){
						fflush(stdin);
						
						numero = atoi(matriz[k][2]);
						if(numero<21){
							if(matriz[k][3]=="1"){
								strcpy(mensaje,"Emergencia");
							}else if(matriz[k][3]=="2"){
								strcpy(mensaje,"Traumatologia");
							} else if(matriz[k][3]=="3"){
								strcpy(mensaje,"Medicina General");
							} else if(matriz[k][3]=="4"){
								strcpy(mensaje,"Obstetricia");
							}
							printf("%s  %s  %s  %s  %s",matriz[k][0],matriz[k][1],matriz[k][2],matriz[k][3],mensaje);

						}
					}

					getch();
				break;
			case 5:
				fflush(stdin);
				printf("Pacientes\n");
				printf("Cedula\tNombre\tEdad\tArea\n");
				for(k=0;k<i;k++){
					char letra1 =matriz[k][1];
					int a=letra1;
					letras[k]=a;
				}


				for(k=0;k<i;k++){
					for(l=0;l<i-1;l++){
						if (letras[k] > letras[k+1]){
							temporal = letras[k];
							letras[k] = letras[k+1];
							letras[k+1] = temporal;

							a1=matriz[40][k][0];
							matriz[40][k][0]=matriz[40][k+1][0];
							matriz[40][k+1][0]=a1;

							a2=matriz[40][k][1];
							matriz[40][k][1]=matriz[40][k+1][1];
							matriz[40][k+1][1]=a2;


							a3=matriz[40][k][2];
							matriz[40][k][2]=matriz[40][k+1][2];
							matriz[40][k+1][2]=a3;


							a4=matriz[40][k][3];
							matriz[40][k][3]=matriz[40][k+1][3];
							matriz[40][k+1][3]=a4;

							a5=matriz[40][k][4];
							matriz[40][k][4]=matriz[40][k+1][4];
							matriz[40][k+1][4]=a5;

						}
					}
				}
					for(k=0;k<i;k++){
						for(l=0;l<3;l++){
							
							if(strcmp(matriz[k][3],"1")==0){
								strcpy(mensaje,"Emergencia");								
							}else if(strcmp(matriz[k][3],"2")==0){
								strcpy(mensaje,"Traumatologia");	
								
							} else if(strcmp(matriz[k][3],"3")==0){
								strcpy(mensaje,"Medicina General");	
								
							} else if(strcmp(matriz[k][3],"4")==0){
								strcpy(mensaje,"Obstetricia");
								
							}
							printf("%s\t",matriz[k][l]);
						
						
						}
						printf("%s",mensaje);
						printf("\n");
					}
				getch();
				break;
			case 6:
				fflush(stdin);
				printf("\n\nEscoja el Area que desea consultar\n");
				printf("1.- Emergencia\n");
				printf("2.- Traumatologia\n");
				printf("3.- Medicina general\n");
				printf("4.- Obstetricia\n");
				scanf("%s",&consultArea);

				fflush(stdin);
				printf("Cedula Nombre Edad Costo\n");
				for(k=0;k<i;k++){

						if(strcmp(matriz[k][3],consultArea)==0){
							vali=1;
							printf("%s    %s    %s    %s",matriz[k][0],matriz[k][1],matriz[k][2],matriz[k][4]);
							
							
							numero = atoi(matriz[k][4]);
							acum +=numero;

						}
					}

				printf("\nTotal a pagar: %d \n"),acum;
				getch();

				break;
			case 7:
				printf("Saliendo del sistema\n");
				break;
			default:
				printf("ERROR: opcion no existe\n");
				break;
		}
		j=0;
		acum=0;
	}while(menu!=7);
    return 0;

}
