#include <stdio.h>
#include <string.h> // strstr
#include <stdlib.h> // malloc & free
#include <ctype.h> // isspace & tolower

#define MAX 80

char linea[MAX], password[MAX], user[MAX];
int saca(); // Function that give us the line
void get (char l[MAX],char p[MAX],char u[MAX]); /* Function that give us the user and the password and agrega gente*/

typedef struct treenode {
  char* user; //usuario 
  char* password; //contraseña 

  struct treenode* leftChild;
  struct treenode* rightChild;
} node;

int main() {
  extern char linea[];
  int l = 0;
  char* u;//// n es el tamaño del arreglo unidimencional puede ver mas de esto en argdemo.c
  char* p;
  int i;

  while ((l = saca()) == 0) {
    if (strstr(linea, "del") != NULL) { // if we found  "del" we need to delete
      get(linea, password, user);
      u = (char*)malloc(sizeof(int*) * strlen(user));
      p = (char*)malloc(sizeof(int*) * strlen(password));
      for (i=0; i<strlen(user);i++){
          u[i]=user[i];
      }
      for (i=0; i<strlen(password);i++){
          p[i]=password[i];
      }
      printf ("%s %s end\n", password, user);
      printf ("%s %s end\n", p, u);
      /// De este modo es igual usar p o password 
    }
    
    else if (strstr(linea, "add") != NULL) { // if we found  "add" we need to add
      get(linea, password, user);
      u = (char*)malloc(sizeof(int*) * strlen(user));
      p = (char*)malloc(sizeof(int*) * strlen(password));
      for (i=0; i<strlen(user);i++){
          u[i]=user[i];
      }
      for (i=0; i<strlen(password);i++){
          p[i]=password[i];
      }
      printf ("%s %s end\n", password, user);
      printf ("%s %s end\n", p, u);
      /// De este modo es igual usar p o password 
    }
    else if (strstr(linea, "view") != NULL) { // if we found  "show" we need to show
      printf("view\n");
    }
    
    
  }
  /// Here
  return 0;
}

int saca() { // Function that give us the line, modification of a SATU ELISA SCHAEFFER  code Longest2.c nocomment.c
          
  extern char linea[];
  int c, i = 0;

  for (; i < MAX - 1 && (c = getchar()) != EOF && c != '\n';) {

        linea[i++] = c;

  }
  linea[i] = '\0'; // caracter end of string
  return c == EOF;
}

void get (char l[MAX],char p[MAX],char u[MAX]){
    int a = 4, b = 0, c=0;
    while (l[a]!=' '&&l[a]!='\t'){
        u[b]=l[a];
        b++;
        a++;
    }
    u[b]='\0';
    int longitud = strlen(u);
    a++;
    while (l[a]!=' '&&l[a]!='\t'&&l[a]!='\0'){
       p[c]=l[a];
       c++;
       a++;
    }
    p[c]='\0';
    int longitud2 = strlen(p);

}

