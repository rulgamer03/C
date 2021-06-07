#include <stdio.h>
int intercambio (int* a, int* b);
int main()
{
    int x, y, z;
    x=5;
    y=10;
    z= intercambio(&x, &y);
    printf("%i %i\n", x, y);
    printf("%i", z);
    return 0;
}
int intercambio(int* a, int* b){
    int aux;
    aux = *b;
    *b = *a;
    *a = aux;
    return 0;
}
