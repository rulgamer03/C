#include <stdio.h>
#include <ctype.h>
#define CAPACITY 80
#define INCOMPLETE -1
#define UNDEFINED INCOMPLETE
int name(char* target) {
  char c;
  int pos = 0;
  while (pos < CAPACITY) {
    c = getchar();
    if (isspace(c)) {
      target[pos] = '\0';
      return pos;
    }
    target[pos++] = c;
  }
  return INCOMPLETE;
}
int count(char* file) {
  int count = UNDEFINED;
  FILE* input = fopen(file, "r");
  if (input) {
    while ( !feof(input)) { // expression (a)
      if (fgetc(input)=='\n') { // expression (b)
        count++;
      }
    }
    count++; // last line
  }
  fclose(input);
  return count;
}
int main() {
  char filename[CAPACITY];
  do {
    printf("Define a file name (leave empty to quit): ");
    if (!name(filename)) {
      return 1;
    }
    int c = count(filename);
    if (c != UNDEFINED) {
      printf("File [%s] has %d lines.\n", filename, c);     
    } else {
      fprintf(stderr, "No such readable file.\n");
    }
  } while (1);
}
