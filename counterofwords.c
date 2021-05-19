//counter words sentences between []
#include <stdio.h> // printf, scanf
#include <stdlib.h> // malloc & free
#include <string.h>
#define MAX 30 // max word length
// #define DEBUG 1

typedef struct treenode {
  char* word;
  unsigned int counter;
  unsigned int depth;
  struct treenode* izq;
  struct treenode* der;
} node;

void erase(node* pos) {
  if (pos != NULL) {
    erase(pos->izq);
    erase(pos->der);
    free(pos->word);
    free(pos);
  }
  return;
}

void set_depth(node* pos, int d) {
  if (pos != NULL) {
    pos->depth = d;
#ifdef DEBUG
    printf("%s is at depth %d\n", pos->word, d);
#endif
    set_depth(pos->izq, d + 1);
    set_depth(pos->der, d + 1);
  }
}

node* insert(char* word, node* pos) {
  int cmp;
  if (pos == NULL) {
#ifdef DEBUG
    printf("%s recibe un nuevo nodo\n", word);
#endif
    pos = (node*)malloc(sizeof(node));
    pos->word = word;
    pos->depth = 0;
    pos->counter = 1;
    pos->izq = NULL;
    pos->der = NULL;
  } else {
#ifdef DEBUG
    printf("en %s, procesando %s\n", pos->word, word);
#endif
    cmp = strcmp(pos->word, word);
    if (cmp == 0) {
#ifdef DEBUG
      printf("%s incrementa su contador\n", pos->word);
#endif
      ++(pos->counter);
    } else if (cmp > 0) {
#ifdef DEBUGx
      printf("%s va a la izquierda en %s\n", word, pos->word);
#endif
      pos->izq = insert(word, pos->izq);
    } else { // cmp < 0
#ifdef DEBUG
      printf("%s va a la derecha en %s\n", word, pos->word);
#endif
      pos->der = insert(word, pos->der); // word is larger
    }
  }
#ifdef DEBUG
  printf("regresando desde %s\n", pos->word);
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
    printf("%c %s (%d) %c\n", prefix, pos->word, pos->counter, suffix);
    show(pos->izq, '<');
    show(pos->der, '>');
  }
  return;
}

void alpha(node* pos) {
  if (pos != NULL) {
    alpha(pos->izq);
    printf("%d %s\n", pos->counter, pos->word);
    alpha(pos->der);
  }
}

int main() {
  node* tree = NULL;
  FILE* general = fopen("conteo para estadisticas.txt", "r");
  char* c;
  char line[MAX];
    char* word;
    int i; //contadores
    int j;
    int k;
    int l;
    int something;
    i=0;
    int nameindicador=0;
    int numberindicador=0;
    while ((c = fgetc(general)) != EOF) {
        word = (char*)malloc(sizeof(char) * MAX);
        j=0;
        if (c == '\n') {
            line[i]='\0';
            i=0;
            k=0;
            l=0;
            for (j=0;j<strlen(line); j++){
                // Now with the name
                if (nameindicador==1&&line[j]!=']'){
                    word[l]=line[j];
                    l++;
                }
                if (nameindicador==1&&line[j]==']'){
                    word[l]='\0';
                    //printf("%s\n", name);
                    nameindicador=0;
                    tree = insert(word, tree);
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
    //end while

  /*while (1) {

    tree = insert(word, tree);
  }
  */
  set_depth(tree, 0);
  //show(tree, '+');
  alpha(tree);
  erase(tree);
  return 0;
}


