#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

// Include C code in C++ bestand
extern "C"
{
    #include "breuk.h"
}

TEST_CASE("rekenen met breuken", "[breuken]")
{
    // Init voor meerdere sections
    Breuk a = {1, 3}, b = {2, 4};

    // Als init niet werkt heeft verder testen geen zin
    REQUIRE(a.teller == 1);
    REQUIRE(a.noemer == 3);
    REQUIRE(b.teller == 2);
    REQUIRE(b.noemer == 4);
    
    SECTION("optellen"){
        // Add 
        Breuk c = add(a, b);
        // Check resultaat
        CHECK(c.teller == 5);
        CHECK(c.noemer == 6);
    }

    SECTION("vermenigvuldigen"){
        // Mul 
        Breuk c = mul(a, b);
        // Check resultaat
        CHECK(c.teller == 1);
        CHECK(c.noemer == 6);
    }

    SECTION("nul"){
        // Init voor deze section
        Breuk a = {0, 1};

        Breuk c = add(a, b);
        CHECK(c.teller == 1);
        CHECK(c.noemer == 2);

        Breuk d = mul(a, b);
        CHECK(d.teller == 0);
        CHECK(d.noemer == 1);
    } 

}
