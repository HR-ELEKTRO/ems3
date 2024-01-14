#include <gtest/gtest.h>
// Include C code in C++ bestand
extern "C"
{
    #include "ems31_2023-2024_groep_XX_submodules/buffer_8/buffer.h"
}

void test_put_and_get(int test_value)
{
    // test if test_value can be written into the buffer
    EXPECT_TRUE(buffer_put(test_value));
    EXPECT_FALSE(buffer_is_empty());
    // test if test_value can be retrieved from the buffer
    int retrieved_value;
    EXPECT_TRUE(buffer_get(&retrieved_value));
    EXPECT_EQ(retrieved_value, test_value);
    EXPECT_TRUE(buffer_is_empty());
}

TEST(buffer, basics)
{
    // test if buffer is empty
    EXPECT_TRUE(buffer_is_empty());
    // test if buffer is not full
    EXPECT_FALSE(buffer_is_full());

    // test if the buffer is empty at startup
    EXPECT_TRUE(buffer_is_empty());
    // test if the buffer is not full at startup
    EXPECT_FALSE(buffer_is_full());
    // test if value 42 can be written into and retrieved from the buffer
    test_put_and_get(42);
    // test if value 0 can be written into and retrieved from the buffer
    test_put_and_get(0);
    // write to the buffer until it is full
    while (buffer_put(13)) /* do nothing */;
    EXPECT_TRUE(buffer_is_full());
    // retrieve from the buffer until it is empty
    int retrieved_value;
    while (buffer_get(&retrieved_value)) /* do nothing */;
    EXPECT_TRUE(buffer_is_empty());
    EXPECT_EQ(retrieved_value, 13);
}

TEST(buffer, FIFO_behavior)
{
    // write 1, 2 and 3 into the buffer
    for (int i = 1; i <= 3; i++)
    {
        EXPECT_TRUE(buffer_put(i));
        EXPECT_FALSE(buffer_is_full());
        EXPECT_FALSE(buffer_is_empty());
    }
    // test if values can be retrieved in FIFO order from the buffer
    int retrieved_value;
    for (int i = 1; i <= 3; i++)
    {
        EXPECT_TRUE(buffer_get(&retrieved_value));
        EXPECT_EQ(retrieved_value, i);
        EXPECT_FALSE(buffer_is_full());
        if (i == 3)
        {
            EXPECT_TRUE(buffer_is_empty());
        }
        else
        {
            EXPECT_FALSE(buffer_is_empty());
        }
    }
}

TEST(buffer, senario_1)
{
    // write 0, 1, ..., and 7 into the buffer
    for (int i = 0; i < 8; i++)
    {
        EXPECT_TRUE(buffer_put(i));
    }
    // buffer should be full now
    EXPECT_TRUE(buffer_is_full());
    // try to write 8 into the buffer
    EXPECT_FALSE(buffer_put(8));
    // retrieve all values from the buffer
    int retrieved_value;
    for (int i = 0; i < 8; i++)
    {
        EXPECT_TRUE(buffer_get(&retrieved_value));
        EXPECT_EQ(retrieved_value, i);
    }
    // buffer should be empty now
    EXPECT_TRUE(buffer_is_empty());
    // try to retrieve a value from the empty buffer
    EXPECT_FALSE(buffer_get(&retrieved_value));
}

TEST(buffer, senario_2)
{
    // write 0, 1, and 2 into the buffer
    for (int i = 0; i < 3; i++)
    {
        EXPECT_TRUE(buffer_put(i));
    }
    // retrieve 0 and 1 from the buffer
    for (int i = 0; i < 2; i++)
    {
        int retrieved_value;
        EXPECT_TRUE(buffer_get(&retrieved_value));
        EXPECT_EQ(retrieved_value, i);
    }
    // write 3, 4, 5, 6, and 7 into the buffer
    for (int i = 3; i < 8; i++)
    {
        EXPECT_TRUE(buffer_put(i));
    }
    // buffer should not be full now
    EXPECT_FALSE(buffer_is_full());
    // retrieve 2, 3, 4, 5, 6, and 7 from the buffer
    for (int i = 2; i < 8; i++)
    {
        int retrieved_value;
        EXPECT_TRUE(buffer_get(&retrieved_value));
        EXPECT_EQ(retrieved_value, i);
    }
    // buffer should be empty now
    EXPECT_TRUE(buffer_is_empty());
}