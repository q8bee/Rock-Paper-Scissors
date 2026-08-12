#include <stdlib.h>
#include <time.h>

int generateComputerItem(void)
{
    srand(time(NULL));
    int itemIndex = rand() % 3; // this number reflects an item from enum "itemsValues"

    return itemIndex;
}