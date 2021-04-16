#include <iostream>
#include <string>
#include <cstring>
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
  while (p!=0)
  {

    cout << p << '\n';
    p = strtok(NULL,"_");
  }
  int cstr_tam = sizeof(cstrcadena1) ;

  string cadena_oficial = convertirstring(cstrcadena1, cstr_tam);;
    cout << "\nCadena_oficial: "<<cadena_oficial<<"\n\n";
  int posicion = cadena_oficial.find_first_of("_");
  while( posicion != string::npos)
  {
    cadena_oficial.replace(posicion,1,"*");
    posicion = cadena_oficial.find_first_of("*",posicion+1);
  }
  delete[] cstrcadena1;
    cout << "\nCadena_oficial: "<<cadena_oficial<<"\n\n";
}

