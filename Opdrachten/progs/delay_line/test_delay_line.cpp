#include <gtest/gtest.h>
#include <sstream>
#include "delay_line.h"

using namespace std;

TEST(delay_line, int)
{
    Delay_line d;
//  Delay_line<int, 8> d;
    // put samples in delay line and see if the samples are delayed by 8 samples.
    // call put before get and alternate calls
    // first put 8 samples and then get 8 samples with value zero
    for (int i{1}; i <= 8; ++i) {
        d.put(i);
        EXPECT_EQ(d.get(), 0);
    }
    // put 9th sample and get the first sample
    d.put(9);
    EXPECT_EQ(d.get(), 1);
    // calls to get without put return the same sample
    for (int i {0}; i < 10; ++i) {
        EXPECT_EQ(d.get(), 1);
    }
    // calls to put without get override each other
    d.put(10);
    d.put(11); // 11 overrides 10
    d.put(12); // 12 overrides 11
    EXPECT_EQ(d.get(), 2);
    d.put(13);
    EXPECT_EQ(d.get(), 3);
    d.put(14);
    EXPECT_EQ(d.get(), 4);
    d.put(15);
    EXPECT_EQ(d.get(), 5);
    d.put(16);
    EXPECT_EQ(d.get(), 6);
    d.put(17);
    EXPECT_EQ(d.get(), 7);
    d.put(18);
    EXPECT_EQ(d.get(), 8);
    d.put(19);
    EXPECT_EQ(d.get(), 9);
    d.put(20);
    EXPECT_EQ(d.get(), 12); // 10 and 11 where overridden by 12
}

/*
TEST(delay_line, float)
{
    Delay_line<float, 4> d;
    // put samples in delay line and see if the samples are delayed by 4 samples.
    // call put before get and alternate calls
    // first put 4 samples and then get 4 samples with value zero
    for (int i{1}; i <= 4; ++i) {
        d.put(i / 10.0f);
        EXPECT_FLOAT_EQ(d.get(), 0.0);
    }
    // put 5th sample and get the first sample
    d.put(0.5);
    EXPECT_FLOAT_EQ(d.get(), 0.1);
    // calls to get without put return the same sample
    for (int i {0}; i < 10; ++i) {
        EXPECT_FLOAT_EQ(d.get(), 0.1);
    }
    // calls to put without get override each other
    d.put(0.6);
    d.put(0.7); // 0.7 overrides 0.6
    d.put(0.8); // 0.8 overrides 0.7
    EXPECT_FLOAT_EQ(d.get(), 0.2);
    d.put(0.9);
    EXPECT_FLOAT_EQ(d.get(), 0.3);
    d.put(1.0);
    EXPECT_FLOAT_EQ(d.get(), 0.4);
    d.put(1.1);
    EXPECT_FLOAT_EQ(d.get(), 0.5);
    d.put(1.2);
    EXPECT_FLOAT_EQ(d.get(), 0.8); // 0.6 and 0.7 where overridden by 0.8
}
*/
/*
TEST(delay_line, Tijdsduur)
{
    Delay_line<Tijdsduur, 2> d;
    Tijdsduur t1(10, 59, 59);
    d.put(t1);
    ostringstream out1;
    out1 << d.get();
    EXPECT_EQ(out1.str(), "0");
    t1 += 1;
    d.put(t1);
    ostringstream out2;
    out2 << d.get();
    EXPECT_EQ(out2.str(), "0");
    t1 += 1;
    d.put(t1);
    ostringstream out3;
    out3 << d.get();
    EXPECT_EQ(out3.str(), "10:59:59");
    t1 += 1;
    d.put(t1);
    ostringstream out4;
    out4 << d.get();
    EXPECT_EQ(out4.str(), "11:00:00");
}
*/
