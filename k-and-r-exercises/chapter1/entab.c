#include <stdio.h>

#define TABWIDTH   7
#define ARR_SIZE   1000
#define TAB_ADDED  1
#define NO_TAB     0

void replace_chars(char arr[]);
void reset_arr(char arr[], int size);

int main() {
    int c, blanks, tabbed;
    int currentCol = blanks = 0;
    tabbed = NO_TAB;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            blanks++;
        } 
        else {
            while (blanks > 0) {
                int spacesToNextTabStop = TABWIDTH - (currentCol % TABWIDTH);
                if (blanks >= spacesToNextTabStop) {
                    putchar('\t');
                    currentCol += spacesToNextTabStop;
                    blanks -= spacesToNextTabStop;
                } else {
                    for (int i = 0; i < blanks; ++i) {
                        putchar(' ');
                        currentCol++;
                    }
                    blanks = 0;
                }
            }

            if (c == '\t') {
                putchar(c);
                currentCol += TABWIDTH - (currentCol % TABWIDTH);
            }
            else if (c == '\n') {
                putchar(c);
                printf("%d\n", currentCol);
                currentCol = 0;
            }
            else {
                putchar(c);
                currentCol++;
            }
        }
    }

    return 0;
}

// int main() {
//     int c, blanks, tabbed, toMove;
//     int currentCol = blanks = 0;
//     tabbed = NO_TAB;

//     while ((c = getchar()) != EOF) {
//         if (c == ' ') {
//             blanks++;
//             toMove = TABWIDTH - (currentCol % TABWIDTH);
//             if (blanks >= TABWIDTH) {
//                 putchar('\t');
//                 blanks -= TABWIDTH;
//                 tabbed = TAB_ADDED;
//                 currentCol += TABWIDTH;
//             }
//         } 
//         else {
//             if (blanks > 0) {
//                 for (int i = 0; i < blanks; ++i) {
//                     putchar(' ');
//                 }
//                 currentCol += blanks;
//                 blanks = 0;
//                 tabbed = NO_TAB;
//             }

//             if (c == '\t') {
//                 putchar('\t');
//                 currentCol += TABWIDTH;
//             }
//             else if (c == '\n') {
//                 putchar('\n');
//                 printf("// Col: %d\n", currentCol);
//                 currentCol = 0;
//             }
//             else {
//                 putchar(c);
//                 currentCol++;
//             }
//         }
//     }

//     return 0;
// }

// int main() {
//     int c, blanks, tabbed;
//     int currentCol = blanks = 0;
//     tabbed = NO_TAB;

//     while ((c = getchar()) != EOF) {
//         if (c == ' ') {
//             blanks++;
//             if (blanks >= TABWIDTH) {
//                 tabbed = TAB_ADDED;
//                 putchar('\t');
//                 blanks -= TABWIDTH;
//                 currentCol += TABWIDTH;
//             }
//             // if (tabbed == TAB_ADDED && blanks > 0) {
//             //     blanks--;
//             //     currentCol++;
//             //     putchar(' ');
//             // } 
//             else {
//                 tabbed = NO_TAB;
//             }
//         } 
//         else if (c == '\t') {
//             putchar(c);
//             currentCol += TABWIDTH;
//         }
//         else if (c == '\n') {
//             printf("%d\n", currentCol);
//         }
//         else {
//             if (blanks > 0) {
//                 for (int i = 0; i < blanks; ++i) {
//                     putchar(' ');
//                 }
//                 currentCol += blanks;
//                 blanks = 0;
//             }
//             putchar(c);
//             currentCol++;
//         }
//     }

//     return 0;
// }











void replace_chars(char arr[]) {
    for (int i = 0; arr[i] != '\0'; ++i) {
        if (arr[i] == ' ') {
            arr[i] = '-';
        } else if (arr[i] == '\t') {
            for (int j = 0; j < TABWIDTH; ++j) {
                // need to increment i as well
                ;
            }
        }
        printf("%c", arr[i]);
    }
}

void reset_arr(char arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = '\0';
    }
}