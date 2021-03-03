#include<stdio.h>
#include<math.h>
#define K 23 /* Los primeros K números */
void prime(int n);
void binary(int j);
int main() {
  prime(K); //Llamando a la función
  return 0;
}


void binary(int j)
{
    int i=0; //// este es un contador
    int base[10]={0}; //  numero de ceros 0 0 0 0 0 0 0 0 0 0
    // 0 0
    while(j>0)
    {
        // Operaciones de la libreta saco el residuo y lo pongo en la posicion, tengo que dividir el numero y aumentar la posicion
	base[i]= j%2;// residuo de la division
	j/=2; // realizamos la division
	++i; // aumentamos en uno la posicion
    }
    // imprimir al reves 123 321

    for(int x=9;x>=0;--x)   //  numero de arriba menos 1
    {
       printf("%01d",base[x]);
    }
     printf("\n");// cuando termine de imprimir todo salto de linea para seguir con el siguiente numero
}


/*  Funcion */
void prime(int k)
{
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

    if(flag==0){ // es primo

      binary(n); // si es primo lo metes a la funcion que transforma a binario
      count++; //Conteo de primos para no pasarse del limite
    }

    n++; //Siguiente numero

  }
}

/*
Output
0000000001
0000000010
0000000011
0000000101
0000000111
0000001011
0000001101
0000010001
0000010011
0000010111
0000011101
0000011111
0000100101
0000101001
0000101011
0000101111
0000110101
0000111011
0000111101
0001000011
0001000111
0001001001
0001001111
*/
