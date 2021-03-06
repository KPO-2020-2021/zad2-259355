#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>
#include <ctype.h>
#include <cmath>


using namespace std;
/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
class  LZespolona { 
  public:
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
  double arg;
  LZespolona  operator + (LZespolona  &Skl1);
  LZespolona  operator - (LZespolona  &Skl1);
  LZespolona  operator * (LZespolona  &Skl1); 
  LZespolona  operator / (LZespolona  &Skl1);
  LZespolona  operator / (double t) const;
  friend bool operator != (LZespolona  Skl1,  LZespolona  Skl2);
  friend bool operator == (LZespolona  Skl1,  LZespolona  Skl2);
  friend std::ostream & operator<< (std::ostream & pom , const LZespolona & cos);
  friend std::istream & operator>> (std::istream &pom,  LZespolona & cos);
  LZespolona Sprzezenie();
  double Modul2();
  friend bool compare(LZespolona tmp);
};

//Takie tam

/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */

//Przeciazenia operatorow (+,-,*,/) oraz (!=,==)
// LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
// LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);
// LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2); 
// LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);
// LZespolona  operator / (LZespolona  Skl1,  double t);
// LZespolona Sprzezenie(LZespolona &Skl2);
// double Modul2(LZespolona Skl2);
// bool operator != (LZespolona  Skl1,  LZespolona  Skl2);
// bool operator == (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona Wczytaj();
// bool compare(LZespolona tmp);
//Przeciazenia operatorow przesuniec bitowych w prawo i lewo pozwalajace wyswietlic liczbe zespolona 
//Oraz pozwalajace wczytac z klawiatury liczbe zespolona 
// std::ostream & operator<< (std::ostream & pom , const LZespolona & cos);
// std::istream & operator>> (std::istream &pom,  LZespolona & cos);


double arg(LZespolona z);
LZespolona operator += (LZespolona &Arg1, LZespolona const &Arg2);
LZespolona operator /=(LZespolona &Arg1, LZespolona const &Arg2);

#endif
