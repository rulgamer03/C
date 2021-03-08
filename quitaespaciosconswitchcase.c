#include <stdio.h>
#include <string.h> // strstr

#define MAX 80
#define TRUE 1
#define FALSE 0

int main() {
  int c, number = FALSE, parenthesis = FALSE, quotes = FALSE;
  while ((c = getchar()) != EOF) {
      switch(c){
      case ' ':
          putchar('_');
      default:
        if(c!=' '){
           putchar(c);
        }
      }



  }
  return 0;
}
