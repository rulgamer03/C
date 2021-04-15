#include <stdio.h>

int main()
{
    int i, j, n=1;
    do{
    printf("Ingrese un numero de filas (i) de la matriz: ");
    scanf("%d", &i);
    } while (i<=0);
    do{
    printf("Ingrese un numero de columnas (j) de la matriz: ");
    scanf("%d", &j);} while (j<=0);
    
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
