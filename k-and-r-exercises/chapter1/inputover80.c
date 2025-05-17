#include <stdio.h>

#define ARR_SIZE 10
#define MIN_SIZE_TO_PRINT 1

void populate_arr(char arr[][ARR_SIZE], int count[]);
void add_lines(char arr[][ARR_SIZE], int count[]);
void print_arr(char arr[][ARR_SIZE], int count[]);
void remove_trail(char arr[][ARR_SIZE], int count[]);

int main() {
    char lines[ARR_SIZE][ARR_SIZE];
    int count[ARR_SIZE];

    populate_arr(lines, count);
    add_lines(lines, count);
    print_arr(lines, count);
    remove_trail(lines, count);

    return 0;
}

void populate_arr(char arr[][ARR_SIZE], int count[]) {
    for (int i = 0; i < ARR_SIZE; ++i) {
        count[i] = 0;
    }
    for (int row = 0; row < ARR_SIZE; ++row) {
        for (int col = 0; col < ARR_SIZE; ++col) {
            arr[row][col] = ' ';
        }
    }
}

void add_lines(char arr[][ARR_SIZE], int count[]) {
    int c;
    for (int row = 0; row < ARR_SIZE; ++row) {
        for (int col = 0; col < ARR_SIZE && (c = getchar()) != EOF && c != '\n'; ++col) {
            arr[row][col] = c;
            count[row]++;
        }
    }
}

void print_arr(char arr[][ARR_SIZE], int count[]) {
    for (int row = 0; row < ARR_SIZE; ++row) {
        if (count[row] >= MIN_SIZE_TO_PRINT) {
            for (int col = 0; col < ARR_SIZE; ++col) {
                printf("%c", arr[row][col]);
            }
            printf("\n");
        }
    }
}

/* increment col until end or arr
   then replace blanks by null until char is hit */ 
void remove_trail(char arr[][ARR_SIZE], int count[]) {
    for (int row = 0; row < ARR_SIZE; ++row) {
        int col = 0;

        while (arr[row][col] != '\0' && col < ARR_SIZE) {
            ++col;
        }

        --col;

        while (col >= 0 && (arr[row][col] == ' ' || arr[row][col] == '\t' || arr[row][col] == '\n')) {
            arr[row][col] = '\0';
            --col;
        }
    }
}