#include <iostream>
#include "../lib/conio.h"
#include <cstdlib>
#include <string.h>

// to clear all the screen     printf("\033[2J\033[H");
// clear  screen     printf('\033[2J');

char alloveragain[47] = "press s to start over again, press x to quit.\n";

int alloveragains() {
    char option;

    option = getch();

    if(option == 's')
        return 0;
    else if(option == 'x')
        EXIT_FAILURE;
    else {
        printf("type better noob\n");
        alloveragains();
    }

    return 0;
}

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

    printf("\033[H\033[2J%s", alloveragain);

    for(int i = 0; i < sizeof(buffer); i++) {
        buffer[i] = getch();

        if(buffer[i] == 127) {
            buffer[i] = 0;
            buffer[i - 1] = 0;
            i = i - 2;
        }

        if(buffer[i] == 10) {
            buffer[i] = 0;

            if(strcmp(buffer, "bash") == 0) {
                bash();
            }

            i = sizeof(buffer);
        }
    }

    printf("you typed: %s\n", buffer);

    if(alloveragains() == 0) {
        main();
    } 

    return 0;
}
