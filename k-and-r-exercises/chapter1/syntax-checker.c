#include <stdio.h>
#include <string.h>

// State machine
#define NORMAL              0
#define IN_PARENTHESES      1
#define IN_BRACKETS         2
#define IN_BRACES           3
#define IN_SINGLE_QUOTES    4
#define IN_DOUBLE_QUOTES    5
// Escape seq and comments
#define ARR_SIZE            1024

void syntax_checker(char text[]);

int main() {
    char text[] = "printf(\"Hello World\");";

    syntax_checker(text);

    return 0;
}

void syntax_checker(char text[]) {
    int state = NORMAL;
    char tempText[ARR_SIZE];
    int i, j;

    memset(tempText, 0, ARR_SIZE);

    i = j = 0;

    while (text[i] != '\0') {
        switch (state) {
            case NORMAL:
            // Don't track state for braces and such, track count or use a stack
            // Because they can be nested
                if (text[i] == '(') {
                    state = IN_PARENTHESES;
                    tempText[j++] = text[i];
                }
                else if (text[i] == '[') {
                    state = IN_BRACKETS;
                    tempText[j++] = text[i];
                }
                else if (text[i] == '{') {
                    state = IN_BRACES;
                    tempText[j++] = text[i];
                }
                else if (text[i] == '\'') {
                    state = IN_SINGLE_QUOTES;
                    tempText[j++] = text[i];
                }
                else if (text[i] == '"') {
                    state = IN_DOUBLE_QUOTES;
                    tempText[j++] = text[i];
                }
                else {
                    tempText[j++] = text[i];
                }
                break;

            case IN_PARENTHESES:
                tempText[j++] = text[i];
                if (text[i] == ')') {
                    state = NORMAL;
                }
                break;
            
            case IN_BRACKETS:
                tempText[j++] = text[i];
                if (text[i] == ']') {
                    state = NORMAL;
                }
                break;

            case IN_BRACES:
                tempText[j++] = text[i];
                if (text[i] == '}') {
                    state = NORMAL;
                }
                break;
            
            case IN_SINGLE_QUOTES:
                tempText[j++] = text[i];
                if (text[i] == '\'') {
                    state = NORMAL;
                }
                break;

            case IN_DOUBLE_QUOTES:
                tempText[j++] = text[i];
                if (text[i] == '"') {
                    state = NORMAL;
                }
                break;
        }

        i++;
    }

    tempText[j] = '\0';

    if (state == NORMAL) {
        printf("%s\n", tempText);
    }
    else {
        printf("Syntax error!");
    }
}