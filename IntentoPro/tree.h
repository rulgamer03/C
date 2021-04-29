#define MAX 80
typedef struct treenode {
  char* user; //usuario 
  char* password; //contraseña 

  struct treenode* leftChild;
  struct treenode* rightChild;
  unsigned int depth;
} node;

char linea[MAX], password[MAX], user[MAX];
int saca(); // Function that give us the line
void get (char l[MAX],char p[MAX],char u[MAX]); /* Function that give us the user and the password and agrega gente*/
node* insert(char* u, char* p, node* pos, int d); // Funcion añade usuario
node* minValueNode(node* node);
node* deleteNode(node* position, char* u, char* p,  int* n);
void alpha(node* position); // Funcion que ordena alfabeticamente
/* */
