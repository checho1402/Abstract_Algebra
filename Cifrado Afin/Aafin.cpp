#include "Aafin.h"
#include <iostream>


Afin::Afin()
{
  int A = 0;
  int B = 0;
  generador_claves(&A,&B);
  this->a = A;
  this->b = B;
}
Afin::Afin(int A, int B)
{
  int tam = Alfabeto.length();
  int inversa_A = inversa(A,tam);
  this->a = inversa_A;
  this->b = B;
}
void Afin::generador_claves(int *a,int *b)
{
  int tam = Alfabeto.length();
  srand(time(nullptr));
  *b = 1 + rand() % tam - 1;
  while(mcd(*a,tam)!= 1)
  {
    *a = 1 + rand() % tam -1;
  }
}
int Afin::residuo(int a, int n){
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

int Afin::mcd(int a, int b) {
    if (b == 0) 
      return a;
    else
      return mcd(b, residuo(a,b));
}

int Afin::euclides_extendido(int a, int b, int *x, int *y){
    int r1 = a, r2 = b, s1 = 1, s2 = 0, t1 = 0,t2 = 1;
    int q,r,s,t;
    while(r2 > 0){
        q = r1 / r2;
        // Actualizando r
        r = r1-q*r2;
        r1 = r2;
        r2 = r;
        // Actualizando s
        s = s1-q*s2;
        s1 = s2;
        s2 = s;
        // Actualizando t
        t = t1-q*t2;
        t1 = t2;
        t2 = t;
    }
    *x = s1;
    *y = t1;
    return r1;
}
int Afin::inversa(int A, int tam){
  int X,Y;
  euclides_extendido(A, tam,&X,&Y);
  int inversa = X;

  if(X < 0)
  {
    inversa = residuo(inversa,Alfabeto.length());
  }
  return inversa;
}
string Afin::cifrado(string mensaje)
{
  int tam = mensaje.length();
  string resultado;
  
  for(int i = 0; i < tam ; i++)
  {
    int pos_letra = Alfabeto.find(mensaje[i]);

    int adi_clave = (a*pos_letra) + b;

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

string Afin::descifrado(string mensaje)
{
  int tam = mensaje.length();
  string resultado;
  for(int i = 0; i < tam ; i++)
  {
    int pos_letra = Alfabeto.find(mensaje[i]);
    int adi_clave = pos_letra - b;
    
    if(adi_clave > 0)
    {
      int adi_clave_aux1 = a*adi_clave;
      
      if(adi_clave_aux1 > Alfabeto.length())
      {
        int adi_clave_aux2 = residuo(adi_clave_aux1,Alfabeto.length());
        resultado += Alfabeto[adi_clave_aux2]; 
      }
      else
      {
        resultado += Alfabeto[adi_clave_aux1]; 
      }
    }
    else
    {
      int adi_clave2 = residuo(adi_clave,Alfabeto.length());
      int adi_clave3 =  a*adi_clave2;
        if(adi_clave3 > Alfabeto.length())
        {
          int adi_clave4 = residuo(adi_clave3,Alfabeto.length());
          resultado += Alfabeto[adi_clave4]; 
        }
        else
        {
          resultado += Alfabeto[adi_clave3]; 
        }
    }
  }
  return resultado;
}