#pragma once
#include <iostream>
#include <string>
using namespace std;

class Afin
{
  public:
    int a;
    int b;
    string Alfabeto = "abcdefghijklmnopqrstuvwxyz";
    Afin();
    Afin(int, int);
    void generador_claves(int*,int*);
    int residuo(int,int);
    int mcd(int,int);
    int euclides_extendido(int,int,int*,int*);
    int inversa(int,int);
    string cifrado(string);
    string descifrado(string);

};