#include <gtest/gtest.h>
// Include C code in C++ bestand
extern "C"
{
    #include "breuk.h"
}

TEST(breuken, optellen)
{
    Breuk a = {1, 3}, b = {2, 4};

    // Als init niet werkt heeft verder testen geen zin
    ASSERT_EQ(a.teller, 1);
    ASSERT_EQ(a.noemer, 3);
    ASSERT_EQ(b.teller, 2);
    ASSERT_EQ(b.noemer, 4);
    
    Breuk c = add(a, b);
    // Check resultaat
    EXPECT_EQ(c.teller, 5);
    EXPECT_EQ(c.noemer, 6);
}

TEST(breuken, vermenigvuldigen)
{
    Breuk a = {1, 3}, b = {2, 4};

    Breuk c = mul(a, b);
    // Check resultaat
    EXPECT_EQ(c.teller, 1);
    EXPECT_EQ(c.noemer, 6);
}

TEST(breuken, nul)
{
    Breuk a = {0, 1}, b = {2, 4};

    Breuk c = add(a, b);
    EXPECT_EQ(c.teller, 1);
    EXPECT_EQ(c.noemer, 2);

    Breuk d = mul(a, b);
    EXPECT_EQ(d.teller, 0);
    EXPECT_EQ(d.noemer, 1);
} 
