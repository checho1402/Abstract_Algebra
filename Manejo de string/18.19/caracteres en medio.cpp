#include <iostream>
#include <string>
using namespace std;

int main() {
  string cadena1;

  cout << "Inserte un texto: ";
  getline(cin,cadena1);
  //La mitad exacta cuando una longitud es impar se aproxima a un valor superior
  int enmedio = (cadena1.length()+2-1)/2;
  cadena1.insert(enmedio,"******");

  cout << "\nCadena1: "<<cadena1<<"\n";
}
