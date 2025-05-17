#include <stdio.h>

#define MAXLINE 10
/* maximum input line length */
int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line*/
int main() {
    int len; /* current line length */
    int max; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE]; /* longest line saved here */

    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) {
        printf("Length: %d\n", max);
        printf("%s", longest);
    }
    return 0;
}

/* getline: read a line into s, return length*/
int get_line(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        if (i < lim - 1) {
            s[i++] = c;
        }
    }

    s[i < lim ? i : lim - 1] = '\0';

    // keep reading if line is longer than buffer
    while (c != '\n' && c != EOF) {
        c = getchar();
        ++i;
    }

    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
    for (int i = 0; (to[i] = from[i]) != '\0'; ++i) ;
}