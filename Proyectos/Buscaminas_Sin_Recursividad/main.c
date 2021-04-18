/* UNA VERSION  SIN RECURSIVIDAD */
/* UNA VERSION  SIN RECURSIVIDAD */
/* UNA VERSION  SIN RECURSIVIDAD */
/* UNA VERSION  SIN RECURSIVIDAD */

#include <stdio.h>
#define TRUE 1 
#define FALSE 0
#include "calc.h"
#include <stdlib.h> /* for atof() */
#include <ctype.h> /* for tolower() */
#include <time.h> /* time */
#define MAXOP 100 /* max size of operand or operator */


int main()
{
    int bombas=0; // Numero de bombas
    float porcentaje_limite_superior = .75; // Para que no pueda poner el 100 % de bombas
    int limite_inferior = 1;
    int play= TRUE; //Siempre sera TRUE
    int pregunta=0; //Si es 0 te pregunta el tamaño del tablero
    int numero_encontrado; //En casos que se ocupan numeros por ejemplo dar el tamaño del arreglo
    int tam; //tamaño del tablero
    int errores=0; // Checa que la entrada este bien
    int type;
    char s[MAXOP];
    int contador=0; // Checa que la entrada este bien
    
    while (play==TRUE){
        if (pregunta==0){
            printf("Numero de columnas (sera el mismo numero de filas) entre 2 y 26\nSi escribes un numero decimal sera redondeado\n");
            while(pregunta==0 && (type = getop(s)) != EOF) {
                if (pregunta==0){
                switch (tolower(type)) {
                    case NUMBER:
                    numero_encontrado = atof(s);
                    contador++;
                    break;
                    case '\n':
                    if (errores==0&&numero_encontrado>=2&&numero_encontrado<=26&&contador==1){
                        tam=numero_encontrado;
                        printf("Listo, se generara un tablero %d x %d\n\n", tam, tam);
                        pregunta=1;
                        contador=0;
                       
                    }
                    else {
                        errores=0;
                        contador=0;
                        printf("\nNumero de columnas (sera el mismo numero de filas) entre 2 y 26\nSi escribes un numero decimal sera redondeado\n");
                    }
                    break;
                    default:
                    errores++;
                    break;
                
                }
                }
            
            }
        }
        
        if (pregunta==1){
            int limite_superior = tam*tam*porcentaje_limite_superior;
            printf("Numero de bombas, entre %d y %d\nSi escribes un numero decimal sera redondeado\n", limite_inferior, limite_superior);
            while(pregunta==1 && (type = getop(s)) != EOF) {
                if (pregunta==1){
                switch (tolower(type)) {
                    case NUMBER:
                    numero_encontrado = atof(s);
                    contador++;
                    break;
                    case '\n':
                    if (errores==0&&numero_encontrado>=limite_inferior&&numero_encontrado<=limite_superior&&contador==1){
                        bombas=numero_encontrado;
                        printf("Listo, el numero de bombas sera %d\n\n", bombas);
                        pregunta=2;
                        contador=0;
                       
                    }
                    else {
                        errores=0;
                        contador=0;
                        printf("\nNumero de bombas, entre %d y %d\nSi escribes un numero decimal sera redondeado\n", limite_inferior, limite_superior);
                    }
                    break;
                    default:
                    errores++;
                    break;
                
                }
                }
            
            }
        } 
        
        if (pregunta==2){ // Aqui ya se empieza a jugar si ganas imprimir ganaste y pregunta = 0 // si pierdes imprimir perdiste y pregunta = 0
            
            /*
            int tablero [tam][tam];
            int x, y;
            
            
            for (x=0;x<tam;x++){ /// llenamos el tablero con 0 
             for(y=0;y<tam;y++){
                 tablero[x][y]=0;
                 printf("%2d ", tablero[x][y]);
           
             }
             printf("\n");
        
            }
             
            printf ("\n");
            int z=0; // agregamos unas bombas
            srand(time(NULL));
            for (int z;z<bombas;z++){
                int primer_numero_random=rand()%(tam);
                int segundo_numero_random=rand()%(tam);
                if (tablero[primer_numero_random][segundo_numero_random]==0){
                    tablero[primer_numero_random][segundo_numero_random]=-1; ////// agregamos la bomba
                }
                else{
                    z--;
                }
            }
            
            // Imprimimos el tablero
            for (x=0;x<tam;x++){ /// llenamos el tablero con 0 
             for(y=0;y<tam;y++){
                 printf("%2d ", tablero[x][y]);
           
             }
             printf("\n");
             
            }
            */
            
            
            int i, j;
            int** matrix;
            int** descubiertas; // Cero cuando no has descubierto nada por lo tanto se mostraran #
            matrix = (int**)malloc(sizeof(int*) * tam);
            // Llenamos de 0 la matrix
            for (i = 0; i < tam; i ++){
                matrix[i] = (int*)malloc(sizeof(int) * tam);
                 for (j=0; j<tam; j++){
                     matrix[i][j]=0;
                 }
            }
            
            descubiertas = (int**)malloc(sizeof(int*) * tam);
            // Llenamos de 0 las descubiertas 
            for (i = 0; i < tam; i ++){
                descubiertas[i] = (int*)malloc(sizeof(int) * tam);
                 for (j=0; j<tam; j++){
                     descubiertas[i][j]=0;
                 }
            }
            
            // Ponemos minas
            srand(time(NULL));
            for (int z=0;z<bombas;z++){
                int primer_numero_random=rand()%(tam);
                int segundo_numero_random=rand()%(tam);
                if (matrix[primer_numero_random][segundo_numero_random]==0){
                    matrix[primer_numero_random][segundo_numero_random]=-1; ////// agregamos la bomba
                }
                else{
                    z--;
                }
            }
            
            // Cambiamos los 0 por los numeros correspondientes
            for (i = 0; i < tam; i ++){
                 for (j=0; j<tam; j++){
                     if (matrix[i][j]==0){
                         matrix[i][j]=contar(matrix,tam,i,j);
                     }
                 }
            }
            
            /*showcompletematrix(matrix, tam);*/ //ESTOO SIRVE PARA HACER TRAMPA TRAMPA TRAMPA TRAMPA TRAMPA TRAMPA TRAMPA TRAMPA TRAMPA TRAMPA TRAMPA TRAMPA TRAMPA TRAMPA TRAMPA 
            printf("\nPara escribir una coordenada escribe a2 o 2a (Cambia los numeros segun la cordenada que quieras\n");
            /// EN ESTE MOMENTO SE CREO EL TABLERO COMPLETO 
            
            
            /// Antes de usarla en la descubiertas en la posicion i j igualarlo a 1
            int letra=0;
            int contador_letra=0;
            int aciertos=0;
            int variable = tam*tam-bombas;
            showmatrixwhileplay(matrix,tam, descubiertas); 
            while(pregunta==2 && (type = getop(s)) != EOF) {///Si pierdes o ganas imprimir el mensaje correspondiente y hacer pregunta =0
                if(pregunta==2){
                    switch (tolower(type)) {
                        case NUMBER:
                        numero_encontrado=atof(s);
                        contador++;
                        break;
                        case '\n':
                        if (numero_encontrado>tam||letra>=tam){
                            printf("\n\n Error 1: Checa tu entrada \n\n");
                            contador_letra=0;
                            letra=0;
                            numero_encontrado=0;
                            contador=0;
                            errores=0;    
                        }
                        else if (numero_encontrado-1<tam&&letra-1<tam&&descubiertas[numero_encontrado-1][letra]!=1&&aciertos<=variable){
                            if (contador==1&&contador_letra==1&&errores==0&&matrix[numero_encontrado-1][letra]!=-1&&numero_encontrado-1<tam&&letra-1<tam){
                                aciertos++; //////// AQUI LE ATINASTE A ALGO QUE NO ES UNA BOMBA
                                if (aciertos==variable){ /////LE ATINASTE Al UNICO QUE FALTABA 
                                    printf("\n\nGANASTE\n\n");
                                    showcompletematrix(matrix, tam);
                                    pregunta=0;
                                    aciertos=0;
                                    contador_letra=0;
                                    letra=0;
                                    numero_encontrado=0;
                                    contador=0;
                                    errores=0;
                                    // Llenamos de 0 la matrix
            for (i = 0; i < tam; i ++){
                matrix[i] = (int*)malloc(sizeof(int) * tam);
                 for (j=0; j<tam; j++){
                     matrix[i][j]=0;
                 }
            }
            
            descubiertas = (int**)malloc(sizeof(int*) * tam);
            // Llenamos de 0 las descubiertas 
            for (i = 0; i < tam; i ++){
                descubiertas[i] = (int*)malloc(sizeof(int) * tam);
                 for (j=0; j<tam; j++){
                     descubiertas[i][j]=0;
                 }
            }
                                }
                                else{
                                    descubiertas[numero_encontrado-1][letra]=1; ///AQUI LE ATINASTE A ALGO QUE NO ES UNA BOMBA PERO AUN TE FALTA 
                                    showmatrixwhileplay(matrix,tam, descubiertas); 
                                    contador_letra=0;
                                    letra=0;
                                    numero_encontrado=0;
                                    contador=0;
                                    errores=0;
                                }
                            }
                            else if (contador==1&&contador_letra==1&&errores==0&&matrix[numero_encontrado-1][letra]==-1&&numero_encontrado-1<tam&&letra-1<tam){
                                printf("\n\n PERDISTE \n\n"); /// LE ATINASTE A UNA BOMBA 
                                showcompletematrix(matrix, tam);
                                aciertos=0;
                                contador_letra=0;
                                letra=0;
                                numero_encontrado=0;
                                contador=0;
                                errores=0;
                                pregunta=0;
                                bombas=-10;
                            }
                            else {
                            printf("\n\nError 2: Checa tu entrada\n\n"); //////  ESCRIBISTE MAL 
                            contador_letra=0;
                            letra=0;
                            numero_encontrado=0;
                            contador=0;
                            errores=0;    
                            }
                        }
                        else if (descubiertas[numero_encontrado-1][letra]!=1&&contador==1&&contador_letra==1&&errores==0&&aciertos==variable&&matrix[numero_encontrado-1][letra]==-1&&numero_encontrado-1<tam&&letra-1<tam){
                            printf("1 Perdiste\n\n");
                            showcompletematrix(matrix, tam);
                            aciertos=0;
                            contador_letra=0;
                            letra=0;
                            numero_encontrado=0;
                            contador=0;
                            errores=0;
                            pregunta=0;
                            bombas=-10;
                        }
                        else {
                            if (descubiertas[numero_encontrado-1][letra]!=1){
                        printf("\n\nError 3: Checa tu entrada\n\n"); //// ESCRIBISTE MAL
                            contador_letra=0;
                            letra=0;
                            numero_encontrado=0;
                            contador=0;
                            errores=0;
                            }
                            else if (numero_encontrado-1<tam&&letra-1<tam){
                            printf("\n\nError 4: Ya habia selesccionado esta opcion\n\n"); ///YA LO HABIAS descubierto
                            contador_letra=0;
                            letra=0;
                            numero_encontrado=0;
                            contador=0;
                            errores=0;
                            /*    if (numero_encontrado-1<tam&&letra-1<tam){
                                printf("Ya habia selesccionado esta opcion\n");
                            contador_letra=0;
                            letra=0;
                            numero_encontrado=0;
                            contador=0;
                            errores=0;
                                }
                                else if (numero_encontrado-1>=tam||letra-1>=tam){
                                printf("2 Checa tu entrada\n");
                            contador_letra=0;
                            letra=0;
                            numero_encontrado=0;
                            contador=0;
                            errores=0;    
                                }
                                
                            */
                            } // AQUI
                            else{
                                 printf("\n\nError 5: Checa tu entrada\n\n"); //// ESCRIBISTE MAL
                            contador_letra=0;
                            letra=0;
                            numero_encontrado=0;
                            contador=0;
                            errores=0;   
                            }
                            
                        }
                        break;
                        default:
                         if (type>=97&&type<=122){
                           letra=type-97;
                           contador_letra++;
                             
                         }
                         else {
                         printf("\n\nError 6: Checa tu entrada\n\n");
                         errores++;
                         }
                        break;
                    
                    }
                }
            }
            
            if (pregunta==3){
                play=FALSE;
            }
            
             
            
        }
     
     
     
     
     
      
    }
    
}
