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
    printf("Se a registrado al usuario <%s> con el password <%s>\n", u, p);
    temp->left = temp->right = NULL;
    return temp;
}
 
// A utility function to do inorder traversal of BST
void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%s ", root->user);
        inorder(root->right);
    }
}
 
// Change status to 0 to later delete
void change(struct node* root, char* u, char* p, int* f) // Root, user, password, flag if is 1 we can use eliminate function later
{
    if (root != NULL) {
        inorder(root->left);
        if (strcmp(root->user, u)==0&&strcmp(root->password, p)==0){
         *f = 1;
          printf("Eliminado\n");
        }
        inorder(root->right);
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
 
// Driver Code
int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct node* root = NULL;
    int flag;
    
    flag=0;


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
    
 
    return 0;
}
