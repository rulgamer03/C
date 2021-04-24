struct estudiante { /// Data estudiante
  unsigned int matr; /// Number for matricula 1234567, (0)987651
  char* pe; /// Study program (3 letters)
};

typedef struct estudiante alumno; // Just say alumno as a nickname 

void imprime(alumno); //print study information
