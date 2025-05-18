#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "../helpers/stack.h"

// Escape seq and comments
#define ARR_SIZE            1024

void syntax_checker(char text[]);

int main() {
    char text[] = "printf(\"Hello World\");";

    syntax_checker(text);

    return 0;
}

void syntax_checker(char text[]) {
    char tempText[ARR_SIZE];
    int i, j;
    bool inSingleQuotes = false;
    bool inDoubleQuotes = false;
    Stack parentheses, braces, brackets;
    init_stack(&parentheses);
    init_stack(&braces);
    init_stack(&brackets);

    memset(tempText, 0, ARR_SIZE);

    i = j = 0;

    while (text[i] != '\0') {
        if (text[i] == '(') {
            tempText[j++] = text[i];
            push(&parentheses, '(');
        }
        else if (text[i] == ')') {
            if (is_empty(&parentheses)) {
                printf("Syntax error: Unmatched parentheses!\n");
                return;
            }
            pop(&parentheses);
            tempText[j++] = text[i];
        }
        else if (text[i] == '[') {
            tempText[j++] = text[i];
            push(&brackets, '[');
        }
        else if (text[i] == ']') {
            if (is_empty(&brackets)) {
                printf("Syntax error: Unmatched brackets!\n");
                return;
            }
            pop(&brackets);
            tempText[j++] = text[i];
        }
        else if (text[i] == '{') {
            tempText[j++] = text[i];
            push(&braces, '{');
        }
        else if (text[i] == '}') {
            if (is_empty(&braces)) {
                printf("Syntax error: Unmatched braces!\n");
                return;
            }
            pop(&braces);
            tempText[j++] = text[i];
        }
        else if (text[i] == '\'') {
            inSingleQuotes = !inSingleQuotes;
            tempText[j++] = text[i];
        }
        else if (text[i] == '\"') {
            inDoubleQuotes = !inDoubleQuotes;
            tempText[j++] = text[i];
        }
        else {
            tempText[j++] = text[i];
        }

        i++;
    }

    tempText[j] = '\0';

    if (!is_empty(&parentheses)) {
        printf("Syntax error: Unmatched parentheses!\n");
    }
    else if (!is_empty(&brackets)) {
        printf("Syntax error: Unmatched brackets!\n");
    }
    else if (!is_empty(&braces)) {
        printf("Syntax error: Unmatched braces!\n");
    }
    else if (inSingleQuotes) {
        printf("Syntax error: Improper use of single quotes!\n");
    }
    else if (inDoubleQuotes) {
        printf("Syntax error: Improper use of double quotes!\n");
    }
    else {
        printf("%s\n", tempText);
    }
}