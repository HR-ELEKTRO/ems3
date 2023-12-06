#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Dit programma bevat een subtiel foutje, dat door cppcheck wordt gevonden.

bool isPos(int *pi)
{
    return *pi > 0 && pi != NULL;
}

int main(void)
{
    int *p = malloc(sizeof(int));
    // Stel dat memory vol is:
    // p = NULL;
    if (p != NULL)
    {        
        *p = 15;
    }
    if (isPos(p))
        printf("*p is positief, zoals verwacht!\n");
    return 0;
}
 