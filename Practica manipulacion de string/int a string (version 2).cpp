#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
  long int cadena1 = 548365842358;
  ostringstream cadena2;

  cadena2 << cadena1;
  cout << "\nEl numero es (string): "<<cadena2.str()<<"\n";
}
