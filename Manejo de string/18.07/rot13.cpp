#include "Rrot13.h"
#include <iostream>
using namespace std;

int main() {
  Rot13 Emisor;
  Rot13 Receptor;
  string mensaje;

  cout << "Ingrese mensaje: \n";
  getline(cin,mensaje);
  string mensaje_cifrado = Emisor.cifrado(mensaje);
  
    cout << "Mensaje cifrado: "<<mensaje_cifrado<<"\n";
  string mensaje_original = Receptor.descifrado(mensaje_cifrado);
    cout << "Mensaje original: "<<mensaje_original<<"\n";
}
