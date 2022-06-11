#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#include "../inc/arrays.h"

char *arrayMenuText[] = {
    "\nChoose exercise:\n",
    "\nComplete array [1]\n",
    "Show array [2]\n",
    "Sort array [3]\n",
    "Swap indexes [4]\n",
    "Binary search [5]\n",
    "Go back [0]\n\n",
    "Select: "};

int arrayMenuCount = sizeof(arrayMenuText) / sizeof(arrayMenuText[0]);

int isSorted = 0;
int isArrayCompleted = 0;

void displayMenuText(char **menu, int size)
{
    printf("\n_________________________\n");
    for (int i = 0; i < size; i++)
        printf("%s", menu[i]);
}

int *initializeArray(int size)
{
    int *array = (int *)malloc(sizeof(int) * size);
    if (array == NULL)
    {
        printf("\nERROR: Cannot allocate memory!\n");
        return 0;
    }

    return array;
}

void completeArray(int *array, int size)
{
    int min, max;
    srand((unsigned)time(NULL));
    printf("\nInsert range of numbers to populate array [(min) (max)]: ");
    scanf("%d %d", &min, &max);

    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % (max - min + 1) + min;
    }

    printf("\nArray populated with values from %d to %d\n", min, max);
    isArrayCompleted = 1;
}

void showArray(int *array, int size)
{
    if (isArrayCompleted)
    {
        printf("\n");
        for (int i = 0; i < size; i++)
        {
            printf("%d ", array[i]);
        }
        printf("\n");
    }
    else
    {
        printf("\nERROR: Complete array first!\n");
    }
}

void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

void swapIndexes(int *array)
{
    if (isArrayCompleted)
    {
        int first, second;
        printf("\nInsert indexes to swap [(first) (second)]: ");
        scanf("%d %d", &first, &second);

        swap(&array[first], &array[second]);
    }
    else
    {
        printf("\nERROR: Complete array first!\n");
    }
}

void bubbleSort(int *array, int size)
{
    if (isArrayCompleted)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (array[j] > array[j + 1])
                {
                    swap(&array[j], &array[j + 1]);
                }
            }
        }
        printf("\nSorting finished!\n");

        isSorted = 1;
    }
    else
    {
        printf("\nERROR: Complete array first!\n");
    }
}

int binarySearch(int *array, int left, int right, int searchValue)
{
    if (right >= left)
    {
        int mid = left + (right - left) / 2;
        if (array[mid] == searchValue)
        {
            return mid;
        }
        if (array[mid] > searchValue)
        {
            return binarySearch(array, left, mid - 1, searchValue);
        }
        return binarySearch(array, mid + 1, right, searchValue);
    }
    return -1;
}

void findValue(int *array, int size)
{
    if (isArrayCompleted)
    {
        if (isSorted)
        {
            int searchValue, result;
            printf("\nInsert value to search for: ");
            scanf("%d", &searchValue);

            result = binarySearch(array, 0, size - 1, searchValue);

            if (result == -1)
            {
                printf("\nThere is no such a value :(");
                return;
            }
            printf("\nValue %d was found on index [%d]\n", searchValue, result);
        }
        else
        {
            printf("\nERROR: Sort array first!\n");
        }
    }
    else
    {
        printf("\nERROR: Complete array first!\n");
    }
}

void renderArraysMenu(int *array, int size)
{
    int option, run = 1;

    while (run)
    {
        displayMenuText(arrayMenuText, arrayMenuCount);
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
            completeArray(array, size);
            break;
        case 2:
            showArray(array, size);
            break;
        case 3:
            bubbleSort(array, size);
            break;
        case 4:
            swapIndexes(array);
            break;
        case 5:
            findValue(array, size);
            break;
        case 0:
            isSorted = 0;
            isArrayCompleted = 0;
            run = 0;
            break;
        }
    }
}

void arrays()
{
    int size;

    printf("\nInsert array size: ");
    int check = scanf("%d", &size);
    fflush(stdin);

    if (check != 1)
    {
        printf("\nERROR: Only numbers are valid!");
        fscanf(stdin, "%*[^\n]%*c");
        return;
    }

    if (size < 0)
    {
        printf("\nERROR: Size is cannot be negative value!\n");
        return;
    }

    int *array = initializeArray(size);

    renderArraysMenu(array, size);

    free(array);
}