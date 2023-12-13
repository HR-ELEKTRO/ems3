void test_FIFO_behavior(void)
{
    // write 1, 2 and 3 into the buffer
    TEST(buffer_put(1), "value 1 can not be written into the buffer")
    TEST(!buffer_is_empty(), "buffer still empty after writing into the buffer")
    TEST(!buffer_is_full(), "buffer full after writing only one int into the buffer")
    TEST(buffer_put(2), "value 2 can not be written into the buffer")
    TEST(!buffer_is_full(), "buffer full after writing two ints into the buffer")
    TEST(buffer_put(3), "value 3 can not be written into the buffer")
    TEST(!buffer_is_full(), "buffer full after writing three ints into the buffer")
    // test if values can be retrieved in FIFO order from the buffer
    int retrieved_value;
    TEST(buffer_get(&retrieved_value), "retrieving 1 from the buffer failed")
    TEST(retrieved_value == 1, "wrong value (%d) retrieved from the buffer, expected 1", retrieved_value)
    TEST(buffer_get(&retrieved_value), "retrieving 2 from the buffer failed")
    TEST(retrieved_value == 2, "wrong value (%d) retrieved from the buffer, expected 2", retrieved_value)
    TEST(buffer_get(&retrieved_value), "retrieving 3 from the buffer failed")
    TEST(retrieved_value == 3, "wrong value (%d) retrieved from the buffer, expected 3", retrieved_value)
    TEST(buffer_is_empty(), "buffer not empty after writing and retrieving three ints to and from the buffer")
}
