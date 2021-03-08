
#include <stdio.h>

#define MAX 80
#define TRUE 1
#define FALSE 0

int main() {
  int c, number = FALSE, parenthesis = FALSE, quotes = FALSE; //contador de numeros, contador de parentesis
  while ((c = getchar()) != EOF) {
      switch(c){
      /*Cuando son parentesis aumento el contador  */
      case '[':
          parenthesis=TRUE;
          putchar(c);
          break;
      case ']':
          parenthesis=FALSE;
          putchar(c);
          break;
      case '(':
          parenthesis=TRUE;
          putchar(c);
          break;
      case ')':
          parenthesis=FALSE;
          putchar(c);
          break;
      case '{':
          parenthesis=TRUE;
          putchar(c);
          break;
      case '}':
          parenthesis=FALSE;
          putchar(c);
          break;
      case '<':
          parenthesis=TRUE;
          putchar(c);
          break;
      case '>':
          parenthesis=FALSE;
          putchar(c);
          break;
      case '\"':
          putchar(c);
          quotes++;
          break;

       case '\'':
          putchar(c);
          quotes++;
          break;

      case '\`':
          putchar(c);
          quotes++;
          break;



      default:
        if(c!='.'&&c!=':'&&c!='\?'&&c!='!'&&c!='-'&&c!=';'&&c!='_'){//quitamos la puntuacion
            if (parenthesis==TRUE||quotes==TRUE){
            putchar(c);
            }
            else{
                if (quotes==2){
                    quotes=0;
                }
                if (c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9'||c=='0'){
                    number++;
                }else{
                  number=0;
                }
                if (number==1){
                    putchar('X');
                }
                if (number==0){
                    putchar(c);
                }
            }
        }




        }
    }


    return 0;
  }

