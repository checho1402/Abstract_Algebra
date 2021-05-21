#include "rRSA.h"
#include <iostream>
using namespace std;

int main() {
  RSA Receptor;
  RSA Emisor(Receptor.e,Receptor.N);
  //Este es el método para cifrar numeros
  
  int mensaje;

  cout << "Ingrese mensaje: \n";
  cin>>mensaje;
  int mensaje_cifrado = Emisor.cifrado(mensaje);
  
    cout << "Mensaje cifrado:"<<mensaje_cifrado<<"/\n";
  int mensaje_original = Receptor.descifrado(mensaje_cifrado);
    cout << "Mensaje original:"<<mensaje_original<<"/\n";

}