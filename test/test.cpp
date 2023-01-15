#include <iostream>

// 
//    \033[H: It moves the cursor at the top left corner of the screen or console.
//   \033[2J: It clears the screen from the cursor to the end of the screen.
//

int main() {
    //printf("\033[h");
    printf("\033[2J");

    return 0;
}
