#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "WyrazenieZesp.hh"
#include "Statystyki.hh"
#include <string>
#include <sstream>
#include <iostream>


std::string toString( std::ostream& str){
        std::ostringstream ss;
        ss << str.rdbuf();
        return ss.str();
    }

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
        a.Arg2.im=2;
        a.Op = Op_Dodaj;
        a.Wyn = Oblicz(a);
        std::stringstream str;
        str << a.Wyn;
        std::string g = toString(str);
        std::string temp;
        temp = "(3+3i)";
        CHECK(temp == g);
    }
    }
    if(i==1){
    SUBCASE("Odejmowanie"){
        a.Arg1.re=1;
        a.Arg1.im=0;
        a.Arg2.re=0;
        a.Arg2.im=1;
        a.Op = Op_Odejmij;
        a.Wyn = Oblicz(a);
        std::stringstream str;
        str << a.Wyn;
        std::string g = toString(str);
        std::string temp;
        temp = "(1-1i)";
        CHECK(temp == g);
    }
    }
    if(i==2){
    SUBCASE("Mnozenie"){
        a.Arg1.re=3;
        a.Arg1.im=0;
        a.Arg2.re=0;
        a.Arg2.im=3;
        a.Op = Op_Mnoz;
        a.Wyn = Oblicz(a);
        std::stringstream str;
        str << a.Wyn;
        std::string g = toString(str);
        std::string temp;
        temp = "(0+9i)";
        CHECK(temp == g);
    }
    }
    if(i==3){
    SUBCASE("Dzielenie"){
        a.Arg1.re=4;
        a.Arg1.im=8;
        a.Arg2.re=1;
        a.Arg2.im=0;
        a.Op = Op_Dziel;
        a.Wyn = Oblicz(a);
        std::stringstream str;
        str << a.Wyn;
        std::string g = toString(str);
        std::string temp;
        temp = "(4+8i)";
        CHECK(temp == g);
    }
    }
    i++;}
    
}

TEST_CASE("Test modulu statystyki czy procent odpowiedzi prawidlowych jest poprawny"){
    Staty Test;
    double proc2;
    Test.popr = 5;
    Test.lpyt = 10;
    proc2 = Procent(Test);
    double proc1 = 50;
    CHECK(proc2 == proc1);
}