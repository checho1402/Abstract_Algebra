#include <iostream>
#include <string>
using namespace std;

int main() {
  string cadena1;

  cout << "Inserte un texto: ";
  getline(cin,cadena1);
  string::reverse_iterator iterador1 = cadena1.rbegin();

  while(iterador1 != cadena1.rend())
  {
    cout << *iterador1;
    iterador1++;
  }
}
