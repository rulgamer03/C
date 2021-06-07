#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h> /* for tolower() */
void ponervalores (float** , int , int, float );
int main()
{
    int i, j;
    float** matrix;
    int a = 2;
    int b = 10;
    
     // CON ESTO SIMPLEMENTE LE DAMOS TAMAÑO
    
    matrix = (float**)malloc(sizeof(int*) * a); /// a = 2 /// b = 10 como quien dice hacemos una matrix de [2][10]
   
    for (i = 0; i < a; i ++){
        matrix[i] = (float*)malloc(sizeof(int) * b);
        for (j=0; j<b; j++){
            
        }
    }
    
    /// FIN DE DAR TAMAÑO 
    ponervalores(matrix, a, b, 20.5);
    for(int i = 0; i < a; i++){
        for (int j=0; j<b; j++){
            printf("%.2f\n", matrix[i][j]);
        }
    }
}
void ponervalores (float** array , int a, int b, float numero){
    for (int i = 0; i < a; i ++){
        for (int j=0; j<b; j++){
            array[i][j]=numero;
        }
    }
}
