#include <stdio.h>
#include <stdlib.h>

int *still_reachable = NULL;
int *global_but_freed = NULL;
int *possibly_lost = NULL;

int main() {
    /* Nothing wrong here */
    global_but_freed = malloc(1*sizeof(int));

    /* Not freeing this alloc means it is still reachable (because global */
    still_reachable = malloc(2*sizeof(int));

    /* Local pointer to pointers */
    int **indirectly_lost = malloc(3*sizeof(int*));
    indirectly_lost[1] = malloc(4*sizeof(int));

    /* To show some errors */
    int *errors = malloc(5*sizeof(int));

    /* To show possibly lost */
    possibly_lost = malloc(6*sizeof(int));

    /* Still points to allocated memory, but not the (start) value returned by malloc. */
    possibly_lost++;

    /* Conditional based on uninitialised value */
    if(errors[0] > 0){
      errors[1] = 6;
    }

    /* Out of bounds */
    errors[7] = 20;

    /* Nothing wrong here */
    free(global_but_freed);

    /* Use after free */
    global_but_freed[0] = 4;

    return 0;
}
