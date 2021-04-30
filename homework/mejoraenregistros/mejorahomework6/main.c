// C program to demonstrate
// delete operation in binary
// search tree
#include <stdio.h>
#include <string.h> // strstr
#include <stdlib.h> // malloc & free
#include <ctype.h> // isspace & tolower
#include "tree.h"


// A utility function to create a new BST node
struct node* newNode(int s, char* u, char* p) /// status always 0 in order to insert later u, p
{
    struct node* temp
        = (struct node*)malloc(sizeof(struct node));
    temp->status = s;
    temp->user = u;
    temp->password = p;
    printf("Se a registrado al usuario <%s> con el password <%s>\n\n", u, p);
    temp->left = temp->right = NULL;
    return temp;
}
 
// A utility function to do inorder traversal of BST
void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf(" > %s\n", root->user);
        
        inorder(root->right);
    }
}
 
// Change status to 0 to later delete
void change(struct node* root, char* u, char* p, int* f) // Root, user, password, flag if is 1 we can use eliminate function later
{
    if (root != NULL) {
        change(root->left, u, p, f);
        if (strcmp(root->user, u)==0&&strcmp(root->password, p)==0){
         *f = 1;
          printf("Eliminado\n\n");
        }
        change(root->right, u, p, f);
    }
} 

void find(struct node* root, char* u, int* f) // find a user
{
    if (root != NULL) {
        find(root->left, u, f);
        if (strcmp(root->user, u)==0){
         *f = 1;
          printf("El usuario ya estaba registrado\n\n");
        }
       find(root->right, u, f);
    }
} 

/* A utility function to
   insert a new node with given key in
 * BST */
struct node* insert(struct node* node, int s, char* u, char* p)  /// status always 0 in order to insert u, p
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(s, u, p); //newNode(int s, char* u, char* p) 
    if (strcmp(node->user, u)==0){
        printf("El usuario ya estaba registrado\n\n");
        return NULL;
    }
    /* Otherwise, recur down the tree */
    if (strcmp(node->user, u)>0)
        node->left = insert(node->left, s, u, p);
    else
        node->right = insert(node->right, s, u, p);
 
    /* return the (unchanged) node pointer */
    return node;
}
 
/* Given a non-empty binary search
   tree, return the node
   with minimum key value found in
   that tree. Note that the
   entire tree does not need to be searched. */
struct node* minValueNode(struct node* node)
{
    struct node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}
 
/* Given a binary search tree
   and a key, this function
   deletes the key and
   returns the new root */
struct node* deleteNode(struct node* root, char* u)
{
    // base case
    if (root == NULL)
        return root;
 
    // If the key to be deleted
    // is smaller than the root's
    // key, then it lies in left subtree
    if (strcmp(root->user, u)>0)
        root->left = deleteNode(root->left, u);
 
    // If the key to be deleted
    // is greater than the root's
    // key, then it lies in right subtree
    else if (strcmp(root->user, u)<0)
        root->right = deleteNode(root->right, u);
 
    // if key is same as root's key,
    // then This is the node
    // to be deleted
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children:
        // Get the inorder successor
        // (smallest in the right subtree)
        struct node* temp = minValueNode(root->right);
 
        // Copy the inorder
        // successor's content to this node
        root->user = temp->user;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->user);
    }
    return root;
}


int saca() { // Function that give us the line, modification of a SATU ELISA SCHAEFFER  code Longest2.c nocomment.c
          
  extern char linea[];
  int c, i = 0;

  for (; i < MAX - 1 && (c = getchar()) != EOF && c != '\n';) {

        linea[i++] = c;

  }
  linea[i] = '\0'; // caracter end of string
  return c == EOF;
}

void get (char l[MAX],char p[MAX],char u[MAX]){
    int a = 4, b = 0, c=0;
    while (l[a]!=' '&&l[a]!='\t'){
        u[b]=l[a];
        b++;
        a++;
    }
    u[b]='\0';
    int longitud = strlen(u);
    a++;
    while (l[a]!=' '&&l[a]!='\t'&&l[a]!='\0'){
       p[c]=l[a];
       c++;
       a++;
    }
    p[c]='\0';
    int longitud2 = strlen(p);

}

// Driver Code
int main()
{
    
    struct node* root = NULL;
    int flag;
    
    flag=0;
    
    int i;
    int j;
    int l = 0;
    int contadorespacios =0; // si cuenta 2 espacios es muy probable que hiciste bien tu entrada
    char* u;//// n es el tamaño del arreglo unidimencional puede ver mas de esto en argdemo.c
    char* p;
    printf("Bienvenido\n");
    printf("Para agregar un usuario usa: add usuario contraseña\n");
    printf("Para eliminar un usuario usa: del usuario contraseña\n");
    printf("Para ver los nombres de los usuarios acomodados alfabeticamente usa: view\n");
    printf("Este programa toma en cuenta mayusculas y minusculas (USUARIO no es lo mismo que usuario)\n");
    printf("Asegurate que tu entrada este correcta antes de dar enter\n\n");
  while ((l = saca()) == 0) {
      contadorespacios=0;
    for (j=0; j<MAX; j++){
        if (linea[j]==' '||linea[j]=='\t'){
            contadorespacios++;
        }
    }
    if (strstr(linea, "del") != NULL&&strlen(linea)>=7&&contadorespacios==2) { // if we found  "del" we need to delete
      get(linea, password, user);
      u = (char*)malloc(sizeof(int*) * strlen(user));
      p = (char*)malloc(sizeof(int*) * strlen(password));
      for (i=0; i<strlen(user);i++){
          u[i]=user[i];
      }
      for (i=0; i<strlen(password);i++){
          p[i]=password[i];
      }
      /// De este modo es igual usar p o password 
      flag = 0;
      change(root, u, p, &flag); // Root, user, password, flag if is 1 we can use eliminate function later
      if (flag==1){
          //node* deleteNode(struct node* root, char* u)
          root = deleteNode(root, u);
      }
      else{
          printf("No se elimino\n\n");
      }
      flag=0;
      contadorespacios=0;
    }
    
    else if (strstr(linea, "add") != NULL&&strlen(linea)>=7&&contadorespacios==2) { // if we found  "add" we need to add
      get(linea, password, user);
      u = (char*)malloc(sizeof(int*) * strlen(user));
      p = (char*)malloc(sizeof(int*) * strlen(password));
      for (i=0; i<strlen(user);i++){
          u[i]=user[i];
      }
      for (i=0; i<strlen(password);i++){
          p[i]=password[i];
      }
      /*
      printf ("%s %s end\n", password, user);
      printf ("%s %s end\n", p, u);*/
      /// De este modo es igual usar p o password 
      if (strlen(password)>0&&strlen(user)>0){
      //void find(struct node* root, char* u, int* f) 
      flag=0;
      find(root, u, &flag);
      if (flag==0){
	  root = insert(root, 0, u, p);
      }
	  contadorespacios=0;
      }
      else if (strlen(password)<=0||strlen(user)<=0){
          printf ("Checa tu entrada\n\n");
          contadorespacios=0;
      }
      }// aqui termina el add 
      
    else if (strstr(linea, "view") != NULL&&strlen(linea)==4) { // if we found  "show" we need to show
      inorder(root); //// Esta se queda asi
      printf("\n");
      contadorespacios=0;
    }
    else{
        printf("Checa tu entrada\n\n");
        contadorespacios=0;
    }
    
    
  }
    /*
    Examples
    //root = insert(root, 80); node* insert(struct node* node, int s, char* u, char* p)
    root = insert(root, 0, "Raul", "Contras");
    
    flag = 0;
    change(root, "Raul", "Contras", &flag); // Root, user, password, flag if is 1 we can use eliminate function later
    if (flag==1){
        //node* deleteNode(struct node* root, char* u)
        root = deleteNode(root, "Raul");
    }
    else{
        printf("No se elimino");
    }
    flag=0;
    
    printf("Inorder traversal of the modified tree \n");
    inorder(root); //// Esta se queda asi
    
    root = insert(root, 0, "Juan", "Gamer");
    printf("Inorder traversal of the modified tree \n");
    inorder(root); //// Esta se queda asi
    
    */
    return 0;
}
