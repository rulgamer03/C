/******************************************************************************
Practica 

Ingrese un numero de filas (i) de la matriz: 3                                                                                             
Ingrese un numero de columnas (j) de la matriz: 6                                                                                          
     1      2      3      4      5      6     21                                                                                           
     7      8      9     10     11     12     57                                                                                           
    13     14     15     16     17     18     93                                                                                           
    21     24     27     30     33     36      
*******************************************************************************/

#include <stdio.h>

int main()
{
    int i, j, n=1;
    printf("Ingrese un numero de filas (i) de la matriz: ");
    scanf("%d", &i);
    printf("Ingrese un numero de columnas (j) de la matriz: ");
    scanf("%d", &j);
    int arreglo[i][j];
    int x, y, suma=0;
    
    for (x=0;x<i;x++){ /// Se mantiene constante
        for(y=0;y<j;y++){
            arreglo[x][y]=n++;
            printf("%6d ", arreglo[x][y]);
            suma+=arreglo[x][y];
        }    
        printf("%6d\n", suma);
        suma=0;
    } 
    
    for (x=0;x<j;x++){ ///en 0 las columnas j
        for(y=0;y<i;y++){
            suma+=arreglo[y][x];
        }  
        printf("%6d ", suma);
        suma=0;
    }
}
