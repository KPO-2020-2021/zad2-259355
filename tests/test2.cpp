#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"
#include <string>
#include <sstream>
#include <iostream>

TEST_CASE("test LZespolona Suma"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -3;

    z.re = 2;
    z.im = -2;
    
    CHECK(x+y == z);
}
TEST_CASE("test LZespolona Róznica"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -3;

    z.re = 0;
    z.im = 4;
    
    CHECK(x-y == z);
}

TEST_CASE("test LZespolona mnozenia"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -3;

    z.re = 4;
    z.im = -2;
    
    CHECK(x*y == z);
}
TEST_CASE("test LZespolona dzielenie"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = 1;

    z.re = 1;
    z.im = 0;
    
    CHECK(x/y == z);
}

TEST_CASE("Test LZespolona operator dodawania (0+0i) "){
    LZespolona x, y, t;
    x.re = 2;
    x.im = 2;

    y.re = 0;
    y.im = 0;

    t.re =2;
    t.im =2;
    CHECK(x+y==t);
}
TEST_CASE("Test LZespolona operator dodawania (0.0 + 0.0i) "){
    LZespolona x, y, t;
    x.re = 2;
    x.im = 2;

    y.re = 0.0;
    y.im = 0.0;

    t.re =2;
    t.im =2;
    CHECK(x+y==t);
}

TEST_CASE("Test LZespolona operator dodawania (0.009 + 0.004i) "){
    LZespolona x, y, t;
    x.re = 2;
    x.im = 2;

    y.re = 0.009;
    y.im = 0.004;

    t.re =2.01;
    t.im =2.00;
    CHECK(x+y==t);
}

TEST_CASE("Test LZespolona operator odejmowania (0+0i) "){
    LZespolona x, y, t;
    x.re = 2;
    x.im = 2;

    y.re = 0;
    y.im = 0;

    t.re =2;
    t.im =2;
    CHECK(x-y==t);
}

TEST_CASE("Test LZespolona operator odejmowania (0.005+0.006) "){
    LZespolona x, y, t;
    x.re = 2;
    x.im = 2;

    y.re = 0.005;
    y.im = 0.006;

    t.re =2;
    t.im =1.99;
    CHECK(x-y==t);
}

TEST_CASE("Test LZespolona operator odejmowania (0.0+0.0i) "){
    LZespolona x, y, t;
    x.re = 2;
    x.im = 2;

    y.re = 0.0;
    y.im = 0.0;

    t.re =2;
    t.im =2;
    CHECK(x-y==t);
}

TEST_CASE("Test LZespolona operator mnozenia przez (0+0i) "){
    LZespolona x, y, t;
    x.re = 2;
    x.im = 2;

    y.re = 0;
    y.im = 0;

    t.re =0;
    t.im =0;
    CHECK(x*y==t);
}

TEST_CASE("Test LZespolona operator mnozenia przez przybliżanie (1.789+0i) "){
    LZespolona x, y, t;
    x.re = 2;
    x.im = 5;

    y.re = 1.789;
    y.im = 0;

    t.re =3.58;
    t.im =8.94;
    CHECK(x*y==t);
}

TEST_CASE("Test LZespolona operator mnozenia przez (1+0i) "){
    LZespolona x, y, t;
    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 0;

    t.re =2;
    t.im =2;
    CHECK(x*y==t);
}
TEST_CASE("Test LZespolona operator mnozenia przez (0+1i) "){
    LZespolona x, y, t;
    x.re = 2;
    x.im = 2;

    y.re = 0;
    y.im = 1;

    t.re =-2;
    t.im =2;
    CHECK(x*y==t);
}
TEST_CASE("Test LZespolona operator mnozenia przez (1+1i) "){
    LZespolona x, y, t;
    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 1;

    t.re =0;
    t.im =4;
    CHECK(x*y==t);
}

TEST_CASE("Test LZespolona dzielenie przez skalar 1") {
    LZespolona x, y;
    double t = 2;
    
    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 1;
   
    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona dzielenie przez skalar 2") {
    LZespolona x, y;
    double t = 3;
    
    x.re = 2;
    x.im = 2;

    y.re = 0.66666;
    y.im = 0.66666;
   
    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona dzielenie przez skalar - zero") {
    LZespolona x;
    double t = 0;
    
    x.re = 2;
    x.im = 2;
 
   WARN_THROWS(x/t);
}

TEST_CASE("Test LZespolona Sprzezenie dla czesci urojonej rownej 0"){
    LZespolona x;
    x.re = 1;
    x.im = 0;
    Sprzezenie(x);

    CHECK(x.im == 0);
}

TEST_CASE("Test LZespolona Sprzezenie dla czesci urojonej niezerowej"){
    LZespolona x;
    x.re = 1;
    x.im = 3;
    Sprzezenie(x);

    CHECK(x.im == -3);
}

TEST_CASE("Test modulu z liczby zespolonej"){
    LZespolona x;
    double y,z ;
    x.re = 2;
    x.im = 3;

    z = Modul2(x);

    y = 13;

    CHECK(z==y);
}

TEST_CASE("Test Wyświetlanie LZespolonej (standard)"){

    LZespolona x;
    x.re = 2;
    x.im = 2;
    std::ostringstream str;
    str << x;
    CHECK("(2.00+2.00i)" == str.str());
}
TEST_CASE("Test Wyświetlanie LZespolonej (zaokrąglenie)"){

    LZespolona x;
    x.re = 2.00/3.00;
    x.im = 2.00/3.00;
    std::ostringstream stream;
    stream << x;
    CHECK("(0.67+0.67i)" == stream.str());
}
TEST_CASE("Test Wczytanie LZespolonej (standardowe) "){

    LZespolona x;
    std::istringstream in("(5+5.20i)");
    in >> x;
    std::ostringstream stream;
    stream << x;
    CHECK("(5.00+5.20i)" == stream.str());
}
TEST_CASE("Test Wczytanie LZespolonej (zaokraglenie) "){
    LZespolona x;
    std::istringstream in("(5.6666+5.3333i)");
    in >> x;
    std::ostringstream stream;
    stream << x;
    CHECK("(5.67+5.33i)" == stream.str());
}

TEST_CASE("Test Porownanie LZespolonej (dodawanie) gdy roznica jest mniejsza badz rowna poprawnie zapisanemu wynikowi "){
    LZespolona x, y;
    x.re = 5.37;
    x.im = 3.83;
    y.re = 5.38;
    y.im = 3.84;
    CHECK(y == x);
}
TEST_CASE("Test Porownanie LZespolonej (odejmowanie) gdy roznica jest mniejsza badz rowna poprawnie zapisanemu wynikowi "){
    LZespolona x, y;
    x.re = -5.37;
    x.im = -3.83;
    y.re = -5.38;
    y.im = -3.84;
    CHECK(y == x);
}
TEST_CASE("Test Porownanie LZespolonej (dodawanie) wraz z zaokragleniem (przed zaokragleniem wykonuje sie porownanie) "){
    LZespolona x, y;
    x.re = 5.379;
    x.im = 3.831;
    y.re = 5.386;
    y.im = 3.843;
    CHECK(y != x);
}
TEST_CASE("Test Porownanie LZespolonej (odejmowanie) wraz z zaokragleniem (przed zaokragleniem wykonuje sie porownanie)"){
    LZespolona x, y;
    x.re = -5.376;
    x.im = -3.836;
    y.re = -5.383;
    y.im = -3.847;
    CHECK(y != x);
}

TEST_CASE("Test Porownanie LZespolonej (dodawanie) wraz z zaokragleniem "){
    LZespolona x, y;
    x.re = 5.379;
    x.im = 3.834;
    y.re = 5.386;
    y.im = 3.843;
    CHECK(y == x);
}

TEST_CASE("Test Porownanie LZespolonej (odejmowanie) wraz z zaokragleniem "){
    LZespolona x, y;
    x.re = -5.376;
    x.im = -3.837;
    y.re = -5.383;
    y.im = -3.846;
    CHECK(y == x);
}