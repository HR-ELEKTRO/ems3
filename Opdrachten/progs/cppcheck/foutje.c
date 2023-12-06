#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Dit programma bevat een subtiel foutje, dat door cppcheck wordt gevonden.
// Dit programma bevat ook een memory leak, maar dat wordt niet gemeld door cppcheck.

// Bepaal of pointer pi naar een positief getal wijst
bool isPos(int *pi)
{
    return *pi > 0 && pi != NULL;
}

int main(void)
{
    int *p = malloc(sizeof(int));
    if (p != NULL) 
        *p = 15;
    if (isPos(p))
        printf("*p is positief, zoals verwacht!\n");
    // Dit gebeurt in bovenstaande code alleen als malloc NULL teruggeeft:
    if (isPos(NULL))
        printf("*NULL is positief!\n");
    return 0;
}
 
