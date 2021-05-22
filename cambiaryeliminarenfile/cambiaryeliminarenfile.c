#include <stdio.h>
#define MAX 100
#include <string.h>

void deleted(char* , char* );
void changed(char* , char* , char* );

//Palabra a eliminar y el archivo.txt

void changed (char* file, char* cambiar, char* cambio){
    FILE* sistema = fopen(file, "r");
    FILE* temp = fopen("temporal.txt", "a");
    int flag = 0; // 0 si no se cambio // 1 si cambio
    char line[MAX];
    char number[MAX];
    char name[MAX];
    char c;
    int i; //contadores
    int j;
    int k;
    int l;
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
                if (nameindicador==1&&line[j]!=']'){ // I use like flags yo read the '[' star to save, we read ']' stop to save in case of numbers
                    name[l]=line[j];
                    l++;
                }
                if (nameindicador==1&&line[j]==']'){
                    name[l]='\0';
                    nameindicador=0;
                    //printf("%s\n", name);
                }
                if (line[j]=='['){
                    nameindicador=1;
                }

                if (strcmp(name, cambiar)==0&&line[j]==']'){//the line[j]==']' is because we need to be sure that we read name and id
                    //este lo cambiaremos
                    fprintf(temp, "[%s]\n", cambio);
                    flag = 1;
                    printf("Cambio realizado\n");
                }
                if (strcmp(name, cambiar)!=0&&line[j]==']'){//the line[j]==']' is because we need to be sure that we read name and id
                    //este no lo cambiaremos
                    fprintf(temp, "[%s]\n", name);
                }

            }
        }
        else{
            line[i]=c;
            i++;
        }
    }
    fclose(sistema);
    fclose(temp);
    remove("frutasyverduras.txt");
    int ret;
    ret = rename("temporal.txt", file);

   /*if(ret == 0) {
      //si se renombro
   } else {
      //no se renombro
   }*/
   if (flag==0){
    printf("No se realizo ningun cambio\n");
   }
}

void deleted(char* eliminar, char* file){ //Palabra a eliminar y el archivo.txt
    FILE* sistema = fopen(file, "r");
    FILE* temp = fopen("temporal.txt", "a");
    char line[MAX];
    char number[MAX];
    char name[MAX];
    char c;
    int flag = 0;
    int i; //contadores
    int j;
    int k;
    int l;
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
                if (nameindicador==1&&line[j]!=']'){ // I use like flags yo read the '[' star to save, we read ']' stop to save in case of numbers
                    name[l]=line[j];
                    l++;
                }
                if (nameindicador==1&&line[j]==']'){
                    name[l]='\0';
                    nameindicador=0;
                    //printf("%s\n", name);
                }
                if (line[j]=='['){
                    nameindicador=1;
                }

                if (strcmp(name, eliminar)==0&&line[j]==']'){//the line[j]==']' is because we need to be sure that we read name and id
                    //este lo eliminaremos
                    flag=1;
                    printf("Eliminado\n");
                }
                if (strcmp(name, eliminar)!=0&&line[j]==']'){//the line[j]==']' is because we need to be sure that we read name and id
                    //este no lo eliminaremos
                    fprintf(temp, "[%s]\n", name);
                }

            }
        }
        else{
            line[i]=c;
            i++;
        }
    }
    fclose(sistema);
    fclose(temp);
    remove("frutasyverduras.txt");
    int ret;
    ret = rename("temporal.txt", file);

   /*if(ret == 0) {
      printf("Ready\n");
   } else {
      printf("Error: unable to rename the file");
   }
   */
   if (flag ==0){
    printf("No se elimino\n");
   }
}


int main()
{
    char eliminar[MAX];
    char cambiar[MAX];
    char cambio[MAX];
    FILE* input = fopen("frutasyverduras.txt", "w"); //open the "file" in the mode "w" con esto se creara el archivo
    fprintf(input, "[Manzana]\n");
    fprintf(input, "[Pera]\n");
    fprintf(input, "[Mango]\n");
    fprintf(input, "[Sandia]\n");
    fclose(input); //con esto se creara el archivo
    printf("Palabra a eiminar?\n");
    scanf("%s", eliminar);
    deleted(eliminar, "frutasyverduras.txt");
    printf("Palabra a cambiar? (cambiar, cambio)\n");
    scanf("%s %s", cambiar, cambio);
    changed("frutasyverduras.txt", cambiar, cambio); // void changed (char* file, char* cambiar, char* cambio)
    //printf("<%s> <%s> <%s>", eliminar, cambiar, cambio);

    return 0;
}
