#include<stdio.h>
#include<math.h>
#define K 7 /* Los primeros K números */
void prime(int n);

int main() {
  prime(K); //Llamando a la función
  return 0;
}

/*  Funcion */
void prime(int k){
  int count, i, flag, sr;
  int n=1;
  count = 1;

  while(count <= k){
    sr = sqrt(n);
    flag = 0; //Tengo como si ya tuviera un numero primo
    for(i=2; i<= sr; i++){
      if(n%i==0){
        flag = 1; //Si no es primo flag = 1 y no se cumple el siguiente if
        break;
      }

    }

    if(flag==0){
      printf("%d \n", n);
      count++; //Conteo de primos
    }

    n++; //Siguiente numero

  }
}
