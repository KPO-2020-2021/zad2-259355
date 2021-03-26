#include "Statystyki.hh"

void Wynikkon (Staty zd){

    
    cout << "Ilosc dobrych odpowiedzi: " << zd.popr << endl;
    cout << "Ilosc neagtywnych odpowiedzi: " << zd.neg << endl;
    cout << "Wynik procentowy poprawnych odpowiedzi: " << Procent(zd) << "%" <<endl;

}

double Procent (Staty zd){
    zd.proc =(zd.popr/(zd.lpyt))*100;
    return zd.proc;
}