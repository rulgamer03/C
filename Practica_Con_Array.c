#include <stdio.h>

int main()
{
    int n, k;
    int x='X';
    
    printf("valor de n\n");
    scanf("%d", &n);
    int arr[n];
  
    for (int i =0; i<n; ++i){
        printf("Escribe el numero que ocupara la posicion %d\n", i);
        scanf("%d", &arr[i]);
    }
    
    printf("valor de k\n");
    scanf("%d", &k);

    for (int i=0; i<n; ++i){
        if ((arr[i]%k)==0){ // Si es un numero divisible
        printf("%d ", arr[i]);
        }
        else{ // Si no 
            printf("X ");
        }
    }
    return 0;
}

/*
valor de n                                                        
4                                                                 
Escribe el numero que ocupara la posicion 0                       
2                                                                 
Escribe el numero que ocupara la posicion 1                       
4                                                                 
Escribe el numero que ocupara la posicion 2                       
7                                                                 
Escribe el numero que ocupara la posicion 3                       
8                                                                 
valor de k                                                        
2                                                                 
2 4 X 8  
*/
