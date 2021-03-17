#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH

#include <ostream>
#include "LZespolona.hh"


/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };

// ostream & operator << (ostream & StrmWy, Operator Op){

//   const char ZnakOp[] = "+-*/";
//   return StrmWy << ZnakOp[Op];
// }


/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
struct WyrazenieZesp {
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego
  LZespolona   Wyn;
};

// void Wyswietl(WyrazenieZesp  WyrZ);
// void WyswietlWyr(WyrazenieZesp  WyrZ);
// void wyswietlSym(Operator ope);
// Prototypy przeciazen operatorow przesuniecia bitowego w lewo 
//Pozwalajace wyswietlic operator miedzy liczbami zespolonymi oraz cale wyrazenie zespolone 
std::ostream & operator<< (std::ostream &stream , const Operator & ope);
std::ostream & operator<< (std::ostream &stream , const WyrazenieZesp & cos);
std::istream & operator >> (std::istream &stream, Operator &op);
std::istream & operator >> (std::istream &stream, WyrazenieZesp &WyrZ);
WyrazenieZesp WczytajWyrz ();
Operator WczytajWyrZsym ();
//Prototyp funkcji ktora oblicza wynik wyrazenia zespolonego na podstawie znaku miedzy nimi
LZespolona Oblicz(WyrazenieZesp  WyrZ);


#endif
