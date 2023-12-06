#include "buffer.h"
// implementation for a buffer with ints
// this very simple buffer can only hold one int

// shared variables within this file
static int buffer;
static bool full = false;

bool buffer_put(int i)
{
    if (full) return false;
    buffer = i;
    full = true;
    return true;
}

bool buffer_get(int *p)
{
    if (!full) return false;
    *p = buffer;
    full = false;
    return true;
}

bool buffer_is_full(void)
{
    return full;
}

bool buffer_is_empty(void)
{
    return !full;
}
