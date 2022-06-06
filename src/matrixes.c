#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../inc/matrixes.h"
#include "../inc/arrays.h"

#define MATRIX_MENU_COUNT 6

int isMatrixCompleted = 0;

char *matrixMenuText[] = {
    "\nChoose exercise:\n",
    "\nComplete matrix [1]\n",
    "Show matrix [2]\n",
    "Switch rows [3]\n",
    "Go back [0]\n\n",
    "Select: "};

// Initialization with double pointer
int **initializeMatrix(int rows, int columns)
{
    int **matrix = (int **)malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int *)malloc(sizeof(int) * columns);
    }
    return matrix;
}

void completeMatrix(int **matrix, int rows, int columns)
{
    int min, max;
    srand((unsigned)time(NULL));
    printf("\nInsert range of numbers to populate array [(min) (max)]: ");
    scanf("%d %d", &min, &max);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            matrix[i][j] = rand() % (max - min + 1) + min;
        }
    }

    isMatrixCompleted = 1;
}

void showMatrix(int **matrix, int rows, int columns)
{
    if (isMatrixCompleted)
    {
        printf("\n");
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                printf("\t%5d", matrix[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    else
    {
        printf("\nComplete matrix first!\n");
    }
}

void freeMatrix(int **matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

void reverse(int **first, int **second)
{
    int *temp = *first;
    *first = *second;
    *second = temp;
}

void switchRows(int **matrix)
{
    if (isMatrixCompleted)
    {
        int first, second;
        printf("\nInsert row's indexes to swap [(first) (second)]: ");
        scanf("%d %d", &first, &second);
        reverse(&matrix[first], &matrix[second]);
    }
    else
    {
        printf("\nComplete matrix first!\n");
    }
}

void renderMatrixesMenu(int **matrix, int rows, int columns)
{
    int option, run = 1;
    while (run)
    {
        printf("\n----------------------------\n");

        displayMenuText(matrixMenuText, MATRIX_MENU_COUNT);
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
            completeMatrix(matrix, rows, columns);
            break;
        case 2:
            showMatrix(matrix, rows, columns);
            break;
        case 3:
            switchRows(matrix);
            break;
        case 4:
            break;
        case 0:
            run = 0;
            isMatrixCompleted = 1;
            break;
        }
    }
}

void matrixes()
{
    int rows, columns;

    printf("\nInsert rows and columns [(rows) (columns)]: ");
    int check = scanf("%d %d", &rows, &columns);
    fflush(stdin);

    if (check != 2)
    {
        printf("\nERROR: Only numbers are valid!");
        fscanf(stdin, "%*[^\n]%*c");
        return;
    }

    if (rows < 0 && columns < 0)
    {
        printf("\nERROR: Values cannot be negative!\n");
        return;
    }

    int **matrix = initializeMatrix(rows, columns);

    renderMatrixesMenu(matrix, rows, columns);

    freeMatrix(matrix, rows);
}

// Initialization with pointer to the table
// Columns number must be const value

/*
void nvm() {
    int rows;
    int (*array)[COLUMNS];
    array = ((*)[COLUMNS]) malloc(sizeof(int) * rows * columns);

    // Complete an array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns: j++) {
            array[i][j] = rand() % (min - max + 1) + min;
        }
    }
    free(array);
}
*/