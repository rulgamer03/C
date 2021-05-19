#include <string.h> // strstr
#include <stdio.h> // printf
#include <stdlib.h> // malloc & free
#include <ctype.h> // isspace & tolower
#define DEBUG 1 // enable for tons of printouts+
#define MAX 999
#include <time.h>
int add();
typedef struct treenode {
  char* value;
  unsigned int counter;
  unsigned int depth;
  struct treenode* izq;
  struct treenode* der;
} node;

void erase(node* pos) {
  if (pos != NULL) {
    erase(pos->izq);
    erase(pos->der);
    free(pos);
  }
  return;
}

void set_depth(node* pos, int d) {
  if (pos != NULL) {
    pos->depth = d;
#ifdef DEBUG
    printf("%s is at depth %d\n", pos->value, d);
#endif
    set_depth(pos->izq, d + 1);
    set_depth(pos->der, d + 1);
  }
}

node* insert(char* value, node* pos) {
  if (pos == NULL) {
#ifdef DEBUG
    printf("%s recibe un nuevo nodo\n", value);
#endif
    pos = (node*)malloc(sizeof(node));
    pos->value = value;
    pos->depth = 0;
    pos->counter = 1;
    pos->izq = NULL;
    pos->der = NULL;
  } else {
    if (strcmp(pos->value, value) == 0) {
#ifdef DEBUG
      printf("%s incrementa su contador\n", value);
#endif
      ++(pos->counter);
    } else if (strcmp(pos->value, value)>0) { // value is smaller
#ifdef DEBUG
      printf("%s va a la izquierda en %s\n", value, pos->value);
#endif
      pos->izq = insert(value, pos->izq);
    } else {
#ifdef DEBUG
      printf("%s va a la derecha en %s\n", value, pos->value);
#endif
      pos->der = insert(value, pos->der); // value is larger
    }
  }
#ifdef DEBUG
  printf("regresando desde %s\n", pos->value);
#endif
  return pos;
}

node* eliminar(char* value, node* pos) { // WORK IN PROGRESS
  node* hijo;
  int count;
  if (pos != NULL) {
    if (strcmp(pos->value, value)==0) {
      --(pos->counter);
      if (pos->counter == 0) {
#ifdef DEBUG
	printf("%s ya no tiene ocurrencias\n", value);
#endif
	if (pos->izq == NULL && pos->der == NULL) {
#ifdef DEBUG
	  printf("%s no tiene hijos\n", value);
#endif
	  free(pos);
	  return NULL;
	} else if (pos->izq != NULL && pos->der == NULL) {
	  hijo = pos->izq;
#ifdef DEBUG
	  printf("%s tiene puro hijo izq %s\n", value, hijo->value);
#endif
	  free(pos);
	  return hijo;
	} else if (pos->izq == NULL && pos->der != NULL) {
	  hijo = pos->der;
#ifdef DEBUG
	  printf("%s tiene puro hijo der %s\n", value, hijo->value);
#endif
	  free(pos);
	  return hijo;
	} else {
#ifdef DEBUG
	  printf("%s tiene dos hijos %s + %s\n", value, pos->izq->value, pos->der->value);
#endif
	  hijo = pos->der;
	  while (hijo->izq != NULL) { // encontrar el menor a la der
	    hijo = hijo->izq;
	  }
#ifdef DEBUG
	  printf("voy a colgar %s desde %s\n", pos->izq->value, hijo->value);
#endif
	  hijo->izq = pos->izq;
	  free(pos);
	  return pos->der; // el hijo derecho sustituye al nodo borrado
	}
      }
    } else if (strcmp(pos->value, value)>0) {
      pos->izq = eliminar(value, pos->izq);
    } else {
      pos->der = eliminar(value, pos->der);
    }
    return pos;
  }
#ifdef DEBUG
  printf("no hay un nodo con %s\n", value);
#endif
  return pos;
}

void show(node* pos, char prefix) {
  int i;
  char suffix = ' ';
  if (pos != NULL) {
    for (i = 0; i < pos->depth; i++) {
      printf(" ");
    }
    if (pos->izq == NULL && pos->der == NULL) { // no children
      suffix = '#'; // a leaf node (dead end)
    }
    printf("%c %s (%d) %c\n", prefix, pos->value, pos->counter, suffix);
    show(pos->izq, '<');
    show(pos->der, '>');
  }
  return;
}


void alpha(node* pos) {
  if (pos != NULL) {
    alpha(pos->izq);
    printf("%s", pos->value);
    alpha(pos->der);
  }
}

typedef enum { agregar, borrar } estado;


int add(){
  node* tree = NULL;
  estado e = agregar;
  FILE* sistema = fopen("conteo para estadisticas.txt", "r");
    char line[MAX];
    char number[MAX];
    char name[MAX];
    char c;
    int i; //contadores
    int j;
    int k;
    int l;
    int something;
    i=0;
    int nameindicador=0;
    int numberindicador=0;
    while ((c = fgetc(sistema)) != EOF) {
        j=0;
        if (c == '\n') {
            line[i]='\0';
            i=0;
            k=0;
            l=0;
            for (j=0;j<strlen(line); j++){
                // Now with the name
                if (nameindicador==1&&line[j]!=']'){
                    name[l]=line[j];
                    l++;
                }
                if (nameindicador==1&&line[j]==']'){
                    name[l]='\0';
                    // We have a name to add
                    printf("%s\n", name);
                    tree = insert(name, tree);
                    nameindicador=0;
                    #ifdef DEBUG
                    printf("depth update\n");
                    set_depth(tree, 0);
                    printf("visualization\n");
                    show(tree, '+');
                    #endif
                }
                if (line[j]=='['){
                    nameindicador=1;
                }
            }
        }
        else{
            line[i]=c;
            i++;
        }
    }

    set_depth(tree, 0);
    show(tree, '+');


/*
  while (1) {
    switch (c = getchar()) {
    case '*':
      if (e == agregar) {
	printf("<<<\n");
	e = borrar;
      } else {
	printf(">>>\n");
	e = agregar;
      }
      break;
    case '-':
      erase(tree);
    case '!':
      set_depth(tree, 0);
      show(tree, '+');
      break;
    case '?':
      alpha(tree);
      printf("\n");
      break;
    default:
      if (!isspace(c)) {
	if (e == agregar) {
	  tree = insert(tolower(c), tree);
	} else {
	  tree = eliminar(tolower(c), tree);
	}
      } //here



      return 0; */


  /*      break;
    }
  }

   */


}

int main() {
  //add();
  node* tree = NULL;
  estado e = agregar;
  char name[MAX];
  tree = insert("asma", tree);
  tree = insert("alergia", tree);
  tree = insert("alergia", tree);
  tree = insert("pepe", tree);
  tree = insert("alma", tree);


   int i, n, aleatorio,P=11, U=12;

        srand(time(NULL));

        scanf("%d", &n);

        for (i = 0; i < n; i ++)
        {
            aleatorio = P+(int)(((U-P+1.0)*rand())/(RAND_MAX+1.0));
            if(aleatorio==11){
                tree = insert("asma", tree);
                printf("1  asma\n");
            }
            if(aleatorio==12){
                tree = insert("pepe", tree);
                printf("2  pepe\n");
            }
            printf("%d", aleatorio);
        }


  set_depth(tree, 0);
  show(tree, '+');

  /*
  FILE* sistema = fopen("conteo para estadisticas.txt", "r");
    char line[MAX];
    char number[MAX];
    char name[MAX];
    char c;
    int i; //contadores
    int j;
    int k;
    int l;
    int something;
    i=0;
    int nameindicador=0;
    int numberindicador=0;
    while ((c = fgetc(sistema)) != EOF) {
        j=0;
        if (c == '\n') {
            line[i]='\0';
            i=0;
            k=0;
            l=0;
            for (j=0;j<strlen(line); j++){
                // Now with the name
                if (nameindicador==1&&line[j]!=']'){
                    name[l]=line[j];
                    l++;
                }
                if (nameindicador==1&&line[j]==']'){
                    name[l]='\0';
                    // We have a name to add
                    printf("%s\n", name);
                    tree = insert(name, tree);
                    nameindicador=0;
                    #ifdef DEBUG
                    printf("depth update\n");
                    set_depth(tree, 0);
                    printf("visualization\n");
                    show(tree, '+');
                    #endif
                }
                if (line[j]=='['){
                    nameindicador=1;
                }
            }
        }
        else{
            line[i]=c;
            i++;
        }
    }

    set_depth(tree, 0);
    show(tree, '+');
    */

/*
  while (1) {
    switch (c = getchar()) {
    case '*':
      if (e == agregar) {
	printf("<<<\n");
	e = borrar;
      } else {
	printf(">>>\n");
	e = agregar;
      }
      break;
    case '-':
      erase(tree);
    case '!':
      set_depth(tree, 0);
      show(tree, '+');
      break;
    case '?':
      alpha(tree);
      printf("\n");
      break;
    default:
      if (!isspace(c)) {
	if (e == agregar) {
	  tree = insert(tolower(c), tree);
	} else {
	  tree = eliminar(tolower(c), tree);
	}
      } //here



      return 0; */


  /*      break;
    }
  }

   */
}
