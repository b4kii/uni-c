#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/files.h"
#include "../inc/arrays.h"

char *filesMenuText[] = {
    "\nChoose exercise:\n\n",
    "Open a file [1]\n",
    "Go back [0]\n\n",
    "Select: "};

int filesMenuCount = sizeof(filesMenuText) / sizeof(filesMenuText[0]);

FILE *openFile()
{
    char fileName[255], mode[3];

    printf("\nInsert file name: ");
    fgets(fileName, 255, stdin);
    strtok(fileName, "\n");

    printf("Insert opening mode: ");
    fgets(mode, 3, stdin);
    strtok(mode, "\n");

    FILE *newFile = fopen(fileName, mode);
    if (newFile == NULL)
    {
        fprintf(stderr, "\nCannot open the file!\n");
        exit(1);
    }

    printf("\nFile have been opened with %s mode!\n", mode);
    return newFile;
}

void saveRandomNumbers(FILE *newFile)
{
    int min, max, randomNumberCount;
    printf("\nHow many numbers to generate: ");
    scanf("%d", &randomNumberCount);
    printf("Insert range of numbers to generate from [(min) (max)]: ");
    scanf("%d %d", &min, &max);

    for (int i = 0; i < randomNumberCount; i++)
    {
        int tempNumber = rand() % (max - min + 1) + min;
        if (i == randomNumberCount - 1)
        {
            fprintf(newFile, "%d", tempNumber);
        }
        else
        {
            fprintf(newFile, "%d\n", tempNumber);
        }
    }

    fclose(newFile);
}

void renderFilesMenu()
{
    int option, run = 1;
    while (run)
    {
        displayMenuText(filesMenuText, filesMenuCount);
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
            openFile();
            break;
        case 2:
            break;
        case 0:
            run = 0;
            break;
        }
    }
}

void files()
{
    renderFilesMenu();
}