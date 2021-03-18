#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "BazaTestu.hh"
#include <string>
#include <sstream>
#include <iostream>


// std::string costam( std::ostream& str){
//         std::ostringstream ss;
//         ss << str.rdbuf();
//         return ss.str();
//     }

// TEST_CASE("Test wyswietlania wyrazenia zespolonego"){
    
//     WyrazenieZesp x;
//     x.Arg1.re = 2;
//     x.Arg1.im = 2;
//     x.Op = Op_Dodaj;
//     x.Arg2.re = 1;
//     x.Arg2.im = 1;
//     std::stringstream stream;
//     stream << x;
//     std::string g = costam(stream);
//     std::string str;
//     str = "(2+2i) + (1+1i) =";
//     CHECK(str == g);

// }
TEST_CASE("Test wyniki dla poszczególnych wyników wyrazenia zespolonego"){

    int i = 0;
    WyrazenieZesp a;
    while(i<4){
    if(i==0){
    SUBCASE("Dodawanie"){
        a.Arg1.re=2;
        a.Arg1.im=1;
        a.Arg2.re=1;
        a.Arg2.re=2;
        a.Op = Op_Dodaj;
        a.Wyn = Oblicz(a);
        LZespolona x;
        x.re = 3;
        x.im = 3;
        CHECK(x == a.Wyn);
    }
    }
    if(i==1){
    SUBCASE("Odejmowanie"){
        LZespolona x;
        x.re = 1;
        x.im = -1;
        CHECK(x == a.Wyn);
    }
    }
    if(i==2){
    SUBCASE("Mnozenie"){
        LZespolona x;
        x.re = 0;
        x.im = 9;
        CHECK(x == a.Wyn);
    }
    }
    if(i==3){
    SUBCASE("Dzielenie"){
        LZespolona x;
        x.re = 4;
        x.im = 8;
        CHECK(x == a.Wyn);
    }
    }
    i++;}
    
}