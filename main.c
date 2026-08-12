#include <stdio.h>
#include "validationFunction.h"
#include "generateComputerItem.h"
#include "itemsValues.h"

int main()
{

    int userItem, computerItem, countComputerVictory = 0, countUserVictory = 0;

    printf("Welcome to \"Rock, Paper, Scissors\" game!\n");

    while (1) //makes the game cyclic
    {
        validationFunction(&userItem);

        computerItem = (enum Items)(generateComputerItem());

        if (computerItem == ROCK)
        {
            printf("Computer chose ROCK!\n");
        }
        else if (computerItem == PAPER)
        {
            printf("Computer chose PAPER!\n");
        }
        else if (computerItem == SCISSORS)
        {
            printf("Computer chose SCISSORS!\n");
        }

        int result = computerItem - userItem;

        if (result == 0)
        {
            printf("Oops! It looks like a tie!\n");
        }
        else if (result == -2 || result == 1)
        {
            countComputerVictory += 1;
            printf("Computer wins!\n");
        }
        else if (result == -1 || result == 2)
        {
            countUserVictory += 1;
            printf("You win!\n");
        }

        printf("Computer victories: %d\n", countComputerVictory);
        printf("Your victories: %d\n", countUserVictory);
        printf("------------------------------------------------------------------\n");
    }

    return 0;
}