/******************************************************************************

Explicando int *a   // &x

*******************************************************************************/
#include <stdio.h>

int main()
{
    int x=2; // x vale 2
    int* a = &x; // a es la direccion de x
    printf("%d\n", x); // imprimo x que vale 2
    printf("%d\n", *a); // imprimo lo que esta en la direccion x
    *a = 200; // con esto le estoy diciendo en a (que es la direccion de x) ponme 200
    printf("%d\n", x);
    printf("%d\n", *a);
    
    return 0;
}
