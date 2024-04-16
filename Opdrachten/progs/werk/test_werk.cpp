#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <sstream>
#include "freelancer.h"
#include "vaste_kracht.h"
#include "print_maandsalaris.h"

using namespace std;

TEST(werk, test1)
{
    Freelancer f {1, 25.75}; // werknemer 1 verdient 25.75 per uur
    Vaste_kracht v {2, 1873.53}; // werknemer 2 verdient 1873.53 per maand
    
    f.werk_uren(84); // werknemer 1 werkt (deze maand) 84 uren
    
    ostringstream out1;
    print_maandsalaris(out1, f);
    EXPECT_EQ(out1.str(), "Werknemer: 1 verdient:  2163.00 Euro.\n");
    ostringstream out2;
    print_maandsalaris(out2, v);
    EXPECT_EQ(out2.str(), "Werknemer: 2 verdient:  1873.53 Euro.\n");
    
    f.werk_uren(13.5); // werknemer 1 werkt (deze maand) 13.5 uren
    
    ostringstream out3;
    print_maandsalaris(out3, f);
    EXPECT_THAT(out3.str(), testing::MatchesRegex("Werknemer: 1 verdient:   347.6[23] Euro.\n"));
    ostringstream out4;
    print_maandsalaris(out4, v);
    EXPECT_EQ(out4.str(), "Werknemer: 2 verdient:  1873.53 Euro.\n");
}

/*
#include "stukwerker.h"

TEST(werk, test2)
{
    Freelancer f {1, 25.75}; // werknemer 1 verdient 25.75 per uur
    Vaste_kracht v {2, 1873.53}; // werknemer 2 verdient 1873.53 per maand
    Stukwerker s {3, 1.05}; // werknemer 3 verdient 1.05 per stuk

    f.werk_uren(84); // werknemer 1 werkt (deze maand) 84 uren
    s.produceer_stuks(1687); // werknemer 3 produceert (deze maand) 1687 stuks

    ostringstream out1;
    print_maandsalaris(out1, f);
    EXPECT_EQ(out1.str(), "Werknemer: 1 verdient:  2163.00 Euro.\n");
    ostringstream out2;
    print_maandsalaris(out2, v);
    EXPECT_EQ(out2.str(), "Werknemer: 2 verdient:  1873.53 Euro.\n");
    ostringstream out3;
    print_maandsalaris(out3, s);
    EXPECT_EQ(out3.str(), "Werknemer: 3 verdient:  1771.35 Euro.\n");
    
    f.werk_uren(13.5); // werknemer 1 werkt (deze maand) 13.5 uren
    s.produceer_stuks(0); // werknemer 3 produceert (deze maand) 0 stuks
    
    ostringstream out4;
    print_maandsalaris(out4, f);
    EXPECT_THAT(out4.str(), testing::MatchesRegex("Werknemer: 1 verdient:   347.6[23] Euro.\n"));
    ostringstream out5;
    print_maandsalaris(out5, v);
    EXPECT_EQ(out5.str(), "Werknemer: 2 verdient:  1873.53 Euro.\n");
    ostringstream out6;
    print_maandsalaris(out6, s);
    EXPECT_EQ(out6.str(), "Werknemer: 3 verdient:     0.00 Euro.\n");
}
*/

/*
#include "manager.h"

TEST(werk, test3)
{
    Stukwerker s(1, 1.05); // werknemer 1 verdient 1.05 per stuk
    Freelancer f(2, 25.75); // werknemer 2 verdient 25.75 per uur
    Vaste_kracht v1(3, 1873.53); // werknemer 3 verdient 1873.53 per maand
    
    Manager m1(4); // werknemer 4 is de manager van:
    m1.geeft_leiding_aan(s); // -  werknemer 1
    m1.geeft_leiding_aan(f); // -  werknemer 2
    m1.geeft_leiding_aan(v1);// -  werknemer 3
    
    Vaste_kracht v2(5, 2036.18); // werknemer 5 verdient 2036,18 per maand
    Manager m2(6); // werknemer 6 is de manager van:
    m2.geeft_leiding_aan(v2); // -  werknemer 5
    m2.geeft_leiding_aan(m1); // -  werknemer 4
    
    s.produceer_stuks(678); // werknemer 1 produceert 678 stuks
    f.werk_uren(84); // werknemer 2 werkt 84 uren

    ostringstream out1;
    print_maandsalaris(out1, s);
    EXPECT_EQ(out1.str(), "Werknemer: 1 verdient:   711.90 Euro.\n");
    ostringstream out2;
    print_maandsalaris(out2, f);
    EXPECT_EQ(out2.str(), "Werknemer: 2 verdient:  2163.00 Euro.\n");
    ostringstream out3;
    print_maandsalaris(out3, v1);
    EXPECT_EQ(out3.str(), "Werknemer: 3 verdient:  1873.53 Euro.\n");
    ostringstream out4;
    print_maandsalaris(out4, m1);
    EXPECT_EQ(out4.str(), "Werknemer: 4 verdient:  3165.62 Euro.\n");
    ostringstream out5;
    print_maandsalaris(out5, v2);
    EXPECT_EQ(out5.str(), "Werknemer: 5 verdient:  2036.18 Euro.\n");
    ostringstream out6;
    print_maandsalaris(out6, m2);
    EXPECT_EQ(out6.str(), "Werknemer: 6 verdient:  5201.80 Euro.\n");
}
*/