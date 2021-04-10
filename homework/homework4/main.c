#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h> /* for tolower() */
#include "calc.h"

#define MAXOP 100 /* max size of operand or operator */

int main()
{
    int type;
    int cantidad_de_numeros=0;
    int cantidad_de_letras=0;
    int cantidad_de_errores=0;

    double op2;
    char s[MAXOP];
    int letra_encontrada=0;
    int question=0;
    int asignacion=0;
    double numero_encontrado =0.0;
    int moverse=0;
    int respuesta_si=0;
    int respuesta_no=0;
    int error=0;

    double abc[26]={0}; // Un arreglo de 26 espacios correspondientes a las letras del abecedario
    int contador[26]={0}; //Cuenta cuantas asignaciones se le ha hecho a cada letra
     while ((type = getop(s)) != EOF) {
        if (moverse==0) {
        switch (tolower(type)) {
            case NUMBER:
            numero_encontrado = atof(s);
            push(atof(s));
            cantidad_de_numeros++;
            break;
            case '+':
            push(pop() + pop());
            break;
            case '*':
            push(pop() * pop());
            break;
            case '-':
            op2 = pop();
            push(pop() - op2);
            break;
            case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");

            break;
            case '\n':
            if (!asignacion&&!question){ //// SI NO HAY SIGNO DE = NI  DE : ES UNA OPERACION
            printf("\t%.8g\n", pop());
            // Volvemos a valores iniciales
            asignacion=0;
            letra_encontrada=0;
            question=0;
            numero_encontrado =0;
            cantidad_de_numeros=0;
            cantidad_de_letras=0;
            cantidad_de_errores=0;
            }
            else if (asignacion==1&&!question&&cantidad_de_numeros==1&&cantidad_de_letras==1){ // SI HAY SIGNO DE = NO HAY DE :  DEBE PREGUNTAR
            if (contador[letra_encontrada]==0){
                abc[letra_encontrada]=numero_encontrado;
                printf("Assignment ready\n");
                contador[letra_encontrada]++; //AUMENTA EL CONTADOR AL HACER UNA ASIGNACION
                // Volvemos a valores iniciales
                asignacion=0;
                letra_encontrada=0;
                question=0;
                pop();
                pop();
                numero_encontrado=0;
                cantidad_de_numeros=0;
                cantidad_de_letras=0;
                cantidad_de_errores=0;

            }

            else{

                moverse=1;
                printf("Would you like to rewrite the variable?\ny --> YES\nn-->NO\n");
                pop();
                pop();
            }
            }// Hay signo de = pero no de :

            else if (asignacion==1&&question==1&&cantidad_de_numeros==1&&cantidad_de_letras==1){
                abc[letra_encontrada]=numero_encontrado;
                pop();
                pop();
                printf("Assignment ready\n");
                contador[letra_encontrada]++; //AUMENTA EL CONTADOR AL HACER UNA ASIGNACION
                // Volvemos a valores iniciales
                asignacion=0;
                letra_encontrada=0;
                question=0;
                numero_encontrado=0;
                cantidad_de_numeros=0;
                cantidad_de_letras=0;
                cantidad_de_errores=0;
            }
            else{
                printf("error: check your input\n");
                asignacion=0;
                letra_encontrada=0;
                question=0;
                numero_encontrado=0;
                cantidad_de_numeros=0;
                cantidad_de_letras=0;
                pop();
                pop();
                cantidad_de_errores=0;
            }

            break;
            case '=':
            asignacion=1;
            break;
            case ':':
            question=1;
            break;
            default:
            if (type>=97&&type<=122){
                push(abc[type-97]);
                letra_encontrada=type-97;
                cantidad_de_letras++;

            }
            else {
            cantidad_de_errores++;
            printf("error: unknown command %s\n", s);
            }
            break;
        }

     }

     else {

     switch (tolower(type)) {
     case 'y':
     respuesta_si++;
     push(0); // puede ser cualquier numero
     break;
     case 'n':
     respuesta_no++;
     push(0); // puede ser cualquier numero
     break;
     case '\n':
     if (respuesta_si==1&&respuesta_no==0&&error==0){
        abc[letra_encontrada]=numero_encontrado;
        pop();
        printf("Assignament ready\n");
        contador[letra_encontrada]++; //AUMENTA EL CONTADOR AL HACER UNA ASIGNACION
        // Volvemos a valores iniciales
        asignacion=0;
        letra_encontrada=0;
        question=0;
        numero_encontrado=0;
        respuesta_no=0;
        respuesta_si=0;
        error=0;
        moverse=0;
        cantidad_de_numeros=0;
        cantidad_de_letras=0;
        cantidad_de_errores=0;

     }
     else if (respuesta_si==0&&respuesta_no==1&&error==0){
        pop();
        printf("The assign did not apply\n");
        // Volvemos a valores iniciales
        asignacion=0;
        letra_encontrada=0;
        question=0;
        numero_encontrado=0;
        respuesta_no=0;
        respuesta_si=0;
        moverse=0;
        error=0;
        cantidad_de_numeros=0;
        cantidad_de_letras=0;
        cantidad_de_errores=0;

     }
     else{
        pop();
        printf("error: Check your input\n\n");
        printf("Would you like to rewrite the variable?\ny --> YES\nn-->NO\n");
        respuesta_no=0;
        respuesta_si=0;
        error=0;
        cantidad_de_numeros=0;
        cantidad_de_letras=0;
        cantidad_de_errores=0;
     }
     break;
     default:
     error++;
     break;
     }
     }
    }
    return 0;
}
