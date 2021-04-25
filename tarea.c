#include <stdio.h>
#include <string.h> // strstr

#define MAX 80

char linea[MAX], password[MAX], user[MAX];
int saca(); // Function that give us the line
void getuser (char linea[MAX]); /* Function that give us the user and the password*/
int main() {
  extern char linea[];
  int l = 0;


  while ((l = saca()) == 0) {
    if (strstr(linea, "del") != NULL) { // if we found  "del" we need to delete
      getuser(linea);
    }
    
    else if (strstr(linea, "add") != NULL) { // if we found  "del" we need to delete
      getuser(linea);
    }
    else if (strstr(linea, "view") != NULL) { // if we found  "del" we need to delete
      printf("view");
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

void getuser (char linea[MAX]){
    int a = 4, b = 0, c=0;
    char user[10];
    char password[10];
    while (linea[a]!=' '&&linea[a]!='\t'){
        user[b]=linea[a];
        b++;
        a++;
    }
    user[b]='\0';
    int longitud = strlen(user);
    a++;
    while (linea[a]!=' '&&linea[a]!='\t'&&linea[a]!='\0'){
       password[c]=linea[a];
       c++;
       a++;
    }
    password[c]='\0';
    printf("el usuario es %s y su contraseña es %s end\n", user, password);
}
