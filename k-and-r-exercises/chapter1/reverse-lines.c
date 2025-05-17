#include <stdio.h>

#define ARR_SIZE 100

void reverse(char s[], int size);

int main() {
    char arr[ARR_SIZE];
    int c, i = 0;

    while (i < ARR_SIZE - 1 && (c = getchar()) != EOF) {
        if (c == '\n') {
            reverse(arr, i);
            i = 0;
        }
        else
            arr[i++] = c;
    }

    return 0;
}

void reverse(char s[], int size) {
    char temp[ARR_SIZE];

    for (int i = 0; i < size; ++i) {
        temp[i] = s[size - i - 1];
    }

    for (int i = 0; i < size; ++i) {
        s[i] = temp[i];
    }

    for (int i = 0; i < size; ++i) {
        printf("%c", s[i]);
    }
    printf("\n");
}