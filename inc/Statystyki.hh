#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH

using namespace std;
#include <iostream>

//Struktura statystyki koncowej 
struct Staty{
    double neg;
    double popr;
    double lpyt;
    double proc;
};

double Procent(Staty zd);
void Wynikkon(Staty zd);

#endif