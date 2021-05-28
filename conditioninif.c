/*
How many numbers do you want?
3
Write the <1> number:
100
Number equal 100
Write the <2> number:
20
Number less than 100
Write the <3> number:
800
Number higher than 100

*/

#include <stdio.h>
int main()
{
    int n;
    int i;
    printf("How many numbers do you want?\n");
    scanf("%d", &n);
    int array[n]; // array with n spaces
    for (i=0; i<n; i++){ //for condition
        printf ("Write the <%d> number:\n", i+1);  //we add 1 to i , 0+1 -> 1 
        scanf("%d", &array[i]); // we ask for the number that we write in the position i, remember that we begin with 0
        printf (array[i] == 100 ? "Number equal 100\n" : array[i] > 100 ? "Number higher than 100\n" : "Number less than 100\n"); // if is equal to 100 print "equal" else -> if is higher than 100 print "higher" else -> print "less"
    }

    return 0;
}
