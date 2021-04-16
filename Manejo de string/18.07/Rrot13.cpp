#include "Rrot13.h"
#include <iostream>

Rot13::Rot13()
{
  clave = 13;
  Alfabeto = "abcdefghijklmnopqrstuvwxyz";
}

int Rot13::residuo(int a, int n){
  int q,r;
  int division = a/n;
  int residuo =a-(division*n);
  if (a-(division*n)<0){
    if (a<0 && n<0){
      return (a-(division+1)*n);
    }
    return (a-(division-1)*n);
  }
  return residuo;
}

string Rot13::cifrado(string mensaje)
{
  int tam = mensaje.length();
  string resultado;
  
  for(int i = 0; i < tam ; i++)
  {
    int pos_letra = Alfabeto.find(mensaje[i]);
    int adi_clave = pos_letra + clave;

    if(adi_clave < Alfabeto.length())
    {
      resultado += Alfabeto[adi_clave]; 
    }
    else
    {
      int adi_clave2 = residuo(adi_clave,Alfabeto.length());
      resultado += Alfabeto[adi_clave2]; 
    }
  }
  return resultado;
}

string Rot13::descifrado(string mensaje)
{
  int tam = mensaje.length();
  string resultado;
  
  for(int i = 0; i < tam ; i++)
  {
    int pos_letra = Alfabeto.find(mensaje[i]);
    int adi_clave = pos_letra - clave;
    
    if(adi_clave > 0)
    {
      resultado += Alfabeto[adi_clave]; 
    }
    else
    {
      int adi_clave2 = residuo(adi_clave,Alfabeto.length());
      resultado += Alfabeto[adi_clave2]; 
    }
  }
  return resultado;
}
