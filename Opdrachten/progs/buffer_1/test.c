#include <stdio.h>

#include "buffer.h"

static int tests = 0;
static int fails = 0;

#define TEST(condition, ...) \
    tests++;\
    if (!(condition))\
    {\
        fails++;\
        printf("Error: ");\
        printf(__VA_ARGS__);\
        printf("\n");\
    }

#define PRINT_TEST_REPORT\
    printf("%d tests performed: %d succeded, %d failed.\n", tests, tests - fails, fails);

void test_put_and_get(int test_value)
{
    // test if test_value can be written into the buffer
    TEST(buffer_put(test_value), "value %d can not be written into the buffer", test_value)
    TEST(!buffer_is_empty(), "buffer still empty after writing into the buffer")
    // test if test_value can be retrieved from the buffer
    int retrieved_value;
    TEST(buffer_get(&retrieved_value), "retrieving %d from the buffer failed", test_value)
    TEST(retrieved_value == test_value, "wrong value (%d) retrieved from the buffer, expected %d", retrieved_value, test_value)
    TEST(buffer_is_empty(), "buffer not empty after writing and retrieving one int to and from the buffer")
}

int main(void)
{
    // test if the buffer is empty at startup
    TEST(buffer_is_empty(), "buffer not empty at startup")
    // test if the buffer is not full at startup
    TEST(!buffer_is_full(), "buffer full at startup")
    // test if value 42 can be written into and retrieved from the buffer
    test_put_and_get(42);
    // test if value 0 can be written into and retrieved from the buffer
    test_put_and_get(0);
    // write to the buffer until it is full
    while (buffer_put(13)) /* do nothing */;
    TEST(buffer_is_full(), "buffer not full after put failed")
    // retrieve from the buffer until it is empty
    int retrieved_value;
    while (buffer_get(&retrieved_value)) /* do nothing */;
    TEST(buffer_is_empty(), "buffer not empty after get failed")
    TEST(retrieved_value == 13, "retrieved value overridden after get failed, expected 13 but got %d", retrieved_value)

    PRINT_TEST_REPORT
    return 0;
}
