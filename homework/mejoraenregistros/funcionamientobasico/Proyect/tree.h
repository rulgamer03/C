struct node {
    int status;
    char* user; //usuario 
    char* password; //contraseña 
    struct node *left, *right;
};

void inorder(struct node* );
void change(struct node* , char* , char* , int* );
struct node* insert(struct node* , int , char* , char* );
struct node* minValueNode(struct node* );
struct node* deleteNode(struct node* , char* );
