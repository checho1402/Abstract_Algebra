#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
using namespace std;
string convertirstring(char* a, int tam)
{
    int i;
    string s;
    for (i = 0; i < tam; i++) {
        s += a[i];
    }
    return s;
}
int main() {
  string cadena1;
  int caracteres;
  cout << "Ingrese el texto: ";
  getline(cin,cadena1);

  cout << "Ingrese el número de caracteres: ";
  cin >>caracteres;

  cout << "\nCadena1: "<<cadena1<<"\n\n";
  for(int i = 4; i < cadena1.length();i+=caracteres+1)
  {
    cadena1.insert(i,"_");
  }
  cadena1.insert(cadena1.length(),"XXX");
  char * cstrcadena1 = new char [cadena1.length()+1];
  strcpy (cstrcadena1, cadena1.c_str());

  char * p = strtok (cstrcadena1,"_");
  ostringstream cadenasalida;
  string vector[15];
  int i=0;
  while (p!=0)
  {
    vector[i] = p;
    string pp = "*";
    cadenasalida << p + pp;
    cout << p << '\n';
    p = strtok(NULL,"_");
    i++;
  }
  string cadena_oficial = cadenasalida.str();
    cout << "\nCadena_salida: "<<cadena_oficial<<"\n\n";

  delete[] cstrcadena1;
  for(int i = 0; i < 15; i++)
  {
    cout << "\nVector: "<<vector[i];
  }
