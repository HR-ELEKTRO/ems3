#include <stdio.h>

#include "breuk.h"

int main(void)
{
    Breuk a = {-2, 4}, b = {6, -8};

    Breuk c = add(a, b);
    printf("c = %d/%d\n", c.teller, c.noemer);

    Breuk d = mul(a, b);
    printf("d = %d/%d\n", d.teller, d.noemer);

    return 0;
}
