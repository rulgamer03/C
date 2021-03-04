#include <stdio.h>
int main() {
  int i;
  for (i = A; i >= B; i = i - C);
  printf("%d\n", i);
}
//where A = 57, B = 14, and C = 10.
//output 7
