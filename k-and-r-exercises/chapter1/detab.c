#include <stdio.h>

#define TABWIDTH 4

int main() {
    int c;
    int currentCol = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            int spaces = TABWIDTH - (currentCol % TABWIDTH);
            for (int i = 0; i < spaces; ++i) {
                putchar(' ');
            }
            currentCol += spaces;
        } else {
            putchar(c);
            ++currentCol;
            if (c == '\n') {
                currentCol = 0;
            }
        }
    }

    return 0;
}


// #include <stdio.h>

// #define TAB_WIDTH 4
// #define ARR_SIZE 1000

// void populate_array(int arr[]);

// int main() {
//     int c, currentCol, nextStop, toStop;
//     int arr[ARR_SIZE];

//     populate_array(arr);
//     nextStop = 0;

//     currentCol = 1;
//     while ((c = getchar()) != EOF) {
//         if (c == '\t') {
//             toStop = arr[nextStop] - currentCol;
//             for (int i = 0; i < toStop; ++i) {
//                 putchar(' ');
//             }
//             ++nextStop;
//         } else {
//             putchar(c);
//         }
//         ++currentCol;
//     }

//     return 0;
// }

// void populate_array(int arr[]) {
//     for (int i = 4; (i + 4) <= ARR_SIZE; i += 4) {
//         arr[i] = i;
//     }
// }