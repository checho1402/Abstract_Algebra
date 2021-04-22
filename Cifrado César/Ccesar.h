#pragma once
#include <iostream>
#include <string>
using namespace std;

class Cesar
{
  private:
    int clave;
  public:
    string Alfabeto;
    Cesar(int);
    int residuo(int,int);
    string cifrado(string);
    string descifrado(string);

};
