/* 
    How to use?
    You don't need to make any txt file, the program will do it
    First register a patient, the program give a pin to the patient (option 3)
    Set a date the program check the user and the pin (option 4)
    Use option 4 at a moment of a doctors appointment, the program check the user and the pin, generate a file with the name of
    the patient
    Use option 5 to View a specific txt file
    Finally option 6 to Exit 

    ___  ___          _              _____            _                 
    |  \/  |         | |            |  ___|          (_)                
    | .  . | __ _ ___| |_ ___ _ __  | |__ _ __   __ _ _ _ __   ___ _ __ 
    | |\/| |/ _` / __| __/ _ \ '__| |  __| '_ \ / _` | | '_ \ / _ \ '__|
    | |  | | (_| \__ \ ||  __/ |    | |__| | | | (_| | | | | |  __/ |   
    \_|  |_/\__,_|___/\__\___|_|    \____/_| |_|\__, |_|_| |_|\___|_|   
                                                __/ |                  
                                               |___/                   

         By: Angel Raul Chavez Carrillo IMTC Mechatronic Engineer
         Thank you so much to my teacher Satu Elisa Schaeffer
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1
#define MAX 999 //Max of some array
#define FIRSTPIN 1900000 //Number of the first pin
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

typedef struct treenode {
  char* word;
  unsigned int counter;
  unsigned int depth;
  struct treenode* izq;
  struct treenode* der;
} node;

void erase(node* pos) {
  if (pos != NULL) {
    erase(pos->izq);
    erase(pos->der);
    free(pos->word);
    free(pos);
  }
  return;
}

void set_depth(node* pos, int d) {
  if (pos != NULL) {
    pos->depth = d;
#ifdef DEBUG
    printf("%s is at depth %d\n", pos->word, d);
#endif
    set_depth(pos->izq, d + 1);
    set_depth(pos->der, d + 1);
  }
}


node* insert(char* word, node* pos) {
  int cmp;
  if (pos == NULL) {
#ifdef DEBUG
    printf("%s recibe un nuevo nodo\n", word);
#endif
    pos = (node*)malloc(sizeof(node));
    pos->word = word;
    pos->depth = 0;
    pos->counter = 1;
    pos->izq = NULL;
    pos->der = NULL;
  } else {
#ifdef DEBUG
    printf("en %s, procesando %s\n", pos->word, word);
#endif
    cmp = strcmp(pos->word, word);
    if (cmp == 0) {
#ifdef DEBUG
      printf("%s incrementa su contador\n", pos->word);
#endif
      ++(pos->counter);
    } else if (cmp > 0) {
#ifdef DEBUGx
      printf("%s va a la izquierda en %s\n", word, pos->word);
#endif
      pos->izq = insert(word, pos->izq);
    } else { // cmp < 0
#ifdef DEBUG
      printf("%s va a la derecha en %s\n", word, pos->word);
#endif
      pos->der = insert(word, pos->der); // word is larger
    }
  }
#ifdef DEBUG
  printf("regresando desde %s\n", pos->word);
#endif
  return pos;
}

void show(node* pos, char prefix) {
  int i;
  char suffix = ' ';
  if (pos != NULL) {
    for (i = 0; i < pos->depth; i++) {
      printf(" ");
    }
    if (pos->izq == NULL && pos->der == NULL) { // no children
      suffix = '#'; // a leaf node (dead end)
    }
    printf("%c %s (%d) %c\n", prefix, pos->word, pos->counter, suffix);
    show(pos->izq, '<');
    show(pos->der, '>');
  }
  return;
}

void alpha(node* pos) {
  FILE* textstatics = fopen("textstatistics.txt", "a"); // here only text
  FILE* graphstatics = fopen("graphstatistics.txt", "a"); // here only text
  int total_patients;
  int number=20; //number of *
  int limit;
  
  total_patients=count("registered.txt");
  if (pos != NULL) {
    alpha(pos->izq);
    fprintf(textstatics, "<%03d>/<%03d> [%s]\n", pos->counter, total_patients, pos->word);
    int i = 0;
    if (total_patients>0){
        limit = (pos->counter*number)/total_patients; //if total_patients will be 0 will be a error
        fprintf(graphstatics, "|\n");
        fprintf(graphstatics, "|");
        for (i=0; i<limit;i++){
            fprintf(graphstatics, "*");
        }
        for (i=0; i<number-limit;i++){
            fprintf(graphstatics, " ");
        }
        fprintf(graphstatics, "  %03d/%03d [%s]\n", pos->counter, total_patients, pos->word);
        fprintf(graphstatics, "|\n");

    }
    printf("<%03d>/<%03d> [%s]\n", pos->counter,total_patients, pos->word);
    alpha(pos->der);
  }
  
  fclose(textstatics);
  fclose(graphstatics);
}

int countdiseases(){
  node* tree = NULL;
  FILE* general = fopen("counting for statistics.txt", "r");
  char c;
  char line[MAX];
  char* word;
    int i; //contadores
    int j;
    int k;
    int l;
    int something;
    i=0;
    int nameindicador=0;
    int numberindicador=0;
    while ((c = fgetc(general)) != EOF) {
        word = (char*)malloc(sizeof(char) * MAX);
        j=0;
        if (c == '\n') {
            line[i]='\0';
            i=0;
            k=0;
            l=0;
            for (j=0;j<strlen(line); j++){
                // Now with the name
                if (nameindicador==1&&line[j]!=']'){
                    word[l]=line[j];
                    l++;
                }
                if (nameindicador==1&&line[j]==']'){
                    word[l]='\0';
                    //printf("%s\n", name);
                    nameindicador=0;
                    tree = insert(word, tree);
                }
                if (line[j]=='['){
                    nameindicador=1;
                }
            }
        }
        else{
            line[i]=c;
            i++;
        }
    }
    //end while

  /*while (1) {

    tree = insert(word, tree);
  }
  */
  set_depth(tree, 0);
  //show(tree, '+');
  alpha(tree);
  erase(tree);
  return 0;
}


int saca(char* linea) { //This part is from longest.c
  //https://github.com/satuelisa/C/blob/main/Ch1/longest.c
  int c, i = 0;
  for (; i < MAX - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
    linea[i] = c;
  }
  linea[i] = '\0'; // caracter de terminacion de string
  return i; // cual fue el largo
}

int main()
{
    printf("\n");
    printf ("\t___  ___          _              _____            _                 \n");
    printf ("\t|  \\/  |         | |            |  ___|          (_)                \n");
    printf ("\t| .  . | __ _ ___| |_ ___ _ __  | |__ _ __   __ _ _ _ __   ___ _ __ \n");
    printf ("\t| |\\/| |/ _` / __| __/ _ \\ '__| |  __| '_ \\ / _` | | '_ \\ / _ \\ '__|\n");
    printf ("\t| |  | | (_| \\__ \\ ||  __/ |    | |__| | | | (_| | | | | |  __/ |   \n");
    printf ("\t\\_|  |_/\\__,_|___/\\__\\___|_|    \\____/_| |_|\\__, |_|_| |_|\\___|_|   \n");
    printf ("\t                                             __/ |                  \n");
    printf ("\t                                            |___/ \n");
    printf("\t By: Angel Raul Chavez Carrillo IMTC Mechatronic Engineer\n");
    printf("\t Thank you so much to my teacher Satu Elisa Schaeffer\n");
    printf("\n");
    FILE* general = fopen("counting for statistics.txt", "a");
    fclose(general);
    FILE* registered = fopen("registered.txt", "a");
    fclose(registered);
    header(); // Only print a header
    char specificname[MAX];
    configuration();
    // The program create a file vitalsigns.txt, with the normal values of temperature // breathing frequency children // blood pressure and heart rate
    // if you don't like these values you can change these values manually

    int option; // Option that you select in the menu
    int end = FALSE; // If is TRUE the while and the program end
    while(end==FALSE){
        printf ("Select a option: \n1. Set a date for a doctors appointment\n2. Doctors appointment\n3. Register a Patient\n4. View registered patients\n5. View a specific txt file\n6. Exit\n");
        scanf("%d", &option);
        if (option==1){ // Set a date for a doctors appointment
            date();
        }
        else if (option==2){ // Doctors appointment
            doctor();
        }
        else if (option==3){ // Register patient
            registerpatient();
        }
        else if (option==4){ //view registered patients
            printfile("registered.txt");
        }
        else if (option==5){ //print a specific file
            printf("Write the name of the .txt file that you want to open\nExample: counting for statistics.txt\nNote: if this file does not exists, it will be created\nBe sure to type .txt\n");
            saca(specificname);
            saca(specificname);
            FILE* specific = fopen(specificname, "a");
            fclose(specific);
            printf("\n");
            printfile(specificname);
            printf("\n");
        }
        else if (option==6){
            FILE* textstatics = fopen("textstatistics.txt", "w");
            fclose(textstatics);
            FILE* graphstatistics = fopen("graphstatistics.txt", "w");
            fclose(graphstatistics);
            printf("\n");
            countdiseases();
            end=TRUE; //end the program

        }
        else{
            printf("This option does not exist\n\n"); //option does not exist
        }
    }

    return 0;
}

int count(char* file){//count lines in a file
    FILE* sistema = fopen(file, "r"); //open to read
    char c;
    int count=0;
    while ((c = fgetc(sistema)) != EOF) {
    if (c == '\n') {
      count++; // let s check how many are registered
    }
    }
    return count;
}





int printfile(char* file){ //print a txt file in console
    FILE* sistema = fopen(file, "r");
    char line[MAX];
    char c;
    int i;
    i=0;
    while ((c = fgetc(sistema)) != EOF) {
        if (c == '\n') {
            line[i]='\0';
            printf("%s\n", line);
            i=0;
        }
        else{
            line[i]=c;
            i++;
        }
    }
    printf("\n");

    return 0;
}

int search(char* file, int idtosearch, char* nametosearch){ //Return 1 if the pin and the user are good, Return 0 if something is bad
    FILE* sistema = fopen(file, "r");
    char line[MAX];
    char number[MAX];
    char name[MAX];
    char c;
    int i; //contadores
    int j;
    int k;
    int l;
    int something;
    i=0;
    int nameindicador=0;
    int numberindicador=0;
    while ((c = fgetc(sistema)) != EOF) {
        j=0;
        if (c == '\n') {
            line[i]='\0';
            i=0;
            k=0;
            l=0;
            for (j=0;j<strlen(line); j++){
                if (numberindicador==1&&line[j]!='>'){
                    number[k]=line[j];
                    k++;
                }
                if (numberindicador==1&&line[j]=='>'){
                    number[k]='\0';
                    something=atof(number); //Convert to number
                    //printf("%d\n", something);
                    numberindicador=0;
                }
                if (line[j]=='<'){
                    numberindicador=1;
                }
                // Now with the name
                if (nameindicador==1&&line[j]!=']'){
                    name[l]=line[j];
                    l++;
                }
                if (nameindicador==1&&line[j]==']'){
                    name[l]='\0';
                    //printf("%s\n", name);
                    nameindicador=0;
                }
                if (line[j]=='['){
                    nameindicador=1;
                }
                if (strcmp(name, nametosearch)==0&&something==idtosearch){
                    printf("The user and the pin is good");
                    printf("\n");
                    return(1);
                }

            }
        }
        else{
            line[i]=c;
            i++;
        }
    }
    //end while
    printf("Check the user and the pin\n");
    printf("\n");
    return 0;
}




void registerpatient(){
    char name[MAX];
    char genre;
    int id;
    int large_number=FIRSTPIN; //The first pin will be 190000
    printf("Name: \n");
    saca (name); //I need to write two times saca because before this function we have a scanf
    //printf("<%s>\n", name); we obtain "" if we don't write two times the function "saca"
    saca (name);
    printf("Genre: \n");
    do{
    scanf("%c", &genre); //F or M
    } while (genre!='F'&&genre!='M');
    FILE* input = fopen("registered.txt", "a"); //open the "file" in the mode "a"
    id = count("registered.txt")+large_number;
    printf("\nThe pin will be <%d>\n\n", id);
    fprintf(input, "<%d> [%s] %c\n", id, name, genre);
    fclose(input); //Only create the file
}

void header(){
    time_t timenow;
    time(&timenow);
    struct tm *mytime = localtime(&timenow);
    switch(mytime->tm_wday){
        case 0:
        printf("Today it is Sunday \n");
        break;
        case 1:
        printf("Today is Monday\n");
        break;
        case 2:
        printf("Today is Tuesday \n");
        break;
        case 3:
        printf("Today is Wednesday\n");
        break;
        case 4:
        printf("Today is Thursday\n");
        break;
        case 5:
        printf("Today is Friday \n");
        break;
        case 6:
        printf ("Today is Saturday \n");
        break;
    }
    printf("Day: %d/%d/%d\n", mytime->tm_mday, mytime->tm_mon+1, mytime->tm_year+1900); //tm year desde 1900 en mes 0 es enero)
    printf("Hour: %d:%d\n\n", mytime->tm_hour, mytime->tm_min);
}

void headerfile(char* file){
    FILE* input = fopen(file, "a"); //open the "file" in the mode "a"
    time_t timenow;
    time(&timenow);
    struct tm *mytime = localtime(&timenow);
    switch(mytime->tm_wday){
        case 0:
        fprintf(input, "Today it is Sunday \n");
        break;
        case 1:
        fprintf(input, "Today is Monday\n");
        break;
        case 2:
        fprintf(input, "Today is Tuesday \n");
        break;
        case 3:
        fprintf(input, "Today is Wednesday\n");
        break;
        case 4:
        fprintf(input, "Today is Thursday\n");
        break;
        case 5:
        fprintf(input, "Today is Friday \n");
        break;
        case 6:
        fprintf (input, "Today is Saturday \n");
        break;
    }
    fprintf(input, "Day: %d/%d/%d\n", mytime->tm_mday, mytime->tm_mon+1, mytime->tm_year+1900); //tm year desde 1900 en mes 0 es enero)
    fprintf(input, "Hour: %d:%d\n\n", mytime->tm_hour, mytime->tm_min);
    fclose(input);

}
void configuration ()
{
    FILE* input = fopen("vitalsigns.txt", "w");
    fprintf(input, "temperature 36 37.5\n"); //Temperature low value / high value
    fprintf(input, "respiratory_rate_kid_under_one_year 30 40\n"); //low / high value
    fprintf(input, "respiratory_rate_kid_under_six_years 25 30\n"); //low / high value
    fprintf(input, "respiratory_rate_kid 20 25\n"); //low / high value
    fprintf(input, "respiratory_rate_adults 16 20\n"); //low / high value
    fprintf(input, "respiratory_rate_ancient 12 16\n"); //low / high value
    fprintf(input, "normal_systolic_blood_pressure 120 120\n"); // in this case we only have 1 value
    fprintf(input, "normal_diastolic_blood_pressure 80 80\n"); // in this case we only have 1 value
    fprintf(input, "hypertension_systolic_blood_pressure 120 139\n");
    fprintf(input, "hypertension_diastolic_blood_pressure 80 89\n");
    fprintf(input, "hypertension1_systolic_blood_pressure 139 140\n");
    fprintf(input, "hypertension1_distolic_blood_pressure 90 99\n");
    fprintf(input, "hypertension2_systolic_blood_pressure 160 160\n"); //greater than
    fprintf(input, "hypertension2_distolic_blood_pressure 100 100\n"); // greater than
    fprintf(input, "heart_rate_kid_under_one_year 120 160\n");
    fprintf(input, "heart_rate_kid  80 100\n");
    fprintf(input, "heart_rate_adult  60 80\n");
    fprintf(input, "heart_rate_ancient  40 60\n"); //Interval
    fclose(input);
}


void write(char* file){ //Function to write a lot of text in a .txt file
  long nc;
  char c;
  int j=0;
  FILE* input = fopen(file, "a"); //open the "file" in the mode "a"
  for (nc = 0; (c = getchar()) != EOF; nc++) {
     if (c>0&&c!=127&&c!=EOF&&j!=0||j==0&&c!=10){ //All IN ASCII IS POSITIVE I ADD !=127 because is when we delete something
     //https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html?fbclid=IwAR1bXZPf8WZSj-jKC3w3RLoeAS5hZJ7eVQ7mDORFZ_kzpb1ZDR-MHy1TSbo
     //if is the first time (j=0) and c is 0 (enter) yo don't enter in this if
      fprintf(input, "%c", c); //we print the character that read in the file
     }
     j++;
  }

  printf ("\nReady\n\n"); //print this message only to know that we write a lot of text in a .txt file
  fprintf(input, "\n");
  fclose(input); //close the file
}

void date(){
    char name[100];
    int hour;
    int min;
    int day;
    int month;
    int year;
    int doctorsoffice;
    int id;
    int continuee=0;
    printf ("\nName:\n");
    saca (name);
    saca (name);
    
    printf ("\nId:\n"); //give the id
    scanf("%d", &id);

    //Return 1 if the pin and the user are good, Return 0 if something is bad
    continuee=search("registered.txt", id,  name); //search(char* file, int idtosearch, char* nametosearch)
    //printf ("%d\n", continuee);

    if (continuee==1){
    

    do {
    printf ("\nHour:\n");
    scanf("%d %d", &hour, &min);
    } while (hour<0||hour>23||min<0||min>60);
    do {
    printf ("\nDay:\n");
    scanf("%d %d %d", &day, &month, &year);
    } while (day<1||day>31||month<1||month>12||year<2021||year>2032);
    printf ("\nDoctors office number:\n");
    scanf("%d", &doctorsoffice);
    FILE* date = fopen("date.txt", "a");


    fprintf(date, "Name: %s\nHour: %d:%d\nDay: %d/%d/%d\nDoctor's office number: %d\n", name, hour, min, day, month, year, doctorsoffice);

    fprintf(date, "Reason: \n");
    fclose(date);
    printf ("\nReason: (at the end press Ctrl + d in the case of online gdb)\n");
    write("date.txt");
    printf("\n");
    }
}



void doctor(){ // Doctors appointment
    char name[MAX]; //Name of the patient
    float height; // cm
    float mass;  // kg
    float temperature; // Celcius degrees
    float bmi; //Body Mass Index/
    int id;

    //When we read vitalsigns.txt we read a string and 2 numbers:
    char referencename[MAX];
    float number1;
    float number2;

    //Some information that the patient need to say to the doctor
    int respiratory_rate;
    float systolic_blood_pressure;
    float diastolic_blood_pressure;
    float heart_rate;

    // A counter for loop
    int i;

    float information[36]; // The file vital signs have 36 numbers and we put this information in the array


    FILE* readvitalsigns = fopen("vitalsigns.txt", "r"); // Read the file
    for (i=-1; fscanf(readvitalsigns, "%s %f %f\n", referencename, &number1, &number2)==3; i+=2){ //This part save in the array all the numbers in vitalsigns.txt
        information[i+1]=number1;
        information[i+2]=number2;
    }


    /*for (i=0;i<36; i++){
        printf("(%d) %.2f\n", i, information[i]); //print the array information
    }
    */

    fclose (readvitalsigns); //close the file

    /*
    HERE WE OBTAIN THE INFORMATION FROM THE PATIENTE AND COMPARE IT, WITH
    THE INFORMATION OF THE FILE FOR EXAMPLE
    THE PATIENT HAVE A TEMPERATURE OF 35 CELSIUS.
    THE FILE SAY THAT THE NORMAL TEMPERATURE IS BETWEEN 36 AND 37.5
    WITH AN IF WE CAN SAY THAT IS A "LOW TEMPERATURE"
    */

    /* Information in the array
    (0) 36.00
    (1) 37.50
    (2) 30.00
    (3) 40.00
    (4) 25.00
    (5) 30.00
    (6) 20.00
    (7) 25.00
    (8) 16.00
    (9) 20.00
    10) 12.00
    (11) 16.00
    (12) 120.00
    (13) 120.00
    (14) 80.00
    (15) 80.00
    (16) 120.00
    (17) 139.00
    (18) 80.00
    (19) 89.00
    (20) 139.00
    (21) 140.00
    (22) 90.00
    (23) 99.00
    (24) 160.00
    (25) 160.00
    (26) 100.00
    (27) 100.00
    (28) 120.00
    (29) 160.00
    (30) 80.00
    (31) 100.00
    (32) 60.00
    (33) 80.00
    (34) 40.00
    (35) 60.00
    */

    int continuee = 0;

    printf ("\nName:\n"); //give the name
    saca (name);
    saca (name);
    printf ("\nId:\n"); //give the id
    scanf("%d", &id);

    //Return 1 if the pin and the user are good, Return 0 if something is bad
    continuee=search("registered.txt", id,  name); //search(char* file, int idtosearch, char* nametosearch)
    //printf ("%d\n", continuee);

    if (continuee==1){

    int id_readed;
    char linea_readed[MAX];
    FILE* readingregistered = fopen("registered .txt", "r");  //Read the file registered in order to check if the id is in the system

    char filename[MAX]; //In order to create a file with the patient name
    strcat(strcpy(filename, name), ".txt"); //name.txt example -> Angel Raul Chavez Carrillo.txt
    //printf("%s\n", filename);

    //We write like a header in the file Angel Raul Chavez Carrillo.txt
    headerfile(filename);

    printf ("\nHeight (cm):\n"); //give the height
    scanf("%f", &height);
    printf ("\nMass: (kg):\n"); //give the mass
    scanf("%f", &mass);
    height = height/100; // convert cm to m
    bmi=mass/(pow(height, 2)); //obtain the BMI
    height = height*100; // convert m to cm
    printf ("\n > The body mass index (BMI) is %.4f\n\n", bmi);
    printf ("Temperature: ( C degrees ):\n"); //give the temperature
    scanf("%f", &temperature);



    //A LOT OF COMPARATIONS
    if (temperature<information[0]){
        printf("\n > Low body temperature (hypothermia)\n\n");
    }
    else if (temperature>information[1]){
        printf("\n > High temperature (fever) \n\n");
    }
    else{
        printf("\n > Normal temperature\n\n");
    }


    printf ("Respiratory rate: (Breaths per minute):\n"); //give the Respiratory rate
    scanf("%d", &respiratory_rate);


    // A LOT OF COMPARATIONS YOU CAN READ THE PRINTF TO KNOW WHAT DO...
    //Acording to a kid under one year
    if (respiratory_rate<information[2]){
        printf("\n > Low respiratory rate to a kid under one year\n");
    }
    else if (respiratory_rate>information[3]){
        printf("\n > High respiratory rate to a kid under one year\n");
    }
    else if (respiratory_rate>=information[2]&&respiratory_rate<=information[3]){
        printf("\n > Normal respiratory rate to a kid under one year\n");
    }
    //Acording to a kid under six years
    if (respiratory_rate<information[4]){
        printf(" > Low respiratory rate to a kid under six years\n");
    }
    else if (respiratory_rate>information[5]){
        printf(" > High respiratory rate to a kid under six years\n");
    }
    else if (respiratory_rate>=information[4]&&respiratory_rate<=information[5]){
        printf(" > Normal respiratory rate to a kid under six years\n");
    }
    //Acording to a kid
    if (respiratory_rate<information[6]){
        printf(" > Low respiratory rate to a kid\n");
    }
    else if (respiratory_rate>information[7]){
        printf(" > High respiratory rate to a kid\n");
    }
    else if (respiratory_rate>=information[6]&&respiratory_rate<=information[7]){
        printf(" > Normal respiratory rate to a kid\n");
    }
    //According to a adult
    if (respiratory_rate<information[8]){
        printf(" > Low respiratory rate to an adult\n");
    }
    else if (respiratory_rate>information[9]){
        printf(" > High respiratory rate to an adult\n");
    }
    else if (respiratory_rate>=information[8]&&respiratory_rate<=information[9]){
        printf(" > Normal respiratory rate to an adult\n");
    }
    //Acording to a old man
    if (respiratory_rate<information[10]){
        printf(" > Low respiratory rate to an ancient\n");
    }
    else if (respiratory_rate>information[11]){
        printf(" > High respiratory rate to an ancient\n\n");
    }
    else if (respiratory_rate>=information[10]&&respiratory_rate<=information[11]){
        printf(" > Normal respiratory rate to an ancient\n\n");
    }


    printf("Blood  pressure: Systolic blood pressure and diastolic  blood pressure\n"); //Give the Blood  pressure
    scanf("%f %f", &systolic_blood_pressure, &diastolic_blood_pressure);

    // A LOT OF COMPARATIONS YOU CAN READ THE PRINTF TO KNOW WHAT DO...
    if (systolic_blood_pressure==information[12]){
        printf ("\n > According to systolic blood pressure: Normal\n");
    }
    if (diastolic_blood_pressure==information[14]){
        printf (" > According to diastolic blood pressure: Normal\n");
    }
    if (systolic_blood_pressure>information[16]&&systolic_blood_pressure<information[17]){
        printf ("\n > According to systolic blood pressure: hypertension\n");
    }
    if (diastolic_blood_pressure>information[18]&&diastolic_blood_pressure<information[19]){
        printf (" > According to diastolic blood pressure: hypertension\n");
    }
    if (systolic_blood_pressure>information[20]&&systolic_blood_pressure<information[21]){
        printf ("\n > According to systolic blood pressure: hypertension type 1\n");
    }
    if (diastolic_blood_pressure>information[22]&&diastolic_blood_pressure<information[23]){
        printf (" > According to diastolic blood pressure: hypertension type 1\n");
    }
    if (systolic_blood_pressure>information[24]){
        printf ("\n > According to systolic blood pressure: hypertension type 2\n");
    }
    if (diastolic_blood_pressure>information[26]){
        printf (" > According to diastolic blood pressure: hypertension type 2\n");
    }

    printf("\nHeart rate: (beats per minute)\n"); //Give the heart rate
    scanf("%f", &heart_rate);

    // A LOT OF COMPARATIONS YOU CAN READ THE PRINTF TO KNOW WHAT DO...
    // Kid under one year
    if (heart_rate>information[28]&&heart_rate<information[29]){
        printf("\n > Normal heart rate to a kid under one year");
    }
    if (heart_rate>information[29]){
        printf("\n > High heart rate to a kid under one year");
    }
    if (heart_rate<information[28]){
        printf("\n > Low heart rate to a kid under one year");
    }
    // Kid
    if (heart_rate>information[30]&&heart_rate<information[31]){
        printf("\n > Normal heart rate to a kid\n");
    }
    if (heart_rate>information[31]){
        printf("\n > High heart rate to a kid\n");
    }
    if (heart_rate<information[30]){
        printf("\n > Low heart rate to a kid\n");
    }
    // Adult
    if (heart_rate>information[32]&&heart_rate<information[33]){
        printf(" > Normal heart rate to an adult\n");
    }
    if (heart_rate>information[33]){
        printf(" > High heart rate to an adult\n");
    }
    if (heart_rate<information[32]){
        printf(" > Low heart rate to an adult\n");
    }
    // Ancient
    if (heart_rate>information[34]&&heart_rate<information[35]){
        printf(" > Normal heart rate to an ancient\n");
    }
    if (heart_rate>information[35]){
        printf(" > High heart rate to an ancient\n");
    }
    if (heart_rate<information[34]){
        printf(" > Low heart rate to an ancient\n");
    }

    FILE* input = fopen(filename, "a"); //open the "file" in the mode "a"
    fprintf(input, "Name: %s\n", name);
    fprintf(input, "Height: %.3f\n", height);
    fprintf(input, "Mass: %.3f\n", mass);
    fprintf(input, "Body Mass Index: %.3f\n", bmi);
    fprintf(input, "Temperature: %.3f\n", temperature);
    fprintf(input, "Respiratory rate: %d\n", respiratory_rate);
    fprintf(input, "Systolic blood pressure: %.3f\n", systolic_blood_pressure);
    fprintf(input, "Diastolic blood pressure: %.3f\n", diastolic_blood_pressure);
    fprintf(input, "Heart rate: %.3f\n\n", heart_rate);
    fprintf(input, "Observations:\n");
    fclose(input);

    printf("\nWrite the Observations: (at the end press Ctrl + d in the case of onlinegdb)\n");
    write(filename);
    printf("\n");


    printf("Write the Medicines (at the end press Ctrl + d in the case of onlinegdb)\n");
    FILE* inputtwo = fopen(filename, "a"); //open the "file" in the mode "a"
    fprintf(inputtwo, "\nMedicines:\n");
    fclose(inputtwo);
    write(filename);
    printf("\n");
    char disease[MAX];
    printf("Do you want to add some disease to statistics\nWrite a single X->No // or write the disease\n");
    do {
        saca(disease);
        if (disease[0]!='X' && strlen(disease)!=1){ //if the string is not a "X"
            FILE* general = fopen("counting for statistics.txt", "a"); //open the "file" in the mode "a"
            fprintf(general, "[%s]\n", disease);
            fclose(general);
        }
    } while (disease[0]!='X' && strlen(disease)!=1); //While the string isn't a "X"
    printf("\n");
    }

}
