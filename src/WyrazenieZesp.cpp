#include "WyrazenieZesp.hh"
#include <iostream>



/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */


//Funkcja obliczajaca wynik dzialania na dwoch liczbach zespolonych
LZespolona Oblicz(WyrazenieZesp  WyrZ){
    LZespolona arg;
    
    switch(WyrZ.Op){
        case Op_Dodaj:
        return arg = WyrZ.Arg1 + WyrZ.Arg2;
        break;

        case Op_Odejmij:
        return arg = WyrZ.Arg1 - WyrZ.Arg2;
        break;

        case Op_Mnoz:
        return arg = WyrZ.Arg1 * WyrZ.Arg2;
        break;

        case Op_Dziel:
        return arg = WyrZ.Arg1 / WyrZ.Arg2;
        break;
    
    }
    return arg;
}

// Funkcja pozwalajaca wczytac operator wyrazenia zespolonego
Operator WczytajWyrZsym (){
    Operator op;
    char oper;
    std::cin>>oper;
    switch(oper){
        case '+':
            oper = Op_Dodaj;
            break;
        case '-':
            oper = Op_Odejmij;
            break;
        case '*':
            oper = Op_Mnoz;
            break;
        case '/':
            oper = Op_Dziel;
            break;
    }
    return op;
}

// Funkcja pozwalajaca na wczytanie wyrazenia zespolonego z klawiatury
// Poprzez wczytanie 1 liczby zespolonej znaku miedzy liczbami i 2 liczbe zespolona
// oraz zwraca wczytane wyrazenie zespolone
WyrazenieZesp WczytajWyrz (){
    LZespolona tmp1, tmp2;
    WyrazenieZesp WyrZ;
    tmp1 = Wczytaj();
    Operator op = WczytajWyrZsym();
    tmp2 = Wczytaj();
    WyrZ.Arg1 = tmp1;
    WyrZ.Op = op;
    WyrZ.Arg2 = tmp2;
    // std::cout << WyrZ << std::endl;
    return WyrZ;
}

// Przeciazenie operatora przesuniecia bitowego w prawo pozwalajace wczytac operator z konsoli
std::istream & operator >> (std::istream &stream, Operator &op){
    
    char oper;
    stream>>oper;
    switch(oper){
        case '+':
            oper = Op_Dodaj;
            break;
        case '-':
            oper = Op_Odejmij;
            break;
        case '*':
            oper = Op_Mnoz;
            break;
        case '/':
            oper = Op_Dziel;
            break;
    }
    return stream;
}

// Przeciazenie operatora przesuniecia bitowego w prawo pozwalajaca wczytac wyrazenie zespolone
std::istream & operator >> (std::istream &stream, WyrazenieZesp &WyrZ){
    stream >> WyrZ.Arg1;
    stream >> WyrZ.Op;
    stream >> WyrZ.Arg2;
    return stream;
}

//void Wyswietlsym(Operator ope)
//Przeciazenie operatora przesuniecia bitowego w lewo tak by wyswietla symbol w wyrazeniu zespolonym
std::ostream & operator << (std::ostream &stream , const Operator & ope){
    switch (ope){
        case Op_Dodaj:
        stream << " + ";
        break;

        case Op_Odejmij:
        stream << " - ";
        break;

        case Op_Mnoz:
        stream << " * ";
        break;

        case Op_Dziel:
        stream << " / ";
        break;
    }
    return stream;
}

// void Wyswietl(LZespolona temp){

//     std::cout << "(" << temp.re << std::showpos << temp.im << "i)" << std::noshowpos;

// }
// void WyswietlWyr(WyrazenieZesp WyrZ)

//Przeciazenie operatora bitowego w lewo ktore pozwala wyswietlic cale wyrazenie zespolone
std::ostream & operator<< (std::ostream &stream , const WyrazenieZesp & cos){

    stream << cos.Arg1;
    stream << cos.Op;
    stream << cos.Arg2 << std::endl;
    // Wyswietl(WyrZ.Arg1);
    // wyswietlSym(WyrZ.Op);
    // Wyswietl(WyrZ.Arg2);
    // stream << " ="<< std::endl;
    return stream;
}






