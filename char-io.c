#include <stdio.h>

int main() {
    // int c;

    // while ((c = getchar()) != EOF) {
    //     printf("getchar != EOF: %d\n", c != EOF);
    // }

    // printf("\nValue of EOF: %d\n", EOF);

    // double nc;

    // for (nc = 0; getchar() != EOF; ++nc) {
    //     ;
    // }

    // printf("%.0f\n", nc);

    int c, nl;

    nl = 0;
    while((c = getchar()) != EOF) {
        if (c == '\n') {
            ++nl;
        }
    }
    printf("%d\n", nl);

    return 0;
}