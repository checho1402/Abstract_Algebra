#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
  string cadena1 = "548365842358";
  istringstream cadena2(cadena1);
  long int entero;

  cadena2>>entero;
  cout << "\nEl numero es (int): "<<entero<<"\n";
}
