#include <stdio.h>
#include <math.h>
#define BASE 3
int main() {
  int a = 12;
  int d = log(a)/log(BASE)+1;
  printf("%d needs %d digits in base %d\n", a, d, BASE);
}
