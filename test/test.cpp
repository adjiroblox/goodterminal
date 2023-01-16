#include <iostream>
#include <conio.h>
#include <string.h>

// 
//    \033[H: It moves the cursor at the top left corner of the screen or console.
//   \033[2J: It clears the screen from the cursor to the end of the screen.
//

void fard() {
    //printf("\033[h");
    printf("\033[2J");
}

void backspacebruh() {
    char b[100];

    for(int i = 0; i < sizeof(b); i++) {
        b[i] = getch();

        if(b[i] == 10) {
            i = sizeof(b);
        }
    }

    printf("you typed: ");

    for(int i = 0; i < strlen(b); i++) {
        printf("%d", b[i]);
    }
}

void idk() {
    printf("idk something somsething ");
    getch();
    //printf("\033[K");
    printf("\033[2K\033[100D");
    printf("idk something somsething ");
    getch();
}

int main() {
    idk();

    return 0;
}
