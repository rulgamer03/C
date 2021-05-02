#include <stdio.h>
#include <time.h>
int main()
{
    time_t tiempoahora;
    time(&tiempoahora);
    printf("%s\n", ctime(&tiempoahora));

    struct tm *mitiempo = localtime(&tiempoahora);
    printf("%d/%d/%d", mitiempo->tm_mday, mitiempo->tm_mon+1, mitiempo->tm_year+1900); //tm year desde 1900 en mes 0 es enero


    return 0;
    
}
