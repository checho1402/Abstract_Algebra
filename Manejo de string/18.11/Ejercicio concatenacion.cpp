#include <iostream>
#include <string>
using namespace std;

int main() {
  string cadena1;
  string cadena2;

  cout << "Primer nombre: ";
  getline(cin,cadena1);
  cout << "\nApellido: ";
  getline(cin,cadena2);

  string cadena_concatenada(cadena1 + " " + cadena2);
  cout << "\nEl nombre ingresado: "<<cadena_concatenada<<"\n";
}
