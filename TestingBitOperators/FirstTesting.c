#include <stdio.h>

int main(){
    /*
    char 1 byte (8 bits)
    int 2 bytes (16 bits)
    */
    int numero1 = 14; // 01110
    int numero2 = 23; // 10111
    int resultadoand = numero1 & numero2;
    /*
    01110	14
    10111	23
    ----------	& AND (1 if both are 1, otherwise 0)
    00110   6	4 + 2
    */
    int resultadoor = numero1 | numero2;
    /*
    01110	14
    10111	23
    ----------	| OR (0 if both are 0, otherwise 1)
    11111	31	16 + 8 + 4 + 2 + 1
    */
    int resultadoxor = numero1 ^ numero2;
    /*
    01110	14
    10111	23
    ----------	^ XOR (1 if only one is 1, otherwise 0)
    11001	25	16 + 8 + 1

    */
    int resultadobit1 = numero1 >> 1;
    // 14/2 =  7 0111
    int resultadobit2 = numero1 >> 2;
    //7/2 = 3.5 = 3 011
    int resultadobit3 = numero1 >> 3;
    //3/2 = 1.1 = 1 001
    int resultadobit4 = numero1 << 1;
    // 14*2 =  28 00011100
    int resultadobit5 = numero1 << 2;
    // 28*2 =  56 000111000
    int resultadonot = ~63; ///////cambia 0 a 1 y 1 a 0
    printf("%d \n\n", resultadoand); // si son int usa %d    / si son char usa %i
    printf("%d \n\n", resultadoor);
    printf("%d \n\n", resultadoxor);
    printf("%d \n\n", resultadobit1);
    printf("%d \n\n", resultadobit2);
    printf("%d \n\n", resultadobit3);
    printf("%d \n\n", resultadobit4);
    printf("%d \n\n", resultadobit5);
    printf("%d \n\n", resultadonot);
    unsigned int contador = 32768; // 2^(n-1) unsigned is an integer that can never be negative
    for (contador; contador > 0; contador >>=1){
        if (contador & numero1){
            printf("1"); // verdadero 1
        }else{
            printf("0"); // falso 0

        }
    }
    /*
    Suponiendo que fuera 2^4 el contador seria 16
    16 --- a binario --> 10000
    El numero es
    14 --- a binario --> 01110
    lo que sigue es hacer la operacion & AND (1 if both are 1, otherwise 0)
    10000
    01110
    -----
    00000
    Entonces imprimiremos "0"
    Dividimos entre 2 el contador, ahora el contador es 8 --- a binario --> 1000
    1000
    1110
    -----
    1000
    Entonces imprimiremos "1"
    Dividimos entre 2 el contador, ahora el contador es 4 --- a binario --> 100
    0100
    1110
    ----
    0100
    Entonces imprimiremos "1"
    Dividimos entre 2 el contador, ahora el contador es 2 --- a binario --> 10
    0010
    1110
    ----
    0010
    Entonces imprimiremos "1"
    Dividimos entre 2 el contador, ahora el contador es 1 --- a binario --> 1
    0001
    1110
    ----
    0000
    Entonces imprimiremos "0"
    Dividimos entre 2 el contador, ahora el contador es
    */
    printf("\n");
    return 0;
}
