/*
add zurita 345                                                                                                                  
Registro hecho                                                                                                                  
                                                                                                                                
add angel 999                                                                                                                   
Registro hecho                                                                                                                  
                                                                                                                                
add yoselin 888                                                                                                                 
Registro hecho                                                                                                                  
                                                                                                                                
add alejandro 4675                                                                                                              
Registro hecho                                                                                                                  
                                                                                                                                
add samuel 5555                                                                                                                 
Registro hecho                                                                                                                  
                                                                                                                                
add christo 1244                                                                                                                
Registro hecho                                                                                                                  
                                                                                                                                
add maury 999913                                                                                                                
Registro hecho                                                                                                                  
                                                                                                                                
add alejandro 999                                                                                                               
Este usuario ya estaba registrado                                                                                               
                                                                                                                                
view                                                                                                                            
alejandro angel christo maury samuel yoselin zurita                                                                             
^C                                                    

*/

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
  unsigned int depth;
} node;

node* insert(char* u, char* p, node* pos, int d) {
  node* temp;
  if (pos == NULL) {
    pos = (node*)malloc(sizeof(node));
    pos->user = u;
    pos->password = p;
    pos->depth = d;
    printf("Registro hecho\n\n");
    /*
    int strcmp(const char *cadena1, const char *cadena2);
    Devuelve 0 si las cadenas de texto son iguales (incluyendo mayúsculas y minúsculas); 
    si la primera cadena es mayor que la segunda, devuelve un número positivo; si es mayor la segunda,
    devuelve un valor negativo. Existen variantes (no estándar, dependientes del compilador) que comparar 
    dos cadenas despreciando mayúsculas y minúsculas, como stricmp
    */
  } else {
    if (strcmp(pos->user, u) == 0) {
      printf("Este usuario ya estaba registrado\n\n");
    } else if (strcmp(pos->user, u)>0) { // value is smaller     si pos->value > value
      /*printf("Registro algo menor\n\n");*/
      temp = insert(u, p, pos->leftChild, d + 1);
      if (pos->leftChild == NULL) {
	pos->leftChild = temp;
      }
    } else if (strcmp(pos->user, u)<0){
      temp = insert(u, p, pos->rightChild, d + 1); // value is larger
      /*printf("Registro algo mayor\n\n");*/
      if (pos->rightChild == NULL) {
	pos->rightChild = temp;
      }
    }
  }
  return pos;
}

void alpha(node* position) {
  if (position != NULL) {
    alpha(position->leftChild);
    printf("%s ", position->user);
    alpha(position->rightChild);
  }
}


int main() {
  extern char linea[];
  node* n = NULL;
  node* tree = NULL; 
  
  int l = 0;
  char* u;//// n es el tamaño del arreglo unidimencional puede ver mas de esto en argdemo.c
  char* p;
  int i;

  while ((l = saca()) == 0) {
    if (strstr(linea, "del") != NULL&&strlen(linea)>=7) { // if we found  "del" we need to delete
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
    
    else if (strstr(linea, "add") != NULL&&strlen(linea)>=7) { // if we found  "add" we need to add
      get(linea, password, user);
      u = (char*)malloc(sizeof(int*) * strlen(user));
      p = (char*)malloc(sizeof(int*) * strlen(password));
      for (i=0; i<strlen(user);i++){
          u[i]=user[i];
      }
      for (i=0; i<strlen(password);i++){
          p[i]=password[i];
      }
      /*
      printf ("%s %s end\n", password, user);
      printf ("%s %s end\n", p, u);*/
      /// De este modo es igual usar p o password 
      n = insert(u,p, tree, 0);
	  if (tree == NULL) {
	    tree = n; // this is the root
	    }
      }
    else if (strstr(linea, "view") != NULL) { // if we found  "show" we need to show
      alpha(tree);
      printf("\n");
    }
    else{
        printf("Checa tu entrada\n");
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

