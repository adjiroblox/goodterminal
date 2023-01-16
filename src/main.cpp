#include <iostream>
#include "../lib/conio.h"
#include <cstdlib>
#include <string.h>

// to clear all the screen     printf("\033[2J\033[H");
// ESC[K 	erase in line (same as ESC[0K) to clear one line
// clear  screen     printf('\033[2J');
//
// https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797
//
// Esc[K   Clear line from cursor right   EL0
// Esc[0K  Clear line from cursor right   EL0
// Esc[1K  Clear line from cursor left    EL1
// Esc[2K  Clear entire line              EL2

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
                fflush(stdout);
                printf("NO.. I WILL NOT LET YOU EXIT THAT EASY!");
                sleep(3);
                fflush(stdout);
                printf("\033[K");
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
