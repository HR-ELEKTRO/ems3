#include <gtest/gtest.h>
import std;
import tijd3;
using namespace std;

TEST(Tijdsduur, aanmaken_zonder_argumenten)
{
    Tijdsduur t1; // t1 is 0 uur, 0 minuten en 0 seconden
    ostringstream out1;
    t1.drukaf(out1);
    EXPECT_EQ(out1.str(), "0");
}

/*
TEST(Tijdsduur, aanmaken_alleen_seconden)
{
    Tijdsduur t1 {10}; // t1 is 10 seconden
    ostringstream out1;
    t1.drukaf(out1);
    EXPECT_EQ(out1.str(), "10");
    Tijdsduur t2 {0}; // t2 is 0 seconden
    ostringstream out2;
    t2.drukaf(out2);
    EXPECT_EQ(out2.str(), "0");
}

TEST(Tijdsduur, aanmaken_alleen_minuten_en_seconden)
{
    Tijdsduur t1 {50, 10}; // t1 is 50 minuten en 10 seconden
    ostringstream out1;
    t1.drukaf(out1);
    EXPECT_EQ(out1.str(), "50:10");
    Tijdsduur t2 {50, 0}; // t2 is 50 minuten en 0 seconden
    ostringstream out2;
    t2.drukaf(out2);
    EXPECT_EQ(out2.str(), "50:00");
}

TEST(Tijdsduur, aanmaken_uren_minuten_en_seconden)
{
    Tijdsduur t1 {3, 50, 10}; // t1 is 3 uur, 50 minuten en 10 seconden
    ostringstream out1;
    t1.drukaf(out1);
    EXPECT_EQ(out1.str(), "3:50:10");
    Tijdsduur t2 {2, 1, 0}; // t2 is 2 uur, 1 minuut en 0 seconden
    ostringstream out2;
    t2.drukaf(out2);
    EXPECT_EQ(out2.str(), "2:01:00");
}

TEST(Tijdsduur, normaliseer)
{
    Tijdsduur t1 {3, 122}; // t1 is 3 minuten en 122 seconden
    ostringstream out1;
    t1.drukaf(out1);
    EXPECT_EQ(out1.str(), "5:02"); // 3 minuten en 122 seconden is 5 minuten en 2 seconden
    Tijdsduur t2 {3, -122}; // t2 is 3 minuten en -122 seconden
    ostringstream out2;
    t2.drukaf(out2);
    EXPECT_EQ(out2.str(), "58"); // 3 minuten en -122 seconden is 58 seconden
    Tijdsduur t3 {60, -120, -61}; // t3 is 60 minuten, -120 seconden en -61 seconden
    ostringstream out3;
    t3.drukaf(out3);
    EXPECT_EQ(out3.str(), "57:58:59"); // 60 minuten, -120 seconden en -61 seconden is 57 minuten, 58 seconden en 59 seconden
}

TEST(Tijdsduur, const_aanmaken)
{
    const Tijdsduur t1 {3, 50, 10}; // t1 is 3 uur, 50 minuten en 10 seconden
    ostringstream out1;
    t1.drukaf(out1);
    EXPECT_EQ(out1.str(), "3:50:10");
    const Tijdsduur t2 {3, -122}; // t2 is 3 minuten en -122 seconden
    ostringstream out2;
    t2.drukaf(out2);
    EXPECT_EQ(out2.str(), "58"); // 3 minuten en -122 seconden is 58 seconden
    const Tijdsduur t3 {60, -120, -61}; // t3 is 60 minuten, -120 seconden en -61 seconden
    ostringstream out3;
    t3.drukaf(out3);
    EXPECT_EQ(out3.str(), "57:58:59"); // 60 minuten, -120 seconden en -61 seconden is 57 minuten, 58 seconden en 59 seconden
}

TEST(Tijdsduur, optellen)
{
    Tijdsduur t1 {3, 50, 10}; // t1 is 3 uur, 50 minuten en 10 seconden
    const Tijdsduur kwartier {15, 0}; // kwartier is 15 minuten
    t1.erbij(kwartier); 
    ostringstream out1;
    t1.drukaf(out1);
    EXPECT_EQ(out1.str(), "4:05:10"); // 3 uur, 50 minuten en 10 seconden plus 15 minuten is 4 uur, 5 minuten en 10 seconden
    Tijdsduur t2 {3, 2, 1}; // t2 is 3 uur, 2 minuten en 1 seconde
    Tijdsduur t3 {2, 58, 59}; // t3 is 2 uur, 58 minuten en 59 seconden
    t2.erbij(t3);
    ostringstream out2;
    t2.drukaf(out2);
    EXPECT_EQ(out2.str(), "6:01:00"); // 3 uur, 2 minuten en 1 seconde plus 2 uur, 58 minuten en 59 seconden is 6 uur, 1 minuut en 0 seconden
    t3.erbij(1); // Integer 1 moet automatisch geconverteerd worden naar Tijdsduur{0, 0, 1} en dan opgeteld worden
    ostringstream out3;
    t3.drukaf(out3);
    EXPECT_EQ(out3.str(), "2:59:00"); // 2 uur, 58 minuten en 59 seconden plus 1 seconde is 2 uur, 59 minuten en 0 seconden
}

TEST(Tijdsduur, kopie_aanmaken)
{
    Tijdsduur t1 {3, 50, 10}; // t1 is 3 uur, 50 minuten en 10 seconden
    Tijdsduur t2 {t1}; // t2 is een kopie van t1
    t1.erbij(15);
    ostringstream out1;
    t1.drukaf(out1);
    EXPECT_EQ(out1.str(), "3:50:25"); // 3 uur, 50 minuten en 10 seconden plus 15 seconden is 3 uur, 50 minuten en 25 seconden
    ostringstream out2;
    t2.drukaf(out2);
    EXPECT_EQ(out2.str(), "3:50:10"); // t2 is een kopie van de originele t1 en is dus 3 uur, 50 minuten en 10 seconden
}

TEST(Tijdsduur, aftrekken)
{
    Tijdsduur t1 {3, 50, 10}; // t1 is 3 uur, 50 minuten en 10 seconden
    const Tijdsduur kwartier {15, 0}; // kwartier is 15 minuten
    t1.eraf(kwartier);
    ostringstream out1;
    t1.drukaf(out1);
    EXPECT_EQ(out1.str(), "3:35:10"); // 3 uur, 50 minuten en 10 seconden min 15 minuten is 3 uur, 35 minuten en 10 seconden
    Tijdsduur t2 {3, 2, 1}; // t2 is 3 uur, 2 minuten en 1 seconde
    Tijdsduur t3 {2, 58, 59}; // t3 is 2 uur, 58 minuten en 59 seconden
    t2.eraf(t3);
    ostringstream out2;
    t2.drukaf(out2);
    EXPECT_EQ(out2.str(), "3:02"); // 3 uur, 2 minuten en 1 seconde min 2 uur, 58 minuten en 59 seconden is 3 minuten en 2 seconden
    t3.eraf(1); // Integer 1 moet automatisch geconverteerd worden naar Tijdsduur{0, 0, 1} en dan afgetrokken worden
    ostringstream out3;
    t3.drukaf(out3);
    EXPECT_EQ(out3.str(), "2:58:58"); // 2 uur, 58 minuten en 59 seconden min 1 seconde is 2 uur, 58 minuten en 58 seconden
}

TEST(Tijdsduur, vermenigvuldigen)
{
    Tijdsduur t1 {3, 50, 10}; // t1 is 3 uur, 50 minuten en 10 seconden
    t1.maal(2);
    ostringstream out1;
    t1.drukaf(out1);
    EXPECT_EQ(out1.str(), "7:40:20"); // 3 uur, 50 minuten en 10 seconden maal 2 is 7 uur, 40 minuten en 20 seconden
    Tijdsduur t2 {15}; // t2 is 15 seconden
    t2.maal(5);
    ostringstream out2;
    t2.drukaf(out2);
    EXPECT_EQ(out2.str(), "1:15"); // 15 seconden maal 5 is 1 minuut en 15 seconden
}
*/