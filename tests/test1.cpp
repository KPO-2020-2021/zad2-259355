#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "WyrazenieZesp.hh"
#include "Statystyki.hh"
#include <string>
#include <sstream>
#include <iostream>


TEST_CASE("Test wyswietlania wyrazenia zespolonego (standardowe)"){
    
    WyrazenieZesp x;
    x.Arg1.re = 2;
    x.Arg1.im = 2;
    x.Op = Op_Dodaj;
    x.Arg2.re = 1;
    x.Arg2.im = 1;
    std::ostringstream stream;
    stream << x;
    CHECK("(2.00+2.00i) + (1.00+1.00i) =" == stream.str());

}

TEST_CASE("Test wyswietlania wyrazenia zespolonego (zaokraglenie)"){
    
    WyrazenieZesp x;
    x.Arg1.re = 2.335;
    x.Arg1.im = 2.663;
    x.Op = Op_Dodaj;
    x.Arg2.re = 1.307;
    x.Arg2.im = 1.186;
    std::ostringstream stream;
    stream << x;
    CHECK("(2.33+2.66i) + (1.31+1.19i) =" == stream.str());

}

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
        std::ostringstream stream;
        stream << a.Wyn;
        CHECK(("(3.00+3.00i)") == stream.str());
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
        std::ostringstream stream;
        stream << a.Wyn;
        CHECK("(1.00-1.00i)" == stream.str());
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
        std::ostringstream stream;
        stream << a.Wyn;
        CHECK("(0.00+9.00i)" == stream.str());
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
        std::ostringstream stream;
        stream << a.Wyn;
        CHECK("(4.00+8.00i)" == stream.str());
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