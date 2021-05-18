/*
where the functionality is as follows:
elisa$ ./a.out
elisa$ ./a.out 3
3 7 9
elisa$ ./a.out 5
0 3 7 8 9
elisa$ ./a.out 10
0 2 3 4 7 8 9
elisa$ ./a.out 20
0 2 3 4 5 7 8 9
elisa$ ./a.out 100
0 1 2 3 4 5 6 7 8 9

*/

#include <stdio.h>
#include <stdlib.h>
int comp(const void* x, const void* y) {
  return *(int*)x - *(int*)y;
}
int main(int c, char* v[]) {
  if (c > 1) {
    int i, n = atoi(v[1]); //// Convierte una cadena a su valor numérico (entero)
    int prev = -1;
    int* data = (int*)malloc(sizeof(int*) * n); //// n es el tamaño del arreglo unidimencional puede ver mas de esto en argdemo.c
    
    for (i = 0; i < n; i++) {
      data[i] = rand() % 10; //////da numeros random del 0 al 9
    }
    qsort(data, n, sizeof(int), comp);
    for (i = 0; i < n; i++) {
      if (data[i] != prev) {
        printf("%d ", data[i]);
        prev = data[i];
      }
    } 
    printf("\n");
    free(data);
  }
}
