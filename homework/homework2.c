#include<stdio.h>
#include<math.h>
#define K 23 /* Los primeros K números */
void prime(int n);
void binary(int j); //creamos una funcion llamada binario la cual ocupa j (que es el numero que generamos con la funcion primo
int main() {
  prime(K); //Llamando a la función
  return 0;
}


void binary(int j)
{
    /*
    char 1 byte (8 bits)
    int 2 bytes (16 bits)
    */
    unsigned int contador = 256 ; // 2^(n-1) maximo 32768 si se quiere menos 0 a la izquierda dividir entre 2, si quiere más 0 a la derecha multiplicar por 2 

    for (contador; contador > 0; contador >>=1){
        if (contador & j){
            printf("1");
        }else{
            printf("0");

        }
    }
    printf("\n");
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
000000001
000000010
000000011
000000101
000000111
000001011
000001101
000010001
000010011
000010111
000011101
000011111
000100101
000101001
000101011
000101111
000110101
000111011
000111101
001000011
001000111
001001001
001001111
*/
