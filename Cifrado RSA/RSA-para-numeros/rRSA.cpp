#include "rRSA.h"
#include <iostream>
#include <math.h>
#include <sstream>
using namespace std;

RSA::RSA()
{
  int P = 0;
  int Q = 0;
  generador_claves(&P,&Q);
  this->p = P;
  this->q = Q;
  this->N = p*q;
  this->oN = (p-1)*(q-1);
  clave_publica_e(&e);
  this->d = inversa(e,oN);

}
RSA::RSA(int E, int n)
{
  this->e = E;
  this->N = n;
}
void RSA::clave_publica_e(int *e)
{
  int max = oN;
  srand(time(nullptr));
  while(mcd(*e,max)!= 1)
  {
    *e = 1 + rand() % max -1;
  }
}
bool RSA::primo(int numero) {
  if (numero == 0 || numero == 1 ||numero == 4) return false;
  for (int x = 2; x < numero / 2; x++) {
    // Es primo si no es divisible por esos numeros
    if (numero % x == 0) 
    {
      return false;
    }
  }
  // Si no se cumple la condicion es primo
  return true;
}
void RSA::generador_claves(int *a,int *b)
{
  int tam = 100;
  srand(time(nullptr));
  while(true)
  {
    if(primo(*a) == true && primo(*b) == true && *a != *b)
    {
      break;
    }
    else
    {
    *b = 1 + rand() % tam + 50;
    *a = 1 + rand() % tam + 50;
    }
  }
}

long int RSA::residuo(int a, int n){
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

int RSA::exponenciacion_modular(int m, int e, int N){
    int exponente = 1, ele_cuadrado = 0, acumulador = 0;
    int resultado = 0;

    if(residuo(e,2) == 1)
    {
        ele_cuadrado = pow(m,exponente);
        acumulador += pow(m,exponente);
        resultado = ele_cuadrado;
        e = e/2;
        exponente = exponente * 2;
    }
    else
    {
      ele_cuadrado = pow(m,1);
      e = e/2;
      exponente = exponente * 2;
    }
    while(e != 0){
      if(residuo(e,2) == 1)
      {

        ele_cuadrado = residuo(pow(ele_cuadrado,2),N);
        acumulador += pow(m,exponente);
        resultado = residuo(resultado * ele_cuadrado,N);
        e = e/2;
        exponente = exponente * 2;
      }
      else if(residuo(e,2) == 0)
      {

        ele_cuadrado = residuo(pow(ele_cuadrado,2),N);
        e = e/2;
        exponente = exponente * 2;

      }
    }
    return resultado;
}

int RSA::mcd(int a, int b) {
    if (b == 0) 
      return a;
    else
      return mcd(b, residuo(a,b));
}

int RSA::euclides_extendido(int a, int b, int *x, int *y){
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
int RSA::inversa(int A, int tam){
  int X,Y;
  euclides_extendido(A, tam,&X,&Y);
  int inversa = X;
  if(X < 0)
  {
    inversa = residuo(inversa,oN);
  }
  return inversa;
}

long int RSA::cifrado(int mensaje)
{
  if(mensaje > N)
  {
    cout << "¡Advertencia! El mensaje ingresado supera los limites de N(p*q) por lo que se complicara el descifrado, ingresa un mensaje que este dentro de los limites de N\n";
    cout << "Ingrese mensaje: \n";
    cin>>mensaje;
  }
    cout << "La clave pública es: (" << e << " , "<<N<<")"<<"\n";
  long int resultado = exponenciacion_modular(mensaje, e, N);
  return resultado;
}

long int RSA::descifrado(int mensaje)
{ 
  cout << "La clave privada es: (" << d << " , "<<N<<")"<<"\n";
  long int resultado = exponenciacion_modular(mensaje, d, N);
  return resultado;
}