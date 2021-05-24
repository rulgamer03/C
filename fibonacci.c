#include <stdio.h>
#define MAX 20

int main()
{
    int i=2, n1=0,n2=1,n3;
    printf("\n%d %d",n1,n2);//printing 0 and 1    
    while (i<MAX){
        n3=n1+n2;    
        printf(" %d",n3);    
        n1=n2;    
        n2=n3;   
        ++i;
    }
    return 0;
}
