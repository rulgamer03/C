#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#define FALSE 0
#define TRUE 1
#define MAX 999
#define LOTOFTEXT 0
void date(); // Set a date for a doctor’s appointment
void write(char* ); //Function to write a lot of text in a .txt file
void doctor();
void header(); //Print a header in console
void headerfile(char* ); //Print a header in a file in my case name.txt -> Angel Raul Chavez Carrillo.txt
void configuration(); // The program create a file vitalsigns.txt, with the normal values of some vitalsigns
int main()
{
    header();
    configuration();
    // The program create a file vitalsigns.txt, with the normal values of temperature // breathing frequency children // blood pressure and heart rate
    // if you don't like these values you can change these values manually
    int option; // Option that you select in the menu
    int end = FALSE; // If is TRUE the while and the program end
    while(end==FALSE){
        printf ("Select a option: \n1. Set a date for a doctors appointment\n2. Doctors appointment\n3. Exit\n");
        scanf("%d", &option);
        if (option==1){ // Set a date for a doctors appointment
            date();
        }
        else if (option==2){ // Doctors appointment
            doctor();
        }
        else if (option==3){
            end=TRUE; //end the program
        }
        else{
            printf("This option does not exist\n\n"); //option does not exist
        }
    }

    return 0;
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
  FILE* input = fopen(file, "a"); //open the "file" in the mode "a"
  for (nc = 0; (c = getchar()) != EOF; nc++) {
     if (c>0&&c!=127){ //All IN ASCII IS POSITIVE I ADD !=127 because is when we delete something
     //https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html?fbclid=IwAR1bXZPf8WZSj-jKC3w3RLoeAS5hZJ7eVQ7mDORFZ_kzpb1ZDR-MHy1TSbo
      fprintf(input, "%c", c); //we print the character that read in the file
     }
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

    printf ("\nName:");
    gets (name);
    gets (name);
    printf("%s\n\n", name);

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

    fprintf(date, "Reason: (at the end press Ctrl + c )");
    fclose(date);
    printf ("\nReason:\n");
    write("date.txt");
    printf("\n");

}

void doctor(){ // Doctors appointment
    char name[MAX]; //Name of the patient
    float height; // cm
    float mass;  // kg
    float temperature; // Celcius degrees
    float bmi; //Body Mass Index/

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


    printf ("\nName:\n"); //give the name
    gets (name);
    gets (name);

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

    printf("\nWrite the Observations: (at the end press Ctrl + c )\n");
    write(filename);
    printf("\n");


    printf("Write the Medicines (at the end press Ctrl + c )\n");
    FILE* inputtwo = fopen(filename, "a"); //open the "file" in the mode "a"
    fprintf(inputtwo, "\nMedicines:\n");
    fclose(inputtwo);
    write(filename);
    printf("\n");
    char disease[MAX];
    printf("Do you want to add some disease to statistics\n");
    do {
        gets(disease);
    } while (disease[0]!='X' && strlen(disease)!=1);
    printf("\n");
}
