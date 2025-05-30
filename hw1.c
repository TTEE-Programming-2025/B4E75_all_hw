#include <stdio.h>
#include <stdlib.h>



int main(void)
{
    int password=0;  
    char input;

    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  @@@@@\n");
    printf("@@@@@@@@  @@@@@@@@@@@@@@        @@@@@\n");
    printf("@@@@@@          @@@@@          @@@@@@\n");
    printf("@@@@@     @@@@@@@@@@@           @@@@@\n");
    printf("@@@@@@ @@@ @@@@@@@@@@@@@@@  @@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@          @@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@    @@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    getchar(); // waiting for user to type anything

    system("cls"); // erase picture   
    
    printf("Enter the 4-digit password:");
    fflush(stdin); // clear input buffer
    scanf("%d", &password); // read password
    if (password == 2025){  
        system("cls");
        printf("-------------------------------\n");
        printf("| 'A'...'Z'  : Uppercase      |\n");
        printf("| 'a'...'z'  : Lowercase      |\n");
        printf("| '0'...'9'  : Digit          |\n");
        printf("| Otherwise  : Yourname       |\n");
        printf("-------------------------------\n");
        printf("Type anything:");

        while (getchar() != '\n');  // Clears any leftover characters, especially '\n'
        scanf("%c", &input); // read input

        if (input >= 'A' && input <= 'Z' ) { // check if it's uppercase letter
            printf("Uppercase\n");
            getchar(); // consumes the leftover newline from previous input
            getchar(); // waits for the user to press any key and hit Enter
            exit(0); //terminates program
        } 
            else if (input >= 'a'&& input <= 'z' ){ // check if it's lowercase letter
                printf("Lowercase\n");
                getchar(); // consumes the leftover newline from previous input
                getchar(); // waits for the user to press any key and hit Enter
                exit(0); // terminates program
            } 
                else if (input >= '0' && input <= '9' ){ // checkif it's number
                    printf("Digit\n");
                    getchar(); // consumes the leftover newline from previous input
                    getchar(); // waits for the user to press any key and hit Enter
                    exit(0); // terminates program
                } 
                    else{ // the leftovers
                        printf("E4B75-kuo-po-lin\n");
                        getchar(); // consumes the leftover newline from previous input
                        getchar(); // waits for the user to press any key and hit Enter
                        exit(0); // terminates program
                    }
    }
    else {
        printf("Wrong password!\a\n"); // \a triggers a beep sound
        getchar(); // consumes the leftover newline from previous input
        getchar(); // waits for the user to press any key and hit Enter
        exit(0);
    }
}    
