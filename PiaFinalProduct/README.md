# Final Project: Medical Software
>Medical software is a technological tool that focuses on improving, assisting and supporting the daily activities of the management of a health center. So I decided to do a medical software using the C programming language.
>
>Link to the project [here](https://github.com/rulgamer03/C/tree/main/PiaFinalProduct).

## Table of Contents
* [Project plan](#Project-plan)
* [Contact](#Contact)
* [Cases](#Cases)
<!-- * [License](#license) -->

## Project plan
The tasks of my project will be:
* **Patient scheduling**: To do a patient scheduling we need the **name** or the **identification number** of the patient, the **hour**, the **day**, the **doctor's office** will he/she attended (I decide to use numbers) and the **reason** (Example:  headache) and save it in a .txt file.
* **Creating patient records**:  The program can **generate an identification number** save the name and genre, put this information in a .txt file.
* **Creating a summary of the doctor's appointment** with this information: height (cm), mass (kg), temperature in °C, respiratory rate (breaths per minute), blood pressure (mm Hg), heart rate (beats per minute) and calculate the body mass index (BMI). 
Write what is the disease of the patient, what drugs need to consume at which time and in what frequency. At the time that you write some information like temperature, the program prints in console if this is a normal temperature or it is a higher temperature, in a file you can write the "normal conditions" in order to change values in a faster and an easier way.
* **Percentage of patient with each disease** At the time that you do a doctor appointment the program asks you if you want to add a disease or more than one diseases on the statistics, if you says yes the program save in a file .txt for example 10 patients of 20 patients registered have X disease, then convert to a percentage 50% in this case.
## Cases

- **Register a patient**: The program asks you what is the name and the genre of the patient. The program generate the next file, (the id generate automatically i want to start with 1900000 but you can change it, you only need to change the value of FIRSTPIN 1900000)
>registered.txt
>
><1900000> [Angel Raul Chavez Carrillo] M
>
><1900001> [Carolina Carrillo Martinez] F
>

- **Set a date for a doctor's appointment:** the program asks you the name and the id of the patient, (the patient must be registered previously) . If he/she is not in the file "registered.txt" or you write something wrong the name or the id, you go to the menu, now if user and pin are correct, the program asks you the hour, the day,  the doctors office number.
>Name: Angel Raul Chavez Carrillo
>
>Hour: 12:12
>
>Day: 12/12/2021
>
>Doctor's office number: 120
>
>Reason: 
>
>Fiver
>
>Flu
>
- **Doctors appointment:** The program asks you the name and the id.  If he/she is not in the file "registered.txt" or you write something wrong the name or the id, you go to the menu. Now if user and pin are correct, the program asks you the height and the mass, the program calculate the Body Mass index (BMI), you write the temperature, respiratory rate, systolic blood pressure and heart rate, when you write one value, the program compare it, using **if** conditions, for example say "high temperature" if the patient temperature is greater than 37.5. If you don't like these values, you can change them in the function "configuration".
These values will be printed in a text file. At the moment of the comparisons, we read this file and save these values in a array **float  information[36]** because we have 36 values in the txt file.

>Angel Raul Chavez Carrillo.txt
>
>Name: Angel Raul Chavez Carrillo
>
>Height: 167.000
>
>Mass: 49.300
>
>Body Mass Index: 17.677
>
>Temperature: 40.000
>
>Respiratory rate: 27
>
>Systolic blood pressure: 120.000
>
>Diastolic blood pressure: 80.000
>
>Heart rate: 70.000
>
Observations:
Fiver
rise in body temperature above the normal
temperature
>
Medicines:
Ibuprofen 200 mg
tablets 3 times a day

- **Statistics:** When you are in a doctor's appointment, the program asks you if you want to add some disease to the statics, you can write the disease if you want and a X when you don't want. Here a example

>Asthma
>
>Flu
>
>Fiver
>
>X

Now when you write a disease, the program write it in a txt file "counting for statistics.txt", when you select the option **6. Exit**, the program count each disease, generate two txt files:

![](https://github.com/rulgamer03/C/blob/main/PiaFinalProduct/graph.png?raw=true)


**Image 1: ** graphstatistics.txt

>
>textstatistics.txt
>
><006>/<009> [Asthma]
>
><002>/<009> [Flu]
>
><003>/<009> [Fiver]

We print the file **textstatistics.txt** in console at the end of the program.

- **View registered patients:** We print the file **registered.txt** in console.

- **View a specific txt file:** You write the name of the file that you want to see in console.

## Contact
You can contact me in discord as  **rulgamer07#7096** , in **my personal profile Instagram:** [here](https://www.instagram.com/bad_ruly/) or in the page do in colaboration with my friends **Master Engineer** our Instagram [here](https://www.instagram.com/masterengineer_oficial/?hl=es-la) and our facebook [here](https://www.facebook.com/MasterEngineerOficial/?notif_id=1609219250768490&notif_t=page_fan&ref=notif).
