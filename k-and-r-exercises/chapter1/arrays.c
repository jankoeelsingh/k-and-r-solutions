#include <stdio.h>

int main() {
    int c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;
    for (i = 0; i < 10; ++i) {
        ndigit[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9')
            ++ndigit[c - '0'];
        else if (c == ' ' || c == '\t' || c == '\n')
            ++nwhite;
        else
            ++nother;
    }

    printf("\nFrequencies of numbers:\n");
    for (i = 0; i < 10; ++i) {
        printf("%d: ", i);
        for (int j = 0; j < ndigit[i]; ++j) {
            printf("-");
        }
        printf("\n");
    }

    printf("Freq of white spaces: ");
    for (i = 0; i < nwhite; ++i) {
        printf("-");
    }

    printf("\nFreq of other chars: ");
    for (i = 0; i < nother; ++i) {
        printf("-");
    }
    printf("\n");

    // printf("digits =");
    // for (i = 0; i < 10; ++i)
    //     printf(" %d", ndigit[i]);
    // printf(", white space = %d, other = %d\n", nwhite, nother);

    return 0;
}