#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define FALSE 0
#define TRUE 1
#define MAX 999
#define LOTOFTEXT 0
void date(); // Set a date for a doctor’s appointment
void write(char* ); //Function to write a lot of text in a .txt file
void doctor(); 
void configuration(); // The program create a file vitalsigns.txt, with the normal values of some vitalsigns
int main()
{
    configuration(); 
    // The program create a file vitalsigns.txt, with the normal values of temperature // breathing frequency children // blood pressure and heart rate
    // if you don't like these values you can change these values manually
    int option; // Option that you select in the menu 
    int end = FALSE; // If is TRUE the while and the program end 
    while(end==FALSE){
        printf ("Select a option: \n1. Set a date for a doctor’s appointment\n2. Doctor’s appointment\n3. Exit\n");
        scanf("%d", &option);
        if (option==1){
            date(); 
        }
        else if (option==2){
            doctor();
        }
        else if (option==3){
            end=TRUE; //end the program
        }
        else{
            printf("This option does not exist\n\n");
        }
    }

    return 0;
}

void configuration ()
{
    FILE* input = fopen("vitalsigns.txt", "w");
    fprintf(input, "temperature 36 37.5\n"); //Temperature low value / high value
    fprintf(input, "breathing_frequency_children_under_one_year 30 40\n"); //low / high value 
    fprintf(input, "breathing_frequency_children_under_six_years 25 30\n"); //low / high value
    fprintf(input, "breathing_frequency_children 20 25\n"); //low / high value
    fprintf(input, "breathing_frequency_adults 16 20\n"); //low / high value
    fprintf(input, "breathing_frequency_old_man 12 16\n"); //low / high value
    fprintf(input, "normal_systolic_blood_pressure 120 120\n"); // in this case we only have 1 value
    fprintf(input, "normal_diastolic_blood_pressure 80 80\n"); // in this case we only have 1 value
    fprintf(input, "hypertension_systolic_blood_pressure 120 139\n");
    fprintf(input, "hypertension_distolic_blood_pressure 80 89\n");
    fprintf(input, "hypertension1_systolic_blood_pressure 140 139\n");
    fprintf(input, "hypertension1_distolic_blood_pressure 90 99\n");
    fprintf(input, "hypertension2_systolic_blood_pressure 160 160\n"); //greater than 
    fprintf(input, "hypertension2_distolic_blood_pressure 100 100\n"); // greater than 
    fprintf(input, "heart_rate_children_under_one_year 120 160\n");
    fprintf(input, "heart_rate_children  80 100\n");
    fprintf(input, "heart_rate_adult  60 80\n");
    fprintf(input, "heart_rate_old_man  60 60\n"); //less than 
    fclose(input);
}

void write(char* file){ //Function to write a lot of text in a .txt file
  long nc;
  char c;
  FILE* input = fopen(file, "a");
  for (nc = 0; (c = getchar()) != EOF; nc++) {
     if (c>0&&c!=127){ //All IN ASCII IS POSITIVE I ADD !=127 because is when we delete something 
     //https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html?fbclid=IwAR1bXZPf8WZSj-jKC3w3RLoeAS5hZJ7eVQ7mDORFZ_kzpb1ZDR-MHy1TSbo
     //descripcion[nc]=c; //TESTING 
      fprintf(input, "%c", c);
     }
  }
 
  printf ("\nReady\n\n");
  fprintf(input, "\n");
  fclose(input);
}

void date(){
    char name[MAX];
    char secondname[MAX];
    char flastname[MAX];
    char mlastname[MAX];
    int hour;
    int min;
    int day;
    int month;
    int year;
    int doctorsoffice;
    printf ("Name:\n");
    scanf("%s %s %s %s", name, secondname, flastname, mlastname); 
    do {
    printf ("Hour:\n");
    scanf("%d %d", &hour, &min);
    } while (hour<0||hour>23||min<0||min>60);
    do {
    printf ("Day:\n");
    scanf("%d %d %d", &day, &month, &year);
    } while (day<1||day>31||month<1||month>12||year<2021||year>2032);
    printf ("Doctor's office number:\n");
    scanf("%d", &doctorsoffice);
    FILE* date = fopen("date.txt", "a"); 
    if (tolower(secondname[0])=='x'&&strlen(secondname)==1){ //Only have 1 name
        fprintf(date, "Name: %s %s %s\nHour: %d:%d\nDay: %d/%d/%d\nDoctor's office number: %d\n", name, flastname, mlastname, hour, min, day, month, year, doctorsoffice);
    }
    else{ //Have 2 names
        fprintf(date, "Name: %s %s %s %s\nHour: %d:%d\nDay: %d/%d/%d\nDoctor's office number: %d\n", name, secondname, flastname, mlastname, hour, min, day, month, year,doctorsoffice);
    }
    fprintf(date, "Reason:");
    fclose(date);
    printf ("Reason:\n");
    write("date.txt");
    printf("\n");
}

void doctor(){
    char name[MAX];
    char secondname[MAX];
    char flastname[MAX];
    char mlastname[MAX];
    float height;
    float mass;
    float temperature;
    float BMI; //Body Mass Index/
    char referencename[MAX];
    int number1;
    int number2;
    int i;
    int information[36];
    printf ("Name:\n");
    scanf("%s %s %s %s", name, secondname, flastname, mlastname);
    printf ("Height (cm):\n");
    scanf("%f", &height);
    printf ("Mass: (kg):\n");
    scanf("%f", &mass);
    height = height/100;
    BMI=mass/(pow(height, 2));
    printf ("The body mass index (BMI) is %.4f\n", BMI);
    printf ("Temperature: (°C):\n");
    scanf("%f", &temperature);
    FILE* readvitalsigns = fopen("vitalsigns.txt", "r");
    for (i=-1; fscanf(readvitalsigns, "%s %d %d\n", referencename, &number1, &number2)==3; i++){
        information[i+1]=number1;
        information[i+2]=number2;
    }
    
    for (i=0;i<36; i++){
        printf("%d\n", information[i]);
    }
    fclose (readvitalsigns);
    printf("\n");
}
