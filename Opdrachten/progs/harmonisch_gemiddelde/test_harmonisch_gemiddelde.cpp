#include <gtest/gtest.h>
import std;
import harmonisch_gemiddelde;
using namespace std;

TEST(harmonisch_gemiddelde, ints)
{
    vector ints {100, 200, 300, 400};
    EXPECT_DOUBLE_EQ(harmonisch_gemiddelde(ints), 192.0);
}

TEST(harmonisch_gemiddelde, doubles)
{
    vector doubles {1.0, 1.2};
    EXPECT_DOUBLE_EQ(harmonisch_gemiddelde(doubles), 1.0909090909090908);
}
