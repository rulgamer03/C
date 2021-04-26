/*
¿Como compilar?
Utilizar el compilador gdb online de preferencia
Pegar este codigo en el main.c 
Crear un archivo llamado tree.h
Pegar lo que se encuentra en el archivo tree.h en esta carpeta
Darle a run en el main.c
*/
#include <stdio.h>
#include <string.h> // strstr
#include <stdlib.h> // malloc & free
#include <ctype.h> // isspace & tolower
#include "tree.h"

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
      if (pos->password!=NULL){
      printf("Este usuario ya estaba registrado\n\n");
      }
      else{
          pos->password = p;
          printf("Registro hecho\n\n");
      }
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
    if (position->password!=NULL){
    printf("%s ", position->user);
    }
    alpha(position->rightChild);
  }
}

void delete(node* position, char* u, char* p, int* i){/////// A la funcion eliminar le damos el usuario y la contrase
    //Recorremos el arbol en busca de una coincidencia con el usuario usuario u 
    // cuando encontremos una coincidencia 
    // checamos que la contraseña sea igual 
    // si son iguales, la cambiamos por null pos->password = NULL;
    /// si esta en 0 quiere decir que no hemos eliminado si esta en 1 si
    //si no checa que el usuario y la contraseña sean correctas
    if (position != NULL) {
        
        if (strcmp(position->user, u) == 0&&position->password==NULL){
            
        }
        
        else if (strcmp(position->user, u) == 0&&strcmp(position->password, p) == 0){
            position->password=NULL;
            printf("Usuario %s eliminado\n\n", u);
            *i=1; // i = 1 por lo tanto se hizo una  asignacion 
        }
        
        
    }
    

  

  
  
}

int main() {
  extern char linea[];
  node* n = NULL;
  node* tree = NULL; 
  int i;
  int l = 0;
  char* u;//// n es el tamaño del arreglo unidimencional puede ver mas de esto en argdemo.c
  char* p;
  int indicador=0;
  
  printf("Bienvenido\n");
  printf("Para agregar un usuario usa: add usuario contraseña\n");
  printf("Para eliminar un usuario usa: del usuario contraseña\n");
  printf("Para ver los nombres de los usuarios acomodados alfabeticamente usa: view\n\n");
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
      /// De este modo es igual usar p o password 
      delete(tree, u, p, &indicador);
      if (indicador!=1){//No se elimino 
          printf("No se elimino al usuario\n\n");
      }
      indicador=0;
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
	    
	  printf ("Se ha registrado al usuario <%s> con la contraseña <%s>\n\n", u, p);
      }// aqui termina el add 
      
    else if (strstr(linea, "view") != NULL&&strlen(linea)==4) { // if we found  "show" we need to show
      alpha(tree);
      printf("\n\n");
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


