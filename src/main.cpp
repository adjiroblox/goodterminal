#include <iostream>
#include "../lib/conio.h"
#include <cstdlib>
#include <string.h>

// to clear all the screen     printf("\033[2J\033[H");
// clear  screen     printf('\033[2J');

void bash() {
    char buffer[100];

    printf("bash mode: ");
    
    for(int i = 0; i < sizeof(buffer); i++) {
        buffer[i] = getch();

        if(strcmp(buffer, "exit\n") == 0) {
            fflush(stdout);
            printf("NO.. I WILL NOT LET YOU EXIT THAT EASY!\n");
            sleep(3);
        }
        
        if(buffer[i] == 10) {
            buffer[i] = 0;

            printf("\n");

            system(buffer);
            bash();
        }
    }
}

int main() {
    char buffer[100];

    printf("\033[H\033[2J");

    for(int i = 0; i < sizeof(buffer); i++) {
        buffer[i] = getch();

        if(buffer[i] == 10) {
            buffer[i] = 0;

            if(strcmp(buffer, "bash") == 0) {
                bash();
            }

            return 0;
        }
    }

    printf("you typed: %s", buffer);

    return 0;
}
