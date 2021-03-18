#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH

using namespace std;
#include "BazaTestu.hh"

using namespace std;

//Struktura statystyki koncowej 
struct Staty{
    double neg=0;
    double popr=0;
    double lpyt=0;
};

void Wynikkon(Staty zd);

#endif