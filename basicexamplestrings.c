#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
int main()
{
 printf("%%15s = %15sn\n","hello");
 printf("%%15s = %14sn\n","hell");
 printf("%%15s = %13sn\n","hel");
 printf("%%15s = %12sn\n","he");
 printf("%%15s = %11sn\n","h");
 printf("%%15s = %10sn\n","hello");
 printf(" %%9s = %9sn\n","hello");
 printf(" %%8s = %8sn\n","hello");
 printf(" %%7s = %7sn\n","hello");
 printf(" %%6s = %6sn\n","hello");
 printf(" %%5s = %5sn\n","hello");
 printf(" %%4s = %4sn\n","hello");
 return(0);
}
