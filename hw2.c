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
            while((ch = getchar()) != '\n' && ch != EOF);
            printf("Warning: Invalid input. Enter again:\n");
            continue;
        }
        
        if(n >= 1 && n <= 9) {
            cleanScreen();
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= n; j++) {
                    printf("%d*%d=%2d ", i, j, i*j);
                }
                printf("\n");
            }
            printf("\nEnter a key to back to main menu");
            while((ch = getchar()) != '\n' && ch != EOF);
            getch();
            cleanScreen();
            return;
        } else {
            printf("Warning: Enter again:\n");
        }
    }
}
