#include <stdio.h>

#define IN  1
#define OUT 0
#define MAXWORDS 1000

int main() {
    int c, state = OUT;
    int word_lengths[MAXWORDS];
    int histogram[30][30];
    int max = 0;
    int count = 0;    
    int index = 0;      

    for (int i = 0; i < MAXWORDS; i++) {
        word_lengths[i] = 0;
    }

    for (int i = 0; i < 30; ++i) {
        for (int j = 0; j < 30; ++j) {
            histogram[i][j] = 0;
        }
    }

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == IN) {
                state = OUT;
                word_lengths[index++] = count;
                if (count > max) {
                    max = count;
                }
                count = 0;
            }
        } else {
            if (state == OUT)
                state = IN;
            ++count;
        }
    }

    if (state == IN) {
        word_lengths[index++] = count;
    }

    for (int i = 0; i < index; ++i) {
        printf("Word %d\t", i);
    }
    printf("\n");

    for (int i = 0; i < index; ++i) {
        for (int j = 0; j < word_lengths[i]; ++j) {
            histogram[max - 1 - j][i]++;
        }
    }

    for (int i = 0; i < max; ++i) {
        for (int j = 0; j < index; ++j) {
            if (histogram[i][j] == 1)
                printf("|\t");
            else
                printf(" \t");
        }
        printf("\n");
    }

    // for (int i = 0; i < index; i++) {
    //     printf("Word %2d (len %2d): ", i + 1, word_lengths[i]);
    //     for (int j = 0; j < word_lengths[i]; j++) {
    //         printf("-");
    //     }
    //     printf("\n");
    // }
    
//     int i, c, count, state;

//     count = 0;
//     state = OUT;
//     while ((c = getchar()) != EOF) {
//         if (c == ' ' || c == '\t' || c == '\n') {
//             if (state == IN) {
//                 printf(": ");
//                 for (i = 0; i < count; ++i) {
//                     printf("-");
//                 }
//                 putchar('\n');
//                 state = OUT;
//                 count = 0;
//             }
//         } else {
//             putchar(c);
//             state = IN;
//             ++count;
//         }
//     }
}