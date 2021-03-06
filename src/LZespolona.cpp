#include "LZespolona.hh"
#include <cmath>
#include <iostream>
#include <ctype.h>
#include <cmath>
#include <iomanip>
#define MIN_DIFF 0.01



/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator+ (LZespolona  &Skl1)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + this->re;
  Wynik.im = Skl1.im + this->im;
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
LZespolona LZespolona::operator- (LZespolona  &Skl1)
{
  LZespolona  Wynik;

  Wynik.re = this->re - Skl1.re;
  Wynik.im = this->im - Skl1.im;
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
LZespolona LZespolona::operator* (LZespolona  &Skl1)
{
  LZespolona  Wynik;

  Wynik.re = (Skl1.re * this->re) + ((-1)*(Skl1.im * this->im));
  Wynik.im = ((Skl1.re * this->im) + (this->re * Skl1.im));
  return Wynik;
}

//Funkcja wykonujaca sprzezenie liczby zespolonej
LZespolona LZespolona::Sprzezenie(){
  
  this->im *= (-1);
  return *this;
}

//Funkcja obliczajaca modul danej liczby zespolonej 
//poniewaz chodzi nam o kwadrat modulu nie pierwiastkujemy go dodatkowo
double LZespolona::Modul2(){
  double modul;

  modul = (pow(this->re, 2) + pow(this->im, 2));

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



LZespolona LZespolona::operator/ (LZespolona  &Skl2)
{
  LZespolona  wynik;
  
  Skl2.Sprzezenie();

  if(Skl2.im != 0 || Skl2.re != 0){
  wynik = (*this * Skl2) / Skl2.Modul2();}
  else {
    throw 
    std::invalid_argument("Dzielenie przez zero");
  }
  return wynik;
}

LZespolona  LZespolona::operator / (double t) const{
  LZespolona wynik;

  if(t != 0){
  wynik.re = this->re/t;
  wynik.im = this->im/t;
  return wynik;}
  else{
    throw 
    std::invalid_argument("Dzielenie przez zero");
  }
  return *this;
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

  if((abs(Skl1.re - Skl2.re) <= MIN_DIFF) && (abs(Skl1.im - Skl2.im) <= MIN_DIFF))
  return true;
  else {
    return false;
  }
}

//Przeciazenie operatora przesuniecia bitowego w lewo 
//Ktory pozwala w odpowiedni sposob wyswietlic liczbe zespolona 
//liczba zespolona zostaje wyswietlona wraz ze znakami za pomoca funkcji showpos
//Przeciazenie zostalo ulepszone o ukrywanie cyfr roznych od zera 
std::ostream & operator<< (std::ostream &stream , const LZespolona & cos){
    stream << std::setprecision(2);
    if(cos.re == 0 && cos.im != 0){
      stream << "("  << std::fixed << cos.im << "i)" << std::noshowpos;
    }
    else if(cos.im == 0 && cos.re !=0){
      stream << "(" << std::fixed << cos.re << std::showpos << ")" << std::noshowpos;
    }
    else if (cos.im == 0 && cos.re ==0){
      stream << "(" << cos.re << ")";
    }
    else if(cos.im == 1 && cos.re != 0){
      stream << "(" << std::fixed << cos.re << std::showpos << "+i)" << std::noshowpos;
    }
    else if(cos.im == -1 && cos.re != 0){
      stream << "(" << std::fixed << cos.re << std::showpos << "-i)" << std::noshowpos;
    }
    else{
    stream << "(" << std::fixed << cos.re << std::showpos << std::fixed << cos.im << "i)" << std::noshowpos;
    }
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
    if(stream.peek() == 'i'){
      cos.re = 0;
      cos.im = 1;
      stream>>tmp;
      if(!stream){
        stream.setstate(std::ios::failbit);
        return stream;}
      stream>>tmp;
      if(!stream){
        stream.setstate(std::ios::failbit);
        return stream;}
      return stream;
    }
    else if(stream.peek() == '-'){
      stream>>tmp;
      if(stream.peek() == 'i'){
        cos.re = 0;
        cos.im = -1;
        stream>>tmp;
        if(!stream){
          stream.setstate(std::ios::failbit);
            return stream;}
        stream>>tmp;
        if(!stream){
          stream.setstate(std::ios::failbit);
            return stream;}
        return stream;}
    }
    else if(stream.peek() == 'i'){
        cos.re = 0;
        cos.im = 1;
        stream>>tmp;
        if(!stream){
          stream.setstate(std::ios::failbit);
            return stream;}
        stream>>tmp;
        if(!stream){
          stream.setstate(std::ios::failbit);
            return stream;}
        return stream;
    }
    stream>>cos.re;
    if(!stream){
    stream.setstate(std::ios::failbit);
      return stream;}
    if(stream.peek() == ')'){
      cos.im = 0;
      stream>>tmp;
      if(!stream){
        stream.setstate(std::ios::failbit);
        return stream;}
      return stream;
    }
    else if(stream.peek() == 'i'){
      cos.im = cos.re;
      cos.re = 0;
      stream>>tmp;
      if(!stream){
        stream.setstate(std::ios::failbit);
        return stream;}
      stream>>tmp;
        if(!stream){
        stream.setstate(std::ios::failbit);
      return stream;}
      return stream;
      }
      else if(stream.peek() == '-'){
        stream.get();
      if(stream.peek() == 'i'){
        cos.im = -1;
        stream>>tmp;
        if(!stream){
          stream.setstate(std::ios::failbit);
            return stream;}
        stream>>tmp;
        if(!stream){
          stream.setstate(std::ios::failbit);
            return stream;}
        return stream;
      }
      stream.unget();
    }
      else if(stream.peek() == '+'){
          stream.get();
        if(stream.peek() == 'i'){
          cos.im = 1;
          stream>>tmp;
          if(!stream){
            stream.setstate(std::ios::failbit);
              return stream;}
          stream>>tmp;
          if(!stream){
            stream.setstate(std::ios::failbit);
              return stream;}
          return stream;
        }
        stream.unget();
      }

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

double arg(LZespolona z)
{
  double result;
  if(z.re != 0){
    if(z.re > 0){
      result = atan2(z.im,z.re);
      cout << "argument rowny: " << result << endl;
      return result;
    }
    else{
      result = atan2(z.im,z.re) + 3.14;
      cout << "argument rowny: " << result << endl;
      return result;
    }
  }
  else if(z.re == 0){
    if(z.im > 0){
      result = 0.5*3.14;
      cout << "argument rowny: " << result << endl;
      return result;
    }
    else{
      result = -0.5*3.14;
      cout << "argument rowny: " << result << endl;
      return result;
    }
  }
  else if(z.re == 0 && z.im == 0){
    cout << "argument nieokreslony" << endl;
  }
  return 0;
}

LZespolona operator += (LZespolona &Arg1, LZespolona const &Arg2){

    Arg1.re += Arg2.re;
    Arg1.im += Arg2.im;

    return Arg1;
}


LZespolona operator /= (LZespolona &Arg1, LZespolona const &Arg2){

  LZespolona copy;
  copy = Arg2;
  copy.Sprzezenie();
  if(copy.im != 0 && copy.re != 0){
  Arg1 = (Arg1 * copy) / copy.Modul2();
  return Arg1;}
  else{
    throw 
    std::invalid_argument("Dzielenie przez zero");
  }
  return Arg1;
}