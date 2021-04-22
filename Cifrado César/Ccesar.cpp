#include "Ccesar.h"
#include <iostream>

Cesar::Cesar(int clave1)
{
  this->clave = clave1;
  Alfabeto = "abcdefghijklmnopqrstuvwxyz ";
}
int Cesar::residuo(int a, int n){
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

string Cesar::cifrado(string mensaje)
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

string Cesar::descifrado(string mensaje)
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
