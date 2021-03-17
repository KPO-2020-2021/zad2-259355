#include "Statystyki.hh"

void Wynikkon (Staty zd){

    double proc;
    proc = (zd.popr/(zd.lpyt))*100;
    cout << "Ilosc dobrych odpowiedzi: " << zd.popr << endl;
    cout << "Ilosc neagtywnych odpowiedzi: " << zd.neg << endl;
    cout << "Wynik procentowy poprawnych odpowiedzi: " << proc << "%" <<endl;

}