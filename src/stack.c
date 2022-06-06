#include <stdio.h>
#include <stdlib.h>

#include "../inc/stack.h"
#include "../inc/arrays.h"

char *stackMenuText[] = {
    "\nChoose exercise:\n",
    "\nPush on stack [1]\n",
    "Pop from stack [2]\n",
    "Show stack [3]\n",
    "Go back [0]\n\n",
    "Select: "};

int stackMenCount = sizeof(stackMenuText) / sizeof(stackMenuText[0]);

void push(Node **stack)
{
    int value;
    printf("\nValue to push: ");
    scanf("%d", &value);

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    if (*stack == NULL)
    {
        newNode->next = NULL;
    }
    else
    {
        newNode->next = *stack;
    }
    *stack = newNode;
}

int pop(Node **stack)
{
    if (*stack == NULL)
    {
        printf("\nERROR: Empty stack!");
    }
    else
    {
        Node *temp = *stack;
        int tempData = (*stack)->value;
        *stack = (*stack)->next;
        free(temp);
        return tempData;
    }
    return -1;
}

void showStack(Node *stack)
{
    if (stack == NULL)
    {
        printf("\nStack is empty!\n");
        return;
    }

    Node *temp = stack;
    while (temp != NULL)
    {
        printf("%d\n", temp->value);
        temp = temp->next;
    }
}

void renderStackMenu(Node *stack)
{
    int option, run = 1;
    while (run)
    {
        displayMenuText(stackMenuText, stackMenCount);
        int check = scanf("%d", &option);
        fflush(stdin);

        if (check != 1)
        {
            printf("\nERROR: Only numbers are valid!");
            fscanf(stdin, "%*[^\n]%*c");
            return;
        }

        switch (option)
        {
        case 1:
            push(&stack);
            break;
        case 2:
            pop(&stack);
            break;
        case 3:
            showStack(stack);
            break;
        case 0:
            run = 0;
            break;
        }
    }
}

void stack()
{
    Node *stack = NULL;

    renderStackMenu(stack);
}