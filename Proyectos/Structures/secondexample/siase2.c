//siase2.c
#include <stdio.h>
#include "siase2.h"

int main() {
  alumno fulano;
  fulano.c = 0; /// Counter as a 0
  fulano.matr = 123456;
  fulano.pe = "ITS"; // first access
  imprime(&fulano); /// imprime
  fulano.pe = "IMA"; /// cambio 
  imprime(&fulano);  /// second access
  fulano.pe = "ITS"; // 3 access
  imprime(&fulano); /// imprime
  return 1;
}

void imprime(alumno* a) {
  (a->c)++; //update the Counter 
  printf("%07d es %s y ha sido accedido %d veces\n", a->matr, a->pe, a->c);
  return;
}
