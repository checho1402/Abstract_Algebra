#pragma once
#include <iostream>
#include <string>
using namespace std;

class Rot13
{
  private:
    int clave;
  public:
    string Alfabeto;
    Rot13();
    int residuo(int,int);
    string cifrado(string);
    string descifrado(string);

};
