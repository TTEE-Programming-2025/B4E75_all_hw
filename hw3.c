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
