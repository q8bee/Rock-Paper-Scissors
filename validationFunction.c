#include <stdio.h>
#include "validationFunction.h"
#include "itemsValues.h"

int validationFunction(int *userItem)
{
    int charBuffer; // using integer data type because it can contain "-1" (EOF)
    char charInput;

    printf("Please, make a move, select your item (R/P/S)\n");

    while (1) // guarantees that the program won't work until the user enters valid input
    {

        if ((scanf("%c", &charInput)) != 1) // checks if at least the first symbol of user's input is invalid
        {
            while ((charBuffer = getchar()) != '\n' && charBuffer != EOF); // if user's input is invalid, empty the buffer
            printf("Invalid input. Try again.\n");
            printf("------------------------------------------------------------------\n");
            continue;
        }

        if ((charBuffer = getchar()) != '\n' && charBuffer != EOF) // checks if user entered exactly one symbol
        {                                                                           
            printf("Error. You have inserted spare, unnecessary data. Try again.\n");
            printf("------------------------------------------------------------------\n");
            while ((charBuffer = getchar()) != '\n' && charBuffer != EOF); // if input contains more than one character, empty the buffer
            continue;
        }

        switch (charInput) // check if user's input is a valid item
        {
        case 'R':
        case 'r':
            *userItem = ROCK;
            return 0;
        case 'P':
        case 'p':
            *userItem = PAPER;
            return 0;
        case 'S':
        case 's':
            *userItem = SCISSORS;
            return 0;
        default:
            printf("Invalid input. Try again.\n");
            printf("------------------------------------------------------------------\n");
            break;
        }
    }

    return 0;
}