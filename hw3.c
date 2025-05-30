#include <stdio.h>  //#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>

#define SIZE 9
#define MAX_RESERVED 10 
#define PASSWORD 2025

char seats[SIZE][SIZE];
char tempSeats[SIZE][SIZE];

void iniSeats() {
    srand((unsigned)time(NULL));
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            seats[i][j] = '-';
        }
    }

    int count = 0;
    while (count < MAX_RESERVED) {
        int r = rand() % SIZE;
        int c = rand() % SIZE;
        if (seats[r][c] != '*') {
            seats[r][c] = '*';
            count++;
        }
    }
}

void showSeats() {
    printf("\\123456789\n");
    for (int i = SIZE - 1; i >= 0; i--) {
        printf("%d", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf("%c", seats[i][j]);
        }
        printf("\n");
    }
    printf("\nPress any key to return to main menu");
    getch();
    system("cls");
}

void showTempSeats() {
    printf("\\123456789\n");
    for (int i = SIZE - 1; i >= 0; i--) {
        printf("%d", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf("%c", tempSeats[i][j]);
        }
        printf("\n");
    }
}

void autoSeats() {
    int n;
    printf("How many seats do you need (1~4)?: ");
    scanf("%d", &n);
    if (n < 1 || n > 4) {
        printf("Error, please enter again");
        return;
    }

    memcpy(tempSeats, seats, sizeof(seats));
    int found = 0;

    if(n < 4) {
        for (int i = 0; i < SIZE && !found; i++) {
            for (int j = 0; j <= SIZE - n; j++) {
                int ok = 1;
                for (int k = 0; k < n; k++) {
                    if (tempSeats[i][j + k] != '-') ok = 0;
                }
                if (ok) {
                    for (int k = 0; k < n; k++) 
                        tempSeats[i][j + k] = '@';
                    found = 1;
                    break;    
                }
            }
        }
    } else {
        for (int i = 0; i < SIZE - 1 && !found; i++) {
            for (int j = 0; j <= SIZE - 2; j++) {
                if (tempSeats[i][j] == '-' && tempSeats[i][j + 1] == '-' &&
                    tempSeats[i + 1][j] == '-' && tempSeats[i + 1][j + 1] == '-') {
                    tempSeats[i][j] = tempSeats[i][j + 1] = '@';
                    tempSeats[i + 1][j] = tempSeats[i + 1][j + 1] = '@';
                    found = 1;
                    break;
                }
            }
        }
    }
}

int main() {
    iniSeats();
    
    int choice;
    while(1) {
        printf("1. Show Seats\n");
        printf("2. Auto Select Seats\n");
        printf("3. Show Temporary Seats\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                showSeats();
                break;
            case 2:
                autoSeats();
                break;
            case 3:
                showTempSeats();
                printf("\nPress any key to continue...");
                getch();
                system("cls");
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
  if (!found) {
        printf("Can't find your seats!\n");
        return;
    }

    showTempSeats();
    printf("Are you happy with the seats? (y/n)\n");
    char ch;
    scanf(" %c", &ch);
    if (ch == 'y' || ch == 'Y') {
        for (int i = 0; i < SIZE; i++) 
            for (int j = 0; j < SIZE; j++) 
                if (tempSeats[i][j] == '@') 
                    seats[i][j] = '*';
    } 
    printf("Back to main menu\n");
    system("cls");
}

// Manual seats
void manualSeats() {
    int n;
    printf("How many seats do you need? (1~4)");
    scanf("%d", &n);
    if (n < 1 || n > 4) {
        printf("Error, please enter again");
        return;
    }

    memcpy(tempSeats, seats, sizeof(seats));
    int c, r;
    for  (int i = 0;  i < n; i++) {
        printf("Row for the %d seats: ", i + 1);
        getch();
        scanf("%d", &r);
        printf("Column for the %d seats: ", i + 1);
        getch();
        scanf("%d", &c);
        if (r < 1 || r > 9 || c < 1 || c > 9 || tempSeats[r - 1][c - 1] != '-') {
            printf("The seat you choose is already reserved\n");
            i--;
        } else {
            tempSeats[r - 1][c - 1] = '@';
        }
    }

    showTempSeats();
    printf("\nPlease confirm\n");
    getch();

    for (int i = 0; i < SIZE; i++) 
        for (int j = 0; j < SIZE; j++) 
            if (tempSeats[i][j] == '@') 
                seats[i][j] = '*';
    system("cls");            
}

// Checking the  password to see if it's correct
int passwordCheck() {
    int input, attempt = 0;
    while (attempt < 3) {
        printf("Enter the password: ");
        scanf("%d", &input);
        if (input == PASSWORD) {
            printf("Welcome!\n");
            return(1);
        } else {
            printf("Wrong  password\n");
            attempt++;
        }
    }
    printf("Error, shutting down");
    return 0;
}

// Comfirming exiting the program
int confirmContinue() { 
    char choice;
    while (1) {
        printf("Enter again (y/n)? ");
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            system("cls");
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
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@          @@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@ @@@@@@@@@@ @@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@ @@@@@@@@@@@@  @@@@@@@@@@@@@\n");
    printf("@@@@@@@@ @@@@@@@@@@@@@ @@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@ @@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@ @@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@ @@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@ @@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@ @@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@ @@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@ @@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@ @@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@ @@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    if (!passwordCheck()) return 0;

    iniSeats();

    char input;
    do {
        system("cls"); // Cleaning screen
        printf("------------------------------\n");
        printf("| a. : Available seats       |\n");
        printf("| b. : Arrange for you       |\n");
        printf("| c. : Choose by yourself    |\n");
        printf("| d. : Exit                  |\n");
        printf("------------------------------\n");
        scanf("%c", &input);

        system("cls");
        switch(input) { // Deciding with funtion we are using
            case 'a':
                showSeats();
                break;
            case 'b':
                autoSeats();
                break;
            case 'c':
                manualSeats();
                break;
            case 'd':
                if (!confirmContinue()){
                return 0; 
                }   
            default:
                printf("Wrong option enter again!\n");
                break;
        }
    } while(1);

    return  0;
}
