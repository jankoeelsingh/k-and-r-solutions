#include <stdio.h>

int main() {
    #define IN 1
    #define OUT 0

    int b, t, nl, c;

    b = t = nl = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            putchar('\\');
            putchar('t');
        } else if (c == '\b') {
            putchar('\\');
            putchar('b');
        } else if (c == '\\') {
            putchar('\\');
            putchar('\\');
        } else {
            putchar(c);
        }
        fflush(stdout);
        // if (c == '\b') printf("\\b");
    }

        // if (c == ' ') {
        //     if (b == OUT) {
        //         putchar(c);
        //         b = IN;
        //     }
        // } else {
        //     putchar(c);
        //     b = OUT;
        // }

        // if (c == ' ') ++b;
        // if (c == '\t') ++t;
        // if (c == '\n') ++nl;

    // printf("Blanks: %d\nTabs: %d\nNewlines: %d\n", b, t, nl);
}