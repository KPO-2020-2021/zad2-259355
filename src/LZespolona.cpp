#include "LZespolona.hh"
#include <cmath>
#include <iostream>
#include <ctype.h>



/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

/*!
 * Realizuje odjecie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Roznice dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

/*!
 * Realizuje mnożenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Iloczyn dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = (Skl1.re * Skl2.re) + ((-1)*(Skl1.im * Skl2.im));
  Wynik.im = ((Skl1.re * Skl2.im) + (Skl2.re * Skl1.im));
  return Wynik;
}

//Funkcja wykonujaca sprzezenie liczby zespolonej
LZespolona Sprzezenie(LZespolona &Skl2){
  
  Skl2.im *= (-1);
  return Skl2;
}

//Funkcja obliczajaca modul danej liczby zespolonej 
//poniewaz chodzi nam o kwadrat modulu nie pierwiastkujemy go dodatkowo
double Modul2(LZespolona Skl2){
  double modul;

  modul = (pow(Skl2.re, 2) + pow(Skl2.im, 2));

  return modul;
}

/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */

LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;
  LZespolona  temp;
  Sprzezenie(Skl2);

  if(Skl2.im != 0 || Skl2.re != 0){
  temp.re = (Skl1.re * Skl2.re) + ((-1)*(Skl1.im * Skl2.im));
  temp.im = ((Skl1.re * Skl2.im) + (Skl2.re * Skl1.im));
  Wynik.re = temp.re / Modul2(Skl2);
  Wynik.im = temp.im / Modul2(Skl2);}
  else {
    std::cerr << "Dzielenie przez zero" << std::endl;
  }
  return Wynik;
}

//Przeciazenie operatora (!=) ktory porownuje dwie liczby zespolone i zwraca true jesli 
//liczby sa od siebie rozne 
bool operator != (LZespolona  Skl1,  LZespolona  Skl2)
{
  if(Skl1.re != Skl2.re || Skl1.im != Skl2.im)
  return true;
  else {
    return false;
  }
}

//Przeciazenie operatora (==) ktory porownuje dwie liczby zespolone i zwraca true jesli 
//liczby sa takie same 
bool operator == (LZespolona  Skl1,  LZespolona  Skl2)
{
  if(Skl1.re == Skl2.re && Skl1.im == Skl2.im)
  return true;
  else {
    return false;
  }
}

//Przeciazenie operatora przesuniecia bitowego w lewo 
//Ktory pozwala w odpowiedni sposob wyswietlic liczbe zespolona 
//liczba zespolona zostaje wyswietlona wraz ze znakami za pomoca funkcji showpos
std::ostream & operator<< (std::ostream &stream , const LZespolona & cos){
    std::cout << "(" << cos.re << std::showpos << cos.im << "i)" << std::noshowpos;
return stream;
} 

//Funkcja wczytujaca liczbe zespolona z klawiatury
//Funkcja po koleji wczytuje znaki LZespolonej i sprawdza czy czesc urojona ma byc ujemna
//oraz zwraca wczytana liczbe zespolona
LZespolona Wczytaj(){
  LZespolona temp;
  char tmp;
  std::cin >> tmp;
  std::cin >> temp.re;
  std::cin >> tmp;
  std::cin >> temp.im;
  if(tmp == '-'){
    temp.im *= -1;
  }
  std::cin >> tmp;
  std::cin >> tmp;
  return temp;
}

bool compare(LZespolona tmp){
  if(typeid(tmp.re) == typeid(double) && typeid(tmp.im) == typeid(double)){
    return true;
  }
  else {
    return false;
  }
}

//Przeciazenie operatora przesuniecia bitowego w prawo 
//Ktory pozwala na wczytanie z klawiatury liczby zespolonej 
std::istream & operator>> (std::istream &stream,  LZespolona & cos){
    char tmp;
    stream>>tmp;
    if(stream.fail())
      return stream;

    if(tmp != '('){
        stream.setstate(std::ios::failbit);
        return stream;
    }
    stream>>cos.re;
    if(!stream){
    stream.setstate(std::ios::failbit);
      return stream;}

    stream>>cos.im;
    if(!stream){
    stream.setstate(std::ios::failbit);
      return stream;}

    stream>>tmp;
      if(tmp != 'i'){
          stream.setstate(std::ios::failbit);
          return stream;
      }

    stream>>tmp;
      if(tmp != ')'){
            stream.setstate(std::ios::failbit);
            return stream;
        }
    return stream;
}


