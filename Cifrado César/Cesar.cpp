#include "Ccesar.h"
#include <iostream>
using namespace std;

int main() {
  Cesar Emisor(3);
  Cesar Receptor(3);
  string mensaje;

  cout << "Ingrese mensaje: \n";
  getline(cin,mensaje);
  string mensaje_cifrado = Emisor.cifrado(mensaje);
  
    cout << "Mensaje cifrado: "<<mensaje_cifrado<<"\n";
  string mensaje_original = Receptor.descifrado(mensaje_cifrado);
    cout << "Mensaje original: "<<mensaje_original<<"\n";
}
