#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void cleanScreen() {
    system("cls");
}

void multiplicationTable() {
    int n;
    char ch;
    
    cleanScreen();
    while(1) {
        printf("Enter a number:");
        if(scanf("%d", &n) != 1) {
            while((ch = getchar()) != '\n');
            printf("Warning: Invalid input. Enter again:\n");
            continue;
        }
        
        if(n >= 1 && n <= 9) {
            cleanScreen();
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= i; j++) {
                    printf("%d*%d=%2d ", j, i, i*j);
                }
                printf("\n");
            }
            printf("\nPress any key to continue...");
            getch();
            cleanScreen();
            return;
        }
        else {
            printf("Warning: Enter again:\n");
        }
    }
}

void drawTriangle(char ch) {
    for(int i = ch; i >= 'a'; i--) {
        for(int j = i; j <= ch; j++) {
            printf("%c", j);
        }
        printf("\n");
    }
}

void triangleOption() {
    char ch;
    cleanScreen();
    while(1) {
        printf("Enter character between a and n:");
        while(getchar() != '\n');
        scanf("%c", &ch);

        if(ch >= 'a' && ch <= 'n') {
            cleanScreen();
            drawTriangle(ch);
            printf("\nPress any key to continue...");
            getch();
            cleanScreen();
            return;
        }
        else {
            printf("Warning: Enter again\n");
            while(getchar() != '\n');
        }
    }
}

int main() {
    int choice;
    while(1) {
        printf("1. Multiplication Table\n");
        printf("2. Character Triangle\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                multiplicationTable();
                break;
            case 2:
                triangleOption();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice\n");
                while(getchar() != '\n');
        }
    }
    return 0;
}
int confirmContinue() { // Comfirming exiting the program
    char choice;
    while (1) {
        printf("Continue? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            cleanScreen();
            return 1;
        } else if (choice == 'n' || choice == 'N') {
            printf("Ending...\n");
            return 0;
        } else {
            printf("Warning: Enter y or n\n");
        }
    }
}

int main() // Main body
{
    int password, i=0;
    char input;   
	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@ @@@@@@@@@@@@@@@@@ @@@@@@@@@@@\n");
    printf("@@@@@    @@@@@@@@@@@@@@@@ @@@@@@@@@@@\n");
    printf("@@@@@@  @@@@@@@@@@@@@@@@@ @@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@ @@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@                     @@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@                         @@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");

    while (i<3){ // Checking if it's still under 3 attpemts
        printf("Enter the 4-digit password:");
        scanf("%d", &password);
        if (password==2025){ 
            break;
                             
            } else {
            i++; // Minus one attempt
            printf("Wrong password, reamining attempts:%d\n", 3 - i);
        }
    }
