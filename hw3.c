#include <iostream>
#include <cstdlib>
#include <conio.h> // For getch()
#include <ctime>
#include <cstring>

#define SIZE 9
#define MAX_RESERVED 10 
#define PASSWORD 2025

char seats[SIZE][SIZE];
char tempSeats[SIZE][SIZE];

// Initialize seats and tag 10 random seats as '*'
void iniSeats() {
    // Initialize random seed
    srand(static_cast<unsigned int>(time(nullptr)));
    
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

// Showing the seats 
void showSeats() {
    std::cout << "\\123456789\n";
    for (int i = SIZE - 1; i >= 0; i--) {
        std::cout << (i + 1);
        for (int j = 0; j < SIZE; j++) {
            std::cout << seats[i][j];
        }
        std::cout << "\n";
    }
    std::cout << "\nPress any key to return to main menu";
    getch();
    system("cls");
}

int main() {
    iniSeats();
    showSeats();
    return 0;
}

