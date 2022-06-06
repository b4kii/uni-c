#include <stdio.h>
#include <ctype.h>

#include "../inc/subjects.h"

void (*programs[5])() = {arrays, matrixes, stack, strings, files};

char *subjectMenuText[] = {
    "\nChoose subject:\n\n",
    " __________________\n",
    "|Arrays \t[1]|\n",
    "|__________________|\n",
    "|Matrixes \t[2]|\n",
    "|__________________|\n",
    "|Stack \t\t[3]|\n",
    "|__________________|\n",
    "|Strings \t[4]|\n",
    "|__________________|\n",
    "|Files \t\t[5]|\n",
    "|__________________|\n",
    "|Exit \t\t[0]|\n",
    "|__________________|\n\n",
    "Selected: "};

int subjectMenuCount = sizeof(subjectMenuText) / sizeof(subjectMenuText[0]);

void runProgram()
{
    int option = 1;

    while (option != 0)
    {
        displayMenuText(subjectMenuText, subjectMenuCount);
        int checkTest = scanf("%d", &option);
        fflush(stdin);

        if (checkTest != 1)
        {
            printf("\nERROR: Only numbers are valid!");
            fscanf(stdin, "%*[^\n]%*c");
            return;
        }

        (*programs[option - 1])();
    }
    printf("\nBye bye!\n");
}