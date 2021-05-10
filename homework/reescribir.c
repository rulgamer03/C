#include <stdio.h>
#include <string.h>

int main() {
  char descripcion[999];
  long nc;
  char c;
  int i;
  for (nc = 0; (c = getchar()) != EOF; nc++) {
     descripcion[nc]=c;
  }
  printf ("Reescrito\n\n");
  for (i=0; i<nc; i++){
      printf("%c", descripcion[i]);
  }
  return 1;
}
