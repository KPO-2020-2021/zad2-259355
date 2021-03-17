#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>
#include <ctype.h>

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};

//Takie tam

/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */

//Przeciazenia operatorow (+,-,*,/) oraz (!=,==)
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2); 
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);
bool operator != (LZespolona  Skl1,  LZespolona  Skl2);
bool operator == (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona Wczytaj();
bool compare(LZespolona tmp);
//Przeciazenia operatorow przesuniec bitowych w prawo i lewo pozwalajace wyswietlic liczbe zespolona 
//Oraz pozwalajace wczytac z klawiatury liczbe zespolona 
std::ostream & operator<< (std::ostream & pom , const LZespolona & cos);
std::istream & operator>> (std::istream &pom,  LZespolona & cos);


#endif
