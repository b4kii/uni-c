#ifndef STACK_H
#define STACK_H

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

void showStack(Node *);
void push(Node **);
int pop(Node **);
void stack();
void renderStackMenu();

#endif // STACK_H