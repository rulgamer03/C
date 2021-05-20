/*
    Angel Raul Chavez Carrillo
    Mechatronic Engineer
    FIME
    Read the main.c file in thie same folder 
*/
void date(); // Set a date for a doctor’s appointment
void write(char* ); //Function to write a lot of text in a .txt file
void doctor(); // Function to a Doctors appointment
void header(); //Print a header in console
void headerfile(char* ); //Print a header in a file in my case name.txt -> Angel Raul Chavez Carrillo.txt
void configuration(); // The program create a file vitalsigns.txt, with the normal values of some vitalsigns
int saca(char*); //In order to get a line
void registerpatient();// Register a patient in the registered file
int count(char* ); //count the lines
int search(char* , int , char*); //Return 1 if the pin and the user are good, Return 0 if something is bad
int printfile(char* ); //print a file in console
int countdiseases();

// #define DEBUG 1

typedef struct treenode { //This part is used to count the diseases and do "graphs"
  char* word; // write a word
  unsigned int counter; // counter
  unsigned int depth;
  struct treenode* izq;
  struct treenode* der;
} node;
