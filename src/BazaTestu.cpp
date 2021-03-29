#include <iostream>
#include <cstring>
#include <cassert>
#include "BazaTestu.hh"
#include "Statystyki.hh"
#include <fstream>
#include <sstream>


using namespace std;

/*
 * Tablica, ktora jest widoczna tylko w tym module.
 * Zawiera ona tresc latwego testu.
 */
static WyrazenieZesp  TestLatwy[] =
  { {{2,1}, Op_Dodaj, {1,2}},
    {{1,0}, Op_Odejmij, {0,1}},
    {{3,0}, Op_Mnoz, {0,3}},
    {{4,8}, Op_Dziel, {1,0}},
  };

/*
 * Analogicznie zdefiniuj test "trudne"
 *
 */
static WyrazenieZesp  TestTrudny[] =
  { {{2,1}, Op_Dodaj, {1,2}},
    {{1,0}, Op_Odejmij, {0,1}},
    {{3,0}, Op_Mnoz, {0,3}},
    {{4,8}, Op_Dziel, {1,0}},
  };





/*
 * W bazie testu ustawia wybrany test jako biezacy test i indeks pytania
 * ustawia na pierwsze z nich.
 * Parametry:
 *    wskBazaTestu - wskaznik na zmienna reprezentujaca baze testu,
 *    wskTabTestu  - wskaznik na tablice zawierajaca wyrazenia arytmetyczne
 *                   bedace przedmiotem testu,
 *    IloscElemTab - ilosc pytan w tablicy.
 *   
 * Warunki wstepne:
 *      - Parametr wskBazaTestu nie moze byc pustym wskaznikiem. Musi zawierac adres
 *        zmiennej reprezentujacej baze testu, ktora wczesniej zostal poprawnie
 *        zainicjalizowany poprzez wywolanie funkcji InicjalizujTest.
 *      - Parametr wskTabTestu zawiera wskaznik na istniejaca tablice.
 *      - Parametr IloscPytan zawiera wartosc, ktora nie przekracza ilosci elementow
 *        w tablicy dostepnej poprzez wskTabTestu.
 */
void UstawTest( BazaTestu *wskBazaTestu, WyrazenieZesp *wskTabTestu, unsigned int IloscPytan )
{
  wskBazaTestu->wskTabTestu = wskTabTestu;
  wskBazaTestu->IloscPytan = IloscPytan;
  wskBazaTestu->IndeksPytania = 0;
}
// void UstawTest( BazaTestu *wskBazaTestu, std::string sNazwaTestu, unsigned int IloscPytan )
// {
//   wskBazaTestu->PlikTest.open(sNazwaTestu, std::ifstream::in);
//   wskBazaTestu->IloscPytan = IloscPytan;
//   wskBazaTestu->IndeksPytania = 0;
// }



/*
 * Inicjalizuje test kojarzac zmienna dostepna poprzez wskaznik wskBazaTestu
 * z dana tablica wyrazen, ktora reprezentuje jeden z dwoch dopuszczalnych 
 * testow.
 * Parametry:
 *    wskBazaTestu - wskaznik na zmienna reprezentujaca baze testu.
 *    sNazwaTestu  - wskaznik na napis wybranego typu testu.
 *
 * Warunki wstepne:
 *      - Parametr wskBazaTestu nie moze byc pustym wskaznikiem. Musi zawierac adres
 *        zmiennej reprezentujacej baze testu, ktora wczesniej zostal poprawnie
 *        zainicjalizowany poprzez wywolanie funkcji InicjalizujTest.
 *      - Parametr sNazwaTestu musi wskazywac na jedna z nazw tzn. "latwe" lub "trudne".
 *       
 * Zwraca:
 *       true - gdy operacja sie powiedzie i test zostanie poprawnie
 *              zainicjalizowany,
 *       false - w przypadku przeciwnym.
 */
bool InicjalizujTest( BazaTestu  *wskBazaTestu, const char *sNazwaTestu )
{
  fstream uchwyt;
  if (!strcmp(sNazwaTestu,"latwy")) {
    UstawTest(wskBazaTestu,TestLatwy,sizeof(TestLatwy)/sizeof(WyrazenieZesp));
    return true;
  }
  else if (!strcmp(sNazwaTestu,"trudny")) {
    UstawTest(wskBazaTestu,TestTrudny,sizeof(TestTrudny)/sizeof(WyrazenieZesp));
    return true;
  }
  /*
   * Analogicznie zrob inicjalizacje dla testu trudne
   */

  cerr << "Otwarcie testu '" << sNazwaTestu << "' nie powiodlo sie." << endl;
  return false;
}


/*!
 * Funkcja udostepnia nastepne pytania o ile jest odpowiednia ich ilosc.
 * Parametry:
 *       wskBazaTestu - wskaznik na zmienna reprezentujaca baze testu.
 *       wskWyrazenie - wskaznik na zmienna, do ktorej zostanie wpisane
 *                      kolejne wyrazenie z bazy testu.
 *
 * Warunki wstepne:
 *      - Parametr wskBazaTestu nie moze byc pustym wskaznikiem. Musi zawierac adres
 *        zmiennej reprezentujacej baze testu, ktora wczesniej zostal poprawnie
 *        zainicjalizowany poprzez wywolanie funkcji InicjalizujTest.
 *      - Parametr wskWyrazenie nie moze byc pustym wskaznikiem. Musi wskazywac na
 *        istniejaca zmienna.
 *
 * Zwraca:
 *       true - gdy operacja sie powiedzie i parametrowi *wskWyrazenie zostanie
 *              przypisane nowe wyrazenie zespolone z bazy,
 *       false - w przypadku przeciwnym.
 */
// bool PobierzNastpnePytanie( BazaTestu  *wskBazaTestu, WyrazenieZesp &wskWyrazenie )
// {
//   if (wskBazaTestu->IndeksPytania >= wskBazaTestu->IloscPytan) return false;

//   wskBazaTestu->PlikTest >> wskWyrazenie;
//   ++wskBazaTestu->IndeksPytania;
//   return true;
// }

bool PobierzNastpnePytanie( BazaTestu  *wskBazaTestu, WyrazenieZesp *wskWyrazenie )
{
  if (wskBazaTestu->IndeksPytania >= wskBazaTestu->IloscPytan) return false;

  *wskWyrazenie = wskBazaTestu->wskTabTestu[wskBazaTestu->IndeksPytania];
  ++wskBazaTestu->IndeksPytania;
  return true;
}

string wybortestu(string wybor){
  if(wybor == "latwy"){
    string testl;
    testl = "/home/adam/Programowanie_Obiektowe/zad2-259355/src/latwe.dat";
    return testl;
  }
  else if (wybor == "trudny"){
    string testt;
    testt = "/home/adam/Programowanie_Obiektowe/zad2-259355/src/trudne.dat";
    return testt;
  }
  return 0;
}

void tescik(WyrazenieZesp WyrZ_PytTest, Staty &Test) {
  LZespolona Odp;
  int i=0;
    while (WyrZ_PytTest.Wyn != Odp && i<3){
      cout << "Twoja odpowiedz: ";
      cin >> Odp;
      

      while(cin.fail() && i<3){
        cin.clear();
        cin.ignore(10000, '\n');
        cerr << "Blednie zapisana liczba zespolona" << endl;
        if(i<2){
        cout << "Ponownie wprowadz liczbe zespolona: ";
        cin >> Odp;
        i++;}
        else{
          cout << "Wykorzystales wszystkie szanse " << endl;
          // cout << "Wynik to: " << WyrZ_PytTest.Wyn << endl;
          // Test.neg++;
        }
      }
        if(WyrZ_PytTest.Wyn == Odp){
          cout << "Poprawna odpowiedz" << endl;
          Test.popr +=1;
          }
        else {
          cout << "Nieprawidłowy wynik " << endl;
          cout << "Wynik to: " << WyrZ_PytTest.Wyn << endl;
          Test.neg++;
          i=3;}
    }
  }