#include <iostream>
#include "../lib/conio.h"
#include <cstdlib>
#include <string.h>

void bash() {
    char buffer[100];

    printf("bash mode: ");
    
    for(int i = 0; i < sizeof(buffer); i++) {
        buffer[i] = getche();

        if(buffer[i] == 127) {
            buffer[i] = 0;
            buffer[i - 1] = 0;
            i = i - 2;

            printf("\033[1D\033[0J");
        }


        if(buffer[i] == 10) {
            buffer[i] = 0;

            if(strcmp(buffer, "exit") == 0) {
                // printf("NO.. I WILL NOT LET YOU EXIT THAT EASY!"); fine... you win
                printf("\033[K");
                return;
            }

            system(buffer);
            bash();
        }
    }
}

int main() {
    char buffer[100];

    printf("\033[H\033[2J");

    for(int i = 0; i < sizeof(buffer); i++) {
        buffer[i] = getche();

        if(buffer[i] == 127) {
            buffer[i] = 0;
            buffer[i - 1] = 0;
            i = i - 2;

            printf("\033[1D\033[0J");
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

    return 0;
}
