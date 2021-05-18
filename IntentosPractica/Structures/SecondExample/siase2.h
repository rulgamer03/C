struct estudiante {
  unsigned int matr;
  char* pe;
  unsigned int c; // Acces counter
};

typedef struct estudiante alumno;

void imprime(alumno*); // it now uses a pointer in order to modify a variable 
