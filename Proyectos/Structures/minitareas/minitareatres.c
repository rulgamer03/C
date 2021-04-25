/*
Provide command-line arguments (omitting the name of the executable that is implicitly considered to be the zero-position command-line argument) that will result in the program producing the printout 1, 4, 6.
r -> 1 
w -> 2 
x -> 4 
/// otro caso 


--------------
r x wx
1 4 6

en wx 2 or 4 es 6 checar en una calculadora programadora
--------------
*/


#include <stdio.h>
#define READ 01
#define WRITE 02
#define EXECUTE 04
typedef enum {FALSE = 0, TRUE = 1} boolean;
int main(int x, char* y[]) {
  int i;
  for (i = 1; i < x; i++) {
    unsigned int status = 0;
    char* pos = y[i];
    boolean done = FALSE;
    while (!done) {
      switch (pos[0]) {
      case '\0':
        done = TRUE;
        break;
      case 'r':
        status |= READ; // asignacion con Or binario
        break;
      case 'w':
        status |= WRITE;
        break;
      case 'x':
        status |= EXECUTE;
        break;
      default:
        break;
      }
      pos++;
    }
    printf("%d ", status);
  }
  printf("\n");
}
