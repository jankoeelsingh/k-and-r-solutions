#ifndef STACK_H
#define STACK_H

#define STACK_MAX 100

typedef struct {
    char data[STACK_MAX];
    int top;
} Stack;

void init_stack(Stack *s);
int is_empty(Stack *s);
int is_full(Stack *s);
void push(Stack *s, char c);
char pop(Stack *s);
char peek(Stack *s);

#endif