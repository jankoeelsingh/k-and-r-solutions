#include <stdio.h>
#include <string.h>

#define NORMAL                  0
#define IN_QUOTED_STRING        1
#define IN_CHARACTER_CONSTANT   2
#define IN_COMMENT              3

#define ARR_SIZE                1024

void remove_comments(char text[]);

int main() {
    char programText[] = "//This \'\'is a comment\\nprin/*fjfdbs*/tf('Hello world\t')\n";

    remove_comments(programText);

    return 0;
}

void remove_comments(char text[]) {
    int state = NORMAL;
    char tempText[ARR_SIZE];
    int i, j;

    memset(tempText, 0, ARR_SIZE);

    i = j = 0;
    while (text[i] != '\0') {
        switch (state) {
            case NORMAL:
                if (text[i] == '"') {
                    state = IN_QUOTED_STRING;
                    tempText[j++] = text[i];
                }
                else if (text[i] == '\'') {
                    state = IN_CHARACTER_CONSTANT;
                    tempText[j++] = text[i];
                }
                else if (text[i] == '/') {
                    state = IN_COMMENT;
                }
                else {
                    tempText[j++] = text[i];
                }
                break;

            case IN_QUOTED_STRING:
                tempText[j++] = text[i];
                if (text[i] == '"') {
                    state = NORMAL;
                }
                break;

            case IN_CHARACTER_CONSTANT:
                tempText[j++] = text[i];
                if (text[i] == '\'') {
                    state = NORMAL;
                }
                break;
            
            case IN_COMMENT:
                if (text[i] == '\\' && text[i + 1] == 'n') {
                    state = NORMAL;
                    i++;
                }
                else if (text[i] == '*' && text[i + 1] == '/') {
                    state = NORMAL;
                    i++;
                }
                break;
        }

        i++;
    }

    tempText[j] = '\0';

    printf("%s\n", tempText);
}