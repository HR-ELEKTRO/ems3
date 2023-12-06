#include <assert.h>

#include "breuk.h"
// This implementation contains deliberate errors to demonstrate  the use of unit testing. 

static int ggd(int n, int m)
{
    if (n < 0) n = -n;
    if (m < 0) m = -m;
    while (m != 0)
    {
        int t = m;
    	m = n % m;
        n = t;
    }
    return n;
}

static Breuk normaliseer(Breuk b)
{
    assert(b.noemer != 0);
    int d;
    if (b.noemer < 0)
    {
        b.noemer = -b.noemer;
        b.teller = -b.teller;
    }
    d = ggd(b.teller, b.noemer);
    b.teller /= d;
    b.noemer /= d;
    return b;
}

Breuk add(Breuk b1, Breuk b2)
{
    Breuk som;
    som.teller = b1.teller * b2.noemer + b1.noemer * b2.teller;
    som.noemer = b1.noemer * b2.noemer;
    return normaliseer(som);
}

Breuk sub(Breuk b1, Breuk b2)
{
    b2.teller = -b2.teller;
    return add(b1, b2);
}

Breuk mul(Breuk b1, Breuk b2)
{
    Breuk product;
    product.teller = b1.teller * b2.teller;
    product.noemer = b1.noemer * b2.noemer;
    return normaliseer(product);
}

Breuk divide(Breuk b1, Breuk b2)
{
    Breuk quotient;
    quotient.teller = b1.teller * b2.noemer;
    quotient.noemer = b1.noemer * b2.teller;
    return quotient;
}
