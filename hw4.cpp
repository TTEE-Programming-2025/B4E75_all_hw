#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

struct Student {
    char name[50];
    int id;
    int math;
    int physics;
    int english;
    float average;
};

struct Student students[MAX];
int studentCount = 0;

int confirmContinue();
int login();
void showMenu();
void enterGrades();
void displayGrades();
void searchGrade();
void rankGrade();

int confirmContinue() { 
    char choice;
    while (1) {
        printf("Continue? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            system("cls");
            return 1;
        } else if (choice == 'n' || choice == 'N') {
            printf("Exiting...\n");
            return 0;
        } else {
            printf("Please enter y or n\n");
        }
    }
}

int login() {
    int pwd, attempts = 0;
    const int correctPwd = 2025;

    while (attempts < 3) {
        printf("?????????????????????????????????????????\n");
        printf("?????????????????????????????????????????\n");
        printf("?????????????????????????????????????????\n");
        printf("????????????          ???????????????????\n");
        printf("??????????? ?????????? ??????????????????\n");
        printf("?????????? ????????????  ????????????????\n");
        printf("????????? ????????????? ?????????????????\n");
        printf("??????????????????????? ?????????????????\n");
        printf("?????????????????????? ??????????????????\n");
        printf("????????????????????? ???????????????????\n");
        printf("???????????????????? ????????????????????\n");
        printf("??????????????????? ?????????????????????\n");
        printf("?????????????????? ??????????????????????\n");
        printf("????????????????? ???????????????????????\n");
        printf("?????????????????????????????????????????\n");
        printf("?????????????????????????????????????????\n");
        printf("????????????????? ???????????????????????\n");
        printf("????????????????? ???????????????????????\n");
        printf("?????????????????????????????????????????\n");
        printf("?????????????????????????????????????????\n"); 
        printf("Enter the 4-digit password: ");
        scanf("%d", &pwd);
        if (pwd == correctPwd) {
            printf("Welcome!\n");
            return 1;
        } else {
            printf("Wrong password!\n");
            attempts++;
        }
    }
    printf("Attempt failed...system ending...\n");
    return 0;
}

void showMenu() {
    printf("-------[Grading system]-------\n"); 
    printf("| a. : Enter grades          |\n");
    printf("| b. : Display grades        |\n");
    printf("| c. : Search grades         |\n");
    printf("| d. : Ranking grades        |\n");
    printf("| e. : Exit                  |\n");
    printf("------------------------------\n");    
}

void enterGrades() { 
    int n;
    system("cls");
    printf("Enter the number of students(5~10): ");
    scanf("%d", &n);
    if (n < 5 || n > 10) {
        printf("Too much/less of the student.\n");
        return;
    }
    studentCount = n;
    for (int i = 0; i < n; i++){
        printf("Name of the %d student: ", i + 1);
        scanf("%s", students[i].name);

        printf("Enter ID(Six-digit number): ");
        scanf("%d", &students[i].id);
        if(students[i].id < 100000 || students[i].id >  999999) {
            printf("Wrong format of student ID.\n");
            i--;
            continue;
        }

        printf("Enter Math grade(0~100): ");
        scanf("%d", &students[i].math);
        if (students[i].math < 0 || students[i].math > 100) {
            printf("Wrong format of grade.\n");
            i--;
            continue;
        }

        printf("Enter Physics grade(0~100): ");
        scanf("%d", &students[i].physics);
        if (students[i].physics < 0 || students[i].physics > 100) {
            printf("Wrong format of grade.\n");
            i--;
            continue;
        }

        printf("Enter English grade(0~100): ");
        scanf("%d", &students[i].english);
        if (students[i].english < 0 || students[i].english > 100) {
            printf("Wrong format of grade.\n");
            i--;
            continue;
        }

        students[i].average = (students[i].math + students[i].physics + students[i].english) / 3.0f;
    }
}

void displayGrades() {
    system("cls");
    printf("Name\tID\tMath\tPhysics\tEnglish\tAverage\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%.1f\n",
        students[i].name, students[i].id, students[i].math, students[i].physics, students[i].english, students[i].average);
    }
    getchar(); getchar();
}

void searchGrade() {
    char target[50];
    int found = 0;
    system("cls");
    printf("Who's grade do you want to look up?: ");
    scanf("%s", target);
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].name, target) == 0) {
            printf("Found it!!\n");
            printf("Name: %s\tId: %d\n", students[i].name, students[i].id);
            printf("Math: %d\tPhysics: %d\tEnglish: %d\n", students[i].math, students[i].physics, students[i].english);
            printf("Average: %.1f\n", students[i].average);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("This student does not exist in the system!\n");
    }
    getchar(); getchar();
} 

void rankGrade() {
    system("cls");
    struct Student temp;
    for(int i = 0; i < studentCount - 1; i++) {
        for(int j = i + 1; j < studentCount; j++) {
            if (students[i].average < students[j].average) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    } 
    printf("Name\tID\tAverage\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%s\t%d\t%.1f\n", students[i].name, students[i].id, students[i].average);
    }
    getchar(); getchar();
}

int main() {
    if(!login()) return 0;
    char input;
    while(1) {
        system("cls");
        showMenu();
        printf("Please enter your choice: ");
        scanf(" %c", &input);

        switch (input) {
            case 'a':
                enterGrades();
                break;
            case 'b':
                displayGrades();
                break;
            case 'c':
                searchGrade();
                break;
            case 'd':
                rankGrade();
                break;
            case 'e':
                if(!confirmContinue()){
                    return 0;
                }
                break;
            default:
                printf("Wrong choice enter again!\n");
                getchar(); getchar();                
        }
    }
    return 0;
}

// Final project of the semester - combining arrays and structs made it much harder, but I managed to complete it through hard work!
// The last project this semester was far more complex than before, but with persistent learning, I got it done!
// This project mixed arrays and structs, making it quite challenging, but the effort paid off in the end!
// The semester's final project was significantly tougher, but after continuous study and practice, I succeeded!
// Combining arrays and structs made this project trickier than previous ones, but I still finished it strong!
// The ultimate challenge this semester - higher complexity, but through steady practice, I made it work!
// This project's difficulty spiked with arrays + structs, but I pushed through and solved it!
// The semester's capstone project was way more complex, but after deep study, I cracked it!
// Final mission: arrays + structs = extreme difficulty, but perseverance led to success!
// The last test of the semester - more complex logic, but persistence made it a win!
