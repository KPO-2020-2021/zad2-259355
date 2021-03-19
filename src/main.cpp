#include <iostream>
#include "BazaTestu.hh"
#include "Statystyki.hh"

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
  LZespolona Odp;
  int i=0;
  cout << "Prosze pamietac zeby nie dawac spacji miedzy cyfra a znakiem operacji" << endl << endl;
  // WyrazenieZesp temp;
  // cout << "Prosze wprowadzic wyrazenie zespolone: " << endl;
  // WczytajWyrz ();

  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytTest)) {
    i=0;
    // cout << "Podaj wynik operacji: (" << Wyswietl(WyrZ_PytTest.Arg1) << wyswietlSym(WyrZ_PytTest)  << Wyswietl(WyrZ_PytTest.Arg2) << "i)" << endl;
    cout << "Podaj wynik operacji: ";
    // WyswietlWyr(WyrZ_PytTest);
    cout << WyrZ_PytTest << endl;
    WyrZ_PytTest.Wyn = Oblicz(WyrZ_PytTest);
    while (WyrZ_PytTest.Wyn != Odp && i<3){
      cout << "Twoja odpowiedz: ";
      cin >> Odp;
      
      while(cin.fail() && i<3){
        cin.clear();
        cin.ignore(10000, '\n');
        cerr << "Blednie zapisana liczba zespolona" << endl;
        if(i<3){
        cout << "Ponownie wprowadz liczbe zespolona: ";
        cin >> Odp;
        i++;}
        else{
          cout << "Wykorzystales wszystkie szanse " << endl;
          cout << "Wynik to: " << WyrZ_PytTest.Wyn << endl;
          Test.neg++;
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
      //cout << WyrZ_PytTest.Odp << endl;
      Test.lpyt +=1;

      
    }
    Wynikkon(Test);
    

    
    // proc = (Test.popr/(Test.lpyt))*100;
    // cout << "Ilosc dobrych odpowiedzi: " << Test.popr << endl;
    // cout << "Wynik procentowy poprawnych odpowiedzi: " << proc << "%" <<endl;

    

    // cout << WyrZ_PytTest.Wyn << endl;
    
    
    
  
  
  cout << endl;
  cout << " Koniec testu." << endl;
  cout << endl;
  // Statystyka(test);

}
