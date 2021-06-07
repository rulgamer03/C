#include <stdio.h>
int a, b, c, d;
void funcion1(int, int*, int*);
int funcion2 (int* , int);
int main()
{
    int a;
    a = 1;
    b = 2;
    c = 3;
    d = 4;
    printf ("\n%d %d %d %d", a, b, c, d); // 1 2 3 4 no hay cambios (1)
    a = funcion2(&a, c); // le ponemos el 1 y el 3 vamos a funcion2 // a es c por el return
    printf("\n%d %d %d %d", a, b,c,d); // 3 2 3 4 (el unico que cambio fue a por el return) (4)
    
    return 0;
}
void funcion1 (int r, int* b, int* c){ // -1 1 7
    int d;
    a = *c; // 7
    d = a + 3 + *b; // de es 7 + 3 + 1 = 11
    *b = *b + 5;  // 1 + 5 = 6
    *c = *c + 4; // 7 + 4 = 11
    printf("\n%d %d %d %d", a, *b, *c, d); // 7 6 11 11 (2)
}
int funcion2 (int *d, int c){ // le ponemos el 1 y el 3
    int b;
    a = 1;
    b = 7; // b solo existe en la funcion2 
    funcion1(-1, d, &b); // d ahora es 6 // b ahora es 11 y recordar que a ahora es 7
    printf("\n%d %d %d %d", a, b, c, *d); // 7 11 3 6 (3)
    return c;
}
