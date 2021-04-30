#include "Aafin.h"
#include <iostream>
using namespace std;

int main() {
  Afin Emisor;
  Afin Receptor(Emisor.a,Emisor.b);
  string mensaje;

  cout << "Ingrese mensaje: \n";
  getline(cin,mensaje);
  string mensaje_cifrado = Emisor.cifrado(mensaje);
  
    cout << "Mensaje cifrado:"<<mensaje_cifrado<<"/\n";
  string mensaje_original = Receptor.descifrado(mensaje_cifrado);
    cout << "Mensaje original:"<<mensaje_original<<"/\n";
}