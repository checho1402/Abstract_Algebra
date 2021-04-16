#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
  string cadena1 = "Yo,como un pan;Además.Uso(signos)de-puntuacion:osi!osi¿punto";

  int posicion = cadena1.find_first_of(",;.()-:!¿");
  while( posicion != string::npos)
  {
    cadena1.replace(posicion,1," ");
    posicion = cadena1.find_first_of(",;.()-:!¿",posicion+1);
  }

  cout << "\nCadena1: "<<cadena1<<"\n\n";
  char * cstrcadena1 = new char [cadena1.length()+1];
  strcpy (cstrcadena1, cadena1.c_str());
  char * p = strtok (cstrcadena1," ");
  while (p!=0)
  {
    cout << p << '\n';
    p = strtok(NULL," ");
  }
  delete[] cstrcadena1;
}
