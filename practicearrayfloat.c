#include <stdio.h>
void ponervalores (float* , int, float );
int main()
{
    float arreglo[20]; /// ESTE ES EL QUE PUSE DE ARGUMENTO
    ponervalores(arreglo, 20, 2.5);
    for (int i=0; i < 20; i++){
        printf("%.2f\n", arreglo[i]);
    }
    return 0;
}
void ponervalores (float* array, int tamano, float numero){
    for (int i=0; i < tamano; i++){
        array[i]=numero * (i+1);
    }
}
