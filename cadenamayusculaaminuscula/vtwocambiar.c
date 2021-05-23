  
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define MAX 99
int saca(char* );
void minusculas(char*);
int sacaminusculas (char* );
int main()
{
    char name[MAX];
    printf("Cadena a minusculas\n");
    saca(name);
    minusculas(name);
    printf("%s", name);
    printf("\n\nCadena a minusculas\n");
    sacaminusculas(name);
    printf("%s", name);

    return 0;
}
void minusculas(char* cadena){
    int i;
    for (i=0; i<strlen(cadena); i++){
        cadena[i]=tolower(cadena[i]);
    }
}
int saca(char* linea) { //This part is from longest.c
  //https://github.com/satuelisa/C/blob/main/Ch1/longest.c
  int c, i = 0;
  for (; i < MAX - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
    linea[i] = c;
  }
  linea[i] = '\0'; // caracter de terminacion de string
  return i; // cual fue el largo
}

int sacaminusculas(char* linea) { //This part is from longest.c
  //https://github.com/satuelisa/C/blob/main/Ch1/longest.c
  int c, i = 0;
  for (; i < MAX - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
    linea[i] = tolower(c);
  }
  linea[i] = '\0'; // caracter de terminacion de string
  return i; // cual fue el largo
}
