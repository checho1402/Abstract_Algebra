#pragma once
#include <iostream>
#include <string>
using namespace std;

class RSA
{ private:
    int d;
    int p;
    int q;
    int oN;
  public:
    int N;
    int e;
    string Alfabeto = "abcdefghijklmnopqrstuvwxyz";
    RSA();
    RSA(int, int);
    bool primo(int);
    void generador_claves(int*,int*);
    void clave_publica_e(int*);
    long int residuo(int,int);
    int exponenciacion_modular(int,int,int);
    int mcd(int,int);
    int euclides_extendido(int,int,int*,int*);
    int inversa(int,int);
    long int cifrado(int);
    long int descifrado(int);

};