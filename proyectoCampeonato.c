#include <stdio.h>
#include <conio.h>


struct equipo{
    int codigo;
    char nombre[100];
}e[10];


int i,j;
int matrizTablaP[10][8];
int partidoContador=0;
int matrizGoles[10][10];
int matrizP[90][5];


void membrete(){
	printf("+---------------------------------------------------------+\n");
    printf("¦                                                         ¦\n");
    printf("¦                                                         ¦\n");
    printf("¦             	  Universidad Udla Park                   ¦\n");
    printf("¦                                                         ¦\n");
    printf("¦             Fundamentos de la programacion I            ¦\n");
    printf("¦                                                         ¦\n");
    printf("¦    Integrantes:                                         ¦\n");
    printf("¦                 ¦ Daniel Ramírez Velasco                ¦\n");
    printf("¦                                                         ¦\n");
    printf("¦                                                         ¦\n");
    printf("+---------------------------------------------------------+\n");
	
}
void primeraCarga(int cant){
    int i,j;
    fflush(stdin);
    for(i=0;i<cant;i++){
    	e[i].codigo=i+1;
        printf("Ingrese nombre del equipo\n");
        gets(e[i].nombre);        
    }
}

int validarEquipo(int cod, int cant){
	int val=0;
	int i,j;
	for(i=0;i<cant;i++){
		if(e[i].codigo==cod){
			val=1;
			break;
		}
	}	
	return val;
}

int validarPart(int cant, int c1, int c2){
	
	int val=0;
	for(i=0;i<cant;i++){
		if((c1==matrizP[i][1] && c2==matrizP[i][2]) || (c2==matrizP[i][1] && c1==matrizP[i][2])) {
			val=1;
			break;
		}
	}
	return val;
}

int validarPartidobyCodigo(int cant, int codigo){
	
	int val=-1;
	for(i=0;i<cant;i++){
		if(matrizP[i][0]==codigo){
			val=i;
			break;
		}
	}
	return val;
}

void actualizarMatrizGoles(int c1,int c2,int g1,int g2){
	matrizGoles[c1-1][c2-1]=g1;
	matrizGoles[c2-1][c1-1]=g2;
}


void tablaPosiciones(int c1,int c2,int g1,int g2){
	matrizTablaP[c1-1][1]++;	
	if(g1>g2){
		matrizTablaP[c1-1][0]+=3;		
		matrizTablaP[c1-1][2]++;
		matrizTablaP[c1-1][5]+=g1;
		matrizTablaP[c1-1][6]+=g2;
		matrizTablaP[c1-1][7]=c1;
	}else if(g1==g2){
		matrizTablaP[c1-1][0]+=1;		
		matrizTablaP[c1-1][3]++;
		matrizTablaP[c1-1][5]+=g1;
		matrizTablaP[c1-1][6]+=g2;
		matrizTablaP[c1-1][7]=c1;
	}else{		
		matrizTablaP[c1-1][4]++;
		matrizTablaP[c1-1][5]+=g1;
		matrizTablaP[c1-1][6]+=g2;
		matrizTablaP[c1-1][7]=c1;
	}
	
	matrizTablaP[c2-1][1]++;
	if(g2>g1){
		matrizTablaP[c2-1][0]+=3;		
		matrizTablaP[c2-1][2]++;
		matrizTablaP[c2-1][5]+=g2;
		matrizTablaP[c2-1][6]+=g1;
		matrizTablaP[c2-1][7]=c2;
	}else if(g1==g2){
		matrizTablaP[c2-1][0]+=1;		
		matrizTablaP[c2-1][3]++;
		matrizTablaP[c2-1][5]+=g2;
		matrizTablaP[c2-1][6]+=g1;
		matrizTablaP[c2-1][7]=c2;
	}else{		
		matrizTablaP[c2-1][4]++;
		matrizTablaP[c2-1][5]+=g2;
		matrizTablaP[c2-1][6]+=g1;
		matrizTablaP[c2-1][7]=c2;
	}
	
	
}


void tablaPosiciones2(int c1,int c2,int g1,int g2){
	if(g1>g2){
		matrizTablaP[c1-1][0]+=3;
		matrizTablaP[c1-1][1]++;
		matrizTablaP[c1-1][2]++;
		matrizTablaP[c1-1][5]+=g1;
		matrizTablaP[c1-1][6]+=g2;
		
	}else if(g1==g2){
		matrizTablaP[c1-1][0]+=1;
		matrizTablaP[c1-1][1]++;
		matrizTablaP[c1-1][3]++;
		matrizTablaP[c1-1][5]+=g1;
		matrizTablaP[c1-1][6]+=g2;
		
	}else{
		
		matrizTablaP[c1-1][1]++;
		matrizTablaP[c1-1][4]++;
		matrizTablaP[c1-1][5]+=g1;
		matrizTablaP[c1-1][6]+=g2;
		
	}
	
	if(g2>g1){
		matrizTablaP[c2-1][0]+=3;
		matrizTablaP[c2-1][1]++;
		matrizTablaP[c2-1][2]++;
		matrizTablaP[c2-1][5]+=g2;
		matrizTablaP[c2-1][6]+=g1;
		
	}else if(g1==g2){
		matrizTablaP[c2-1][0]+=1;
		matrizTablaP[c2-1][1]++;
		matrizTablaP[c2-1][3]++;
		matrizTablaP[c2-1][5]+=g2;
		matrizTablaP[c2-1][6]+=g1;
		
	}else{
		matrizTablaP[c2-1][1]++;
		matrizTablaP[c2-1][4]++;
		matrizTablaP[c2-1][5]+=g2;
		matrizTablaP[c2-1][6]+=g1;
		
	}
	
	
}


void TablaGoles(int cant){
	printf("\n\n\tTABLA DE GOLES\n");
	int sum1=0;
	printf("\t");
	for(i=0;i<cant;i++){
		printf("\t%s",e[i].nombre);
	}
	printf("\tTotal a favor\n");
	for(i=0;i<cant;i++){
		printf("\t%s",e[i].nombre);
		for(j=0;j<cant;j++){
			printf("\t%d",matrizGoles[i][j]);
			sum1+=matrizGoles[i][j];
		}
		printf("\t%d",sum1);
		sum1=0;
		printf("\n");
	}
	sum1=0;
	printf("\tT.C");
	for(i=0;i<cant;i++){			
		for(j=0;j<cant;j++){
			sum1+=matrizGoles[j][i];
		}
		printf("\t%d",sum1);
		sum1=0;
	}
}

void verTablaPosiciones(int cant){
	int k;
	
	printf("\tEquipo\tPtos\tJ\tG\tE\tP\tGA\tGC\n");
	for(i=0;i<cant;i++){
		
		for(k=0;k<cant;k++){
			
			if(matrizTablaP[i][7]==e[k].codigo){
				printf("\t%s",e[k].nombre);
			}
		}
		
		
		for(j=0;j<7;j++){
			printf("\t%d",matrizTablaP[i][j]);
		}
		printf("\n");
	}
}

void bubbleSort(int cant){
	int temp;

	
	for(i=0;i<cant;i++){
		for(j=0;j<cant-1;j++){
			if (matrizTablaP[j][0]  < matrizTablaP[j+1][0])
			{
				temp = matrizTablaP[j][0];
    			matrizTablaP[j][0] = matrizTablaP[j+1][0];
    			matrizTablaP[j+1][0] = temp;
    				
    			temp = matrizTablaP[j][1];
    			matrizTablaP[j][1] = matrizTablaP[j+1][1];
    			matrizTablaP[j+1][1] = temp;
    			
    			temp = matrizTablaP[j][2];
    			matrizTablaP[j][2] = matrizTablaP[j+1][2];
    			matrizTablaP[j+1][2] = temp;
    			
    			temp = matrizTablaP[j][3];
    			matrizTablaP[j][3] = matrizTablaP[j+1][3];
    			matrizTablaP[j+1][3] = temp;
    			
    			temp = matrizTablaP[j][4];
    			matrizTablaP[j][4] = matrizTablaP[j+1][4];
    			matrizTablaP[j+1][4] = temp;
    			
    			temp = matrizTablaP[j][5];
    			matrizTablaP[j][5] = matrizTablaP[j+1][5];
    			matrizTablaP[j+1][5] = temp;
    			
    			temp = matrizTablaP[j][6];
    			matrizTablaP[j][6] = matrizTablaP[j+1][6];
    			matrizTablaP[j+1][6] = temp;
    			
    			temp = matrizTablaP[j][7];
    			matrizTablaP[j][7] = matrizTablaP[j+1][7];
    			matrizTablaP[j+1][7] = temp;
    		}	
		}
	}
}

void encerar(){
	for(i=0;i<10;i++){
    	for(j=0;j<5;j++){
    		matrizP[i][j]=0;
		}
	}
				
	for(i=0;i<10;i++){
    	for(j=0;j<10;j++){
    		matrizGoles[i][j]=0;
		}
	}
}


void guardaDatos(int cant){
	int j;
	FILE * flujo = fopen("equipos.txt","w");
	if(flujo == NULL){
		perror("Error en la apertura del archivo");

	}else{
		for(j=0;j<cant;j++){
			fprintf(flujo,"%d %s",e[j].codigo,e[j].nombre);
			if(j<i-1){
				fputc('\n',flujo);
			}

		}
	}
	fflush(flujo);
	fclose(flujo);
}

void guardaResultadosTxt(int cant){
	
	int k;
	getch();
	FILE * flujo = fopen("resultados.txt","w");
	
	if(flujo == NULL){
		perror("Error en la apertura del archivo");

	}else{
		fprintf(flujo,"\tEquipo\tPtos\tJ\tG\tE\tP\tGA\tGC\n");
		for(i=0;i<cant;i++){
		
			for(k=0;k<cant;k++){
				
				if(matrizTablaP[i][7]==e[k].codigo){
					fprintf(flujo,"\t%s",e[k].nombre);
					//printf("\t%s",e[k].nombre);
				}
			}
		
		
		for(j=0;j<7;j++){
			fprintf(flujo,"\t%d",matrizTablaP[i][j]);
			//printf("\t%d",matrizTablaP[i][j]);
			
		}
		fprintf(flujo,"\n");
		//printf("\n");
	}
	}
	fflush(flujo);
	fclose(flujo);
}


int main(){
	system("color 71");    
    int val=0;
    int band,tam,codigoBuscar,posic,equip1,equip2,g1,g2,opcion,ip=0,jp=0;;
    int autorizacion=0;
    
    do{
    	system("cls");
    	membrete();
    	jp=0;
        printf("	MENU\n");
        printf("1.- Cargar equipos\n");
        printf("2.- Registrar un resultado\n");
        printf("3.- Corregir un resultado\n");
        printf("4.- Mostrar tabla de goles\n");
        printf("5.- Mostrar tabla de posiciones\n");
        printf("6.- Finalizar\n");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
            	if(autorizacion==0){	
            		autorizacion=1;
                	band=0;
                	do{
	                    printf("Ingrese la cantidad de equipos\n");
	                    scanf("%d",&tam);
	                    if(tam>1 && tam<11){
	                        band=1;
	                    }else{
	                        printf("La cantidad de equipos debe ser mayor a 2 y menor a 10\n");
	                    }
	                }while(band==0);
	                primeraCarga(tam);				                
	                encerar();
	                guardaDatos(tam);
	        	}
	        	else{
	        		printf("LOS EQUIPOS YA FUERON CARGADOS");
				}
                break;
             case 2:
             	if(autorizacion!=0){				 
             		band=0;
             		int opr=0;
             		do{
	             		printf("Ingrese codigo del primero equipo\n");
	             		scanf("%d",&equip1);
	             		printf("Ingrese codigo del segundo equipo\n");
	             		scanf("%d",&equip2);
	             		if(equip1==equip2){
	             			printf("No se puede registrar un partido contra si mismo\n");
	             			opr++;
						 }else{
						 	if(validarEquipo(equip1,tam)==1){
						 		if(validarEquipo(equip2,tam)==1){
						 			if(validarPart(tam,equip1,equip2)==0){
						 				band=1;
									 }else{
									 	printf("Este partido ya esta registrado\n");
									 	opr++;
									 }
								 }else{
								 	printf("Codigo del segundo equipo no encontrado\n");
								 	opr++;
								 }
							 }else{
							 	printf("Codigo del primer equipo no encontrado\n");
							 	opr++;
							 }
						 }
					 }while(band==0 && opr<5);
					
					if(opr<5){             						
						matrizP[ip][jp]=partidoContador++;
						jp++;
						matrizP[ip][jp]=equip1;
						jp++;
						matrizP[ip][jp]=equip2;
						jp++;
						printf("Ingrese la cantidad de goles del primer equipo");
						scanf("%d",&g1);
						matrizP[ip][jp]=g1;
						jp++;
						printf("Ingrese la cantidad de goles del segundo equipo");
						scanf("%d",&g2);
						matrizP[ip][jp]=g2;
						
						actualizarMatrizGoles(equip1,equip2,g1,g2);
						tablaPosiciones(equip1,equip2,g1,g2);
						
						ip++;
					}else{
						printf("DEMASIADOS INTENTOS PARA REGISTRAR UN PARTIDO");
					}
				}
				else{
					printf("CARGUE LOS EQUIPOS PARA ACCEDER A ESTA OPCION\n");
				}
                break;
            case 3:
            	if(autorizacion!=0){
            		printf("Ingrese codigo del partido");
					scanf("%d",&codigoBuscar);
					posic=validarPartidobyCodigo(tam,codigoBuscar);
					if(posic!=-1){
						band=0;
	             	
						equip1=matrizP[posic][1];
						equip2=matrizP[posic][2];
						printf("Ingrese la cantidad de goles del primer equipo");
						scanf("%d",&g1);
						matrizP[posic][3]=g1;
						jp++;
						printf("Ingrese la cantidad de goles del segundo equipo");
						scanf("%d",&g2);
						matrizP[posic][4]=g2;
						
						printf("IMPRESION EQ1 %d EQ2 %d",equip1,equip2);
						
						actualizarMatrizGoles(equip1,equip2,g1,g2);
						tablaPosiciones2(equip1,equip2,g1,g2);
						
					}else{
						printf("Codigo del partido no encontrado");
					}
				}
				else{
					printf("CARGUE LOS EQUIPOS PARA ACCEDER A ESTA OPCION\n");
				}
                break;
             case 4:
             		if(autorizacion!=0){
	             		TablaGoles(tam);
	           		}else{
						printf("CARGUE LOS EQUIPOS PARA ACCEDER A ESTA OPCION\n");
					}
                break;
             case 5:
             		if(autorizacion!=0){
	             		bubbleSort(tam);
	             		verTablaPosiciones(tam);
	             		guardaResultadosTxt(tam);
	           		}else{
						printf("CARGUE LOS EQUIPOS PARA ACCEDER A ESTA OPCION\n");
					}
                break;
             case 6:
             	printf("Gracias por ocupar el sistema\n");
                break;
             default:
                printf("OPCION INCORRECTA\n");
        }
        getch();
    }while(opcion!=6);
}



