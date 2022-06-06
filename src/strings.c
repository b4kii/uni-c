#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "../inc/arrays.h"

char *stringsMenuText[] = {
    "\nChoose exercise:\n\n",
    "Change text to lower case [1]\n",
    "Change text to upper case [2]\n"
    "Concatenate text [3]\n",
    "Check if word is palindrom [4]\n",
    "Swap characters [5]\n",
    "Check substring occurances [6]\n",
    "Count letters in sentence [7]\n",
    "Go back [0]\n\n",
    "Select: "};

int stringsMenuCount = sizeof(stringsMenuText) / sizeof(stringsMenuText[0]);

#define ALPHABET_COUNT 26
typedef struct alpha
{
    char letter;
    int count;
} Alphabet;

void completeAlphabet(Alphabet *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i].letter = 97 + i;
        array[i].count = 0;
    }
}

void showAlphabet(Alphabet *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%c - %d\n", array[i].letter, array[i].count);
    }
}

int getIndex(Alphabet *array, int size, char letter)
{
    int index;
    for (int i = 0; i < size; i++)
    {
        if (letter == array[i].letter)
        {
            index = i;
        }
    }
    return index;
}

void countLetters()
{
    Alphabet letters[ALPHABET_COUNT];
    completeAlphabet(letters, ALPHABET_COUNT);

    char userInput[255];
    printf("\nInsert sentence: ");
    fgets(userInput, 255, stdin);
    strtok(userInput, "\n");

    char *temp = userInput;

    while (*temp)
    {
        *temp = tolower(*temp);
        if (*temp >= 97 && *temp <= 122)
        {
            int index = getIndex(letters, ALPHABET_COUNT, *temp);
            letters[index].count++;
        }
        ++temp;
    }
    showAlphabet(letters, ALPHABET_COUNT);
}

void checkOccurances()
{
    char userInput[255], substring[255];
    int count = 0, occurances = 0;

    printf("\nInsert sentence: ");
    fgets(userInput, 255, stdin);
    strtok(userInput, "\n");

    printf("Insert substring: ");
    fgets(substring, 255, stdin);
    strtok(substring, "\n");

    char *tempUserInput = userInput;
    char *tempSubstring = substring;
    int substringLenght = strlen(substring);

    while (*tempUserInput)
    {
        if (*tempSubstring == '\0' || *tempSubstring != *tempUserInput)
        {
            tempSubstring = substring;
        }
        if (*tempSubstring == *tempUserInput)
        {
            ++count;
        }
        if (count == substringLenght)
        {
            count = 0;
            ++occurances;
        }
        ++tempSubstring;
        ++tempUserInput;
    }

    printf("\nOccurances: %d\n", occurances);
}

void swapChar()
{
    char userInput[255], toSwap, substitution;
    printf("\nInsert sentence: ");
    fgets(userInput, 255, stdin);
    strtok(userInput, "\n");

    printf("\nInsert character [(to swap) (substitution)]: ");
    scanf("%c %c", &toSwap, &substitution);
    fflush(stdin);

    char *temp = userInput;
    while (*temp)
    {
        if (*temp == toSwap)
        {
            *temp = substitution;
        }

        ++temp;
    }

    puts(userInput);
}

void isPalindrom()
{
    char userInput[255];
    printf("\nInsert word: ");
    fgets(userInput, 255, stdin);
    strtok(userInput, "\n");

    int size = strlen(userInput), count = 0;

    for (int i = 0, j = size - 1; i < size / 2; ++i, --j)
    {
        if (userInput[i] == userInput[j])
        {
            ++count;
        }
    }

    if (count == (size / 2))
    {
        printf("\nWord \"%s\" is a palindrom", userInput);
    }
    else
    {
        printf("\nWord \"%s\" is NOT a palindrom", userInput);
    }
}

void customToLower()
{
    char userInput[255];
    printf("\nInsert text: ");
    fgets(userInput, 255, stdin);
    strtok(userInput, "\n");

    char *temp = userInput;
    printf("\nOUTPUT: ");
    while (*temp)
    {
        printf("%c", *temp | 32);
        ++temp;
    }
}

void customToUpper()
{
    char userInput[255];
    printf("\nInsert text: ");
    fgets(userInput, 255, stdin);
    strtok(userInput, "\n");

    char *temp = userInput;
    printf("\nOUTPUT: ");
    while (*temp)
    {
        printf("%c", *temp & ~32);
        ++temp;
    }
}

void concatenateWords()
{
    char firstText[255], secondText[255];
    printf("\nInsert first text: ");
    fgets(firstText, 255, stdin);
    strtok(firstText, "\n");

    printf("Insert second text: ");
    fgets(secondText, 255, stdin);
    strtok(secondText, "\n");

    int size = strlen(firstText) + strlen(secondText) + 1;

    char *tempFirstText = firstText;
    char *tempSecondText = secondText;
    char *thirdText = (char *)malloc(sizeof(char) * size);

    while (*tempFirstText)
    {
        *thirdText = *tempFirstText;

        ++thirdText;
        ++tempFirstText;
    }
    while (*tempSecondText)
    {
        *thirdText = *tempSecondText;

        ++thirdText;
        ++tempSecondText;
    }

    *thirdText = '\0';

    puts(thirdText - (size + 1));

    free(thirdText);
}

void renderStringsMenu()
{
    int option, run = 1;
    while (run)
    {
        displayMenuText(stringsMenuText, stringsMenuCount);
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
            customToLower();
            break;
        case 2:
            customToUpper();
            break;
        case 3:
            concatenateWords();
            break;
        case 4:
            isPalindrom();
            break;
        case 5:
            swapChar();
            break;
        case 6:
            checkOccurances();
            break;
        case 7:
            countLetters();
            break;
        case 0:
            run = 0;
            break;
        }
    }
}

void strings()
{
    renderStringsMenu();
}