#ifndef BAZATESTU_HH
#define BAZATESTU_HH

#include "WyrazenieZesp.hh"
#include "Statystyki.hh"
using namespace std;

/*
 * Modeluje pojecie baze testu z zestawem pytan w tablicy
 * oraz informacji o maksymalnej ilosci pytan, jak
 * tez indeksem nastepnego pytania, ktore ma byc pobrane
 * z bazy.
 */
struct BazaTestu {
    WyrazenieZesp *wskTabTestu;
  unsigned int    IloscPytan;    /* Ilosc wszystkich pytan */
  // std::ifstream PlikTest;
  unsigned int    IndeksPytania; /* Numer pytania, ktore ma byc pobrane jako nastepne */
};

void UstawTest( BazaTestu *wskBazaTestu, std::string sNazwaTestu, unsigned int IloscPytan );

/*
 * Inicjalizuje test powiazany z dana nazwa.
 */
bool InicjalizujTest( BazaTestu  *wskBazaTestu, const char*  sNazwaTestu );
/*
 * Udostepnia nastepne pytanie z bazy.
 */
// bool PobierzNastpnePytanie( BazaTestu  *wskBazaTestu,  WyrazenieZesp &wskWyr );
bool PobierzNastpnePytanie( BazaTestu  *wskBazaTestu,  WyrazenieZesp *wskWyr );

// bool PobierzPytaniePlik(WyrazenieZesp *wskWyrazenie);
//Funkcja wybierajaca odpowiednia sciezke do pliku
string wybortestu(string wybor);
//Funkcja wykonujaca test
void tescik(WyrazenieZesp WyrZ_PytTest, Staty &Test);

#endif
