#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>

#define SIZE 9
#define MAX_RESERVED 10 
#define PASSWORD 2025

char seats[SIZE][SIZE];
char tempSeats[SIZE][SIZE];

// Function prototypes
void iniSeats();
void showSeats();
void showTempSeats();
void autoSeats();
void manualSeats();
int passwordCheck();
int confirmContinue();

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
        printf("Error, please enter again\n");
        getch();
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

    if (!found) {
        printf("Can't find your seats!\n");
        getch();
        return;
    }

    showTempSeats();
    printf("Are you happy with the seats? (y/n): ");
    char ch;
    scanf(" %c", &ch);  // Note the space before %c to skip whitespace
    if (ch == 'y' || ch == 'Y') {
        for (int i = 0; i < SIZE; i++) 
            for (int j = 0; j < SIZE; j++) 
                if (tempSeats[i][j] == '@') 
                    seats[i][j] = '*';
    }
    printf("Back to main menu\n");
    getch();
    system("cls");
}

void manualSeats() {
    int n;
    printf("How many seats do you need? (1~4): ");
    scanf("%d", &n);
    if (n < 1 || n > 4) {
        printf("Error, please enter again\n");
        getch();
        return;
    }

    memcpy(tempSeats, seats, sizeof(seats));
    int c, r;
    for (int i = 0; i < n; i++) {
        printf("Row for seat %d: ", i + 1);
        scanf("%d", &r);
        printf("Column for seat %d: ", i + 1);
        scanf("%d", &c);
        
        if (r < 1 || r > SIZE || c < 1 || c > SIZE || tempSeats[r - 1][c - 1] != '-') {
            printf("Invalid seat or already reserved\n");
            i--;
            continue;
        }
        tempSeats[r - 1][c - 1] = '@';
    }

    showTempSeats();
    printf("\nPlease confirm (y/n): ");
    char ch;
    scanf(" %c", &ch);
    
    if (ch == 'y' || ch == 'Y') {
        for (int i = 0; i < SIZE; i++) 
            for (int j = 0; j < SIZE; j++) 
                if (tempSeats[i][j] == '@') 
                    seats[i][j] = '*';
    }
    system("cls");            
}

int passwordCheck() {
    int input, attempt = 0;
    while (attempt < 3) {
        printf("Enter the password: ");
        scanf("%d", &input);
        if (input == PASSWORD) {
            printf("Welcome!\n");
            getch();
            return 1;
        } else {
            printf("Wrong password\n");
            attempt++;
        }
    }
    printf("Too many attempts. Shutting down...\n");
    getch();
    return 0;
}

int confirmContinue() { 
    char choice;
    while (1) {
        printf("Are you sure you want to exit? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            return 0;
        } else if (choice == 'n' || choice == 'N') {
            return 1;
        } else {
            printf("Please enter y or n\n");
        }
    }
}

void displayWelcome() {
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
}

int main() {
    displayWelcome();
    if (!passwordCheck()) return 0;

    iniSeats();

    char input;
    do {
        system("cls");
        printf("------------------------------\n");
        printf("| a. Available seats         |\n");
        printf("| b. Arrange for you         |\n");
        printf("| c. Choose by yourself      |\n");
        printf("| d. Exit                    |\n");
        printf("------------------------------\n");
        printf("Enter your choice: ");
        scanf(" %c", &input);  // Note the space before %c to skip whitespace

        switch(input) {
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
                if (!confirmContinue()) {
                    printf("Goodbye!\n");
                    return 0;
                }
                break;
            default:
                printf("Invalid option. Please try again.\n");
                getch();
                break;
        }
    } while(1);

    return 0;
}

// This project was significantly more challenging than the previous one. While arrays themselves aren't that complicated,
// implementing them correctly turned out to be much harder than expected, with lots of subtle details to handle.

// The toughest part was implementing function b - ensuring that when users book 4 seats,
// they must be adjacent. This logic took me a full two days to implement,
// with multiple rewrites and moments where I almost gave up...

// During debugging, I realized my boundary condition checks weren't rigorous enough -
// I kept missing edge cases, which caused numerous bugs in my code.

// But through this struggle, I've noticeably improved my array manipulation and logical reasoning skills,
// and learned to approach problems more systematically. These lessons are incredibly valuable.

// Although the process was painful, the sense of accomplishment afterwards was immense.
// I'm certain these gains will form an important foundation for tackling more complex projects in the future.

// Next time I work on a similar project, I'll definitely draw a flowchart before coding -
// that should help me avoid many detours!


