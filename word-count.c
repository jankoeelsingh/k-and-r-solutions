#include <stdio.h>

#define IN  1
#define OUT 0

int main() {
    int c, state;

    state = OUT;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == IN) {
                putchar('\n');
                state = OUT;
            }
        } else {
            putchar(c);
            state = IN;
        }
    }

    // int c, nl, nw, nc, state;

    // state = OUT;
    // nl = nw = nc = 0;

    // while ((c = getchar()) != EOF) {
    //     ++nc;
    //     if (c == '\n')
    //         ++nl;
    //     if (c == ' ' || c == '\n' || c == '\t')
    //         state = OUT;
    //     else if (state == OUT) {
    //         state = IN;
    //         ++nw;
    //     }
    // }
    // printf("%d %d %d\n", nl, nw, nc);

    return 0;
}