#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // For getch()
#include <time.h>
#include <string.h>

#define SIZE 9
#define MAX_RESERVED 10 
#define PASSWORD 2025

char seats[SIZE][SIZE];
char tempSeats[SIZE][SIZE];
// Initialise seats and tag 10 random seats as '*'
void iniSeats() {
    for (int i = 0; i < SIZE; i++)
       for (int j = 0; j < SIZE; j++)
          seats[i][j]='-';

    int count = 0;
    while (count < MAX_RESERVED) {
        int r = rand() %SIZE;
        int c = rand() %SIZE;
        if(seats[r][c] != '*') {
           seats[r][c] = '*';
           count++;
        }
    }
}

// Showing the seats 
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

