/*
2. Desarrollar un programa en C que calcule el área de un trapecio, introduciendo por teclado los valores de las bases y su altura.
A= (B+b)*a/2
Luis Loredo Maving      Mt. 1965085
*/

#include <stdio.h>
#include <conio.h>
int main(){

float A, a, B, b;

printf("B: ");
scanf("%f", &B);

printf("\nb: ");
scanf("%f", &b);

printf("\na: ");
scanf("%f", &a);

A= (B+b)*a / 2;

printf("El area del trapecio es %.2f", A);


return 0;
}
