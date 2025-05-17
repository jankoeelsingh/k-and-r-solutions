#include <stdio.h>

#define MAX_LINE_LEN 10
#define TAB_WIDTH 8

int main() {
    int c, blanks, currentCol, spacesToNextTabStop;

    currentCol = blanks = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            putchar(c);
            currentCol = 0;
            blanks = 0;
        }
        else {
            if (c == ' ') {
                blanks++;
            }
            else if (c == '\t') {
                spacesToNextTabStop = TAB_WIDTH - (currentCol % TAB_WIDTH);
                blanks += spacesToNextTabStop;
            }
            else {
                if ((currentCol + blanks + 1) >= MAX_LINE_LEN) {
                    putchar('\n');
                    currentCol = 0;
                }
                for (int i = 0; i < blanks; ++i) {
                    putchar(' ');
                    currentCol++;
                }
                blanks = 0;

                putchar(c);
                currentCol++;
            }
        }
    }

    return 0;
}