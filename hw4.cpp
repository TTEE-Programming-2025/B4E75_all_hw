#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

// �T�{�O�_�~��{��
int confirmContinue() { 
    char choice;
    while (1) {
        printf("Continue? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            system("cls");  // �M���e�� (Windows)
            return 1;
        } else if (choice == 'n' || choice == 'N') {
            printf("Exiting...\n");
            return 0;
        } else {
            printf("Please enter y or n\n");
        }
    }
}

int main() {
    printf("Program Started\n");
    
    // �ϥ� confirmContinue �禡
    if (confirmContinue()) {
        printf("User chose to continue\n");
    } else {
        printf("User chose to exit\n");
        return 0;
    }
    
    printf("Program Ended\n");
    return 0;
}
