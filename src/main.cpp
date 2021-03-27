#include <iostream>
#include "BazaTestu.hh"
#include "Statystyki.hh"
#include <sstream>
#include <limits>
#include <fstream>
#include <stdexcept>


using namespace std;


int main(int argc, char **argv)
{

  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }
  
  //Wybor testu, uzytkownik moze wybrac czy chce wykonac test z pliku tekstowego badz bazy 
  string wybortes;
  cout << "Prosze wybrac rodzaj testu z pliku (wpisz 'plik') badz z bazy (wpisz 'baza')" << endl;
  cin >> wybortes;

  //Odpowiedni wybor testu z pliku badz bazy (latwy czy trudny)
  if(wybortes == "baza"){
  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }
    cout << endl;
    cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
    cout << endl;

    Staty Test;
    WyrazenieZesp   WyrZ_PytTest;
    std::cout << "Prosze pamietac zeby nie dawac spacji miedzy cyfra a znakiem operacji" << endl;
    std::cout << "prosze wpisywac pelna liczbe zespolona np. (0+0i) brak ktorejs z czesci spowoduje blad" << endl << endl;

    while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytTest)) {
      cout << "Podaj wynik operacji: ";
      cout << WyrZ_PytTest << endl;
      WyrZ_PytTest.Wyn = Oblicz(WyrZ_PytTest);
      tescik(WyrZ_PytTest, Test);
      Test.lpyt +=1;
      }
      Wynikkon(Test);
  }
  else if(wybortes == "plik"){
  string wybor;
  wybor = wybortestu(string(argv[1]));
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  Staty Test;
  WyrazenieZesp   WyrZ_PytTest;
  std::cout << "Prosze pamietac zeby nie dawac spacji miedzy cyfra a znakiem operacji" << endl;
  std::cout << "prosze wpisywac pelna liczbe zespolona np. (0+0i) brak ktorejs z czesci spowoduje blad" << endl << endl;
  std::ifstream plik(wybor);
  while (!plik.eof()) {
    //Gdy pojawi sie niespodziewany blad w ktoryms z wyrazen przechwytujemy go dajemy odpowiedni komunikat 
    //I pomijamy bledne pytanie nie konczac dzialania programu 
    try{
      plik >> WyrZ_PytTest;
      cout << "Podaj wynik operacji: ";
      cout << WyrZ_PytTest << endl;
    }
    catch( std::runtime_error &e){
      cerr << "invalid argument: " << e.what() << " idziemy dalej" << endl;
      continue;
    }
    WyrZ_PytTest.Wyn = Oblicz(WyrZ_PytTest);
    tescik(WyrZ_PytTest, Test);
    Test.lpyt +=1;
  }
  Wynikkon(Test);
  }
  else{
    cerr << "Blednie wprowadziles nazwe" << endl;
  }

  cout << endl;
  cout << " Koniec testu." << endl;
  cout << endl;

}

