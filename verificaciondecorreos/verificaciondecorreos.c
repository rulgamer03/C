#include <stdio.h>
#include <string.h>
#define MAX 99
int verificarcorreo(char* );
int saca(char* );

int main()
{
    char correo[MAX];
    do {
    printf("Dame tu correo\n");
    saca(correo);
    } while (verificarcorreo(correo)==0);

    return 0;
}
int saca(char* linea) { //This part is from longest.c
  //https://github.com/satuelisa/C/blob/main/Ch1/longest.c
  int c, i = 0;
  for (; i < MAX - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
    linea[i] = c;
  }
  linea[i] = '\0'; // caracter de terminacion de string
  return i; // cual fue el largo
}
int verificarcorreo(char* correo) //return 1 si el correo es valido // return 0 si no es correo valido
{
    int longitude;
    char extencion[MAX]; //ejemplo @gmail.com
    longitude = strlen(correo);
    int i;
    int j=0;
    int flag=0;
    
    for (i=0; i<longitude; i++){
        if (correo[i]=='@'){
            flag=1;
        }
        if (flag==1){
            extencion[j]=correo[i];
            j++;
        }
        if (correo[i]==' '){
            printf("Los correos no pueden tener espacios\n");
            printf("Correo no valido\n\n");
            return 0;
        }
        
    }
    extencion[j]='\0';
    if (strcmp(extencion, "@gmail.com") == 0) { 
        printf("Correo valido\n\n");
        return 1;
    }
    else if (strcmp(extencion, "@hotmail.com") == 0) { 
        printf("Correo valido\n\n");
        return 1;
    }
    else{
        printf("Correo no valido\n\n");
        return 0;
    }
}
