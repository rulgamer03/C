#include "funciones.h"

float PI= 3.1416;

int suma(int a, int b){
    return a+b;
}

int resta(int a,int b){
    return a-b;
}

char primer_character(char* cadena){
    return cadena[0];
}

double area_circulo(int radio){
    return PI*radio*radio;
}
