#include <iostream>
#include <string>
using namespace std;

void hombresito(int partes){
  switch(partes)
  {
    case 1:
      cout << "\t 0 \n";
      cout << "\t\n";
      cout << "\t\n";
      cout << "\t\n";
    break;
    case 2:
      cout << "\t 0 \n";
      cout << "\t/\n";
      cout << "\t\n";
      cout << "\t\n";
    break;
    case 3:
      cout << "\t 0 \n";
      cout << "\t/|\n";
      cout << "\t\n";
      cout << "\t\n";
    break;
    case 4:
      cout << "\t 0 \n";
      cout << "\t/|\\ \n";
      cout << "\t\n";
      cout << "\t\n";
    break;
    case 5:
      cout << "\t 0 \n";
      cout << "\t/|\\ \n";
      cout << "\t | \n";
      cout << "\t\n";
    break;
    case 6:
      cout << "\t 0 \n";
      cout << "\t/|\\ \n";
      cout << "\t | \n";
      cout << "\t/ \n";
    break;
    case 7:
      cout << "\t 0 \n";
      cout << "\t/|\\ \n";
      cout << "\t | \n";
      cout << "\t/ \\ \n";
    break;
  }
}
int main() {

  string palabra = "lapiz";
  int tam = palabra.length();
  string palabrax;
  palabrax.append(tam,'x'); 
  cout << "\nAdivine la palabra: "<< palabrax << "\n";
  int perdio = 0;
  int intentos = 0;
  while(perdio != 7)
  {
    char letra;
    int ubicacion;
    cout << "Ingrese una letra: ";
    cin >> letra;

    if((ubicacion = palabra.find(letra)) != string::npos)
    {
      cout << "\n(Si) Encontraste una letra: ";
      palabrax[ubicacion] = palabra[ubicacion];
      cout << palabrax << "\n";
      intentos ++;
      cout << "\nNumero de intentos: "<<intentos<<"\n";
      if(palabra == palabrax)
      {
        string continuar;
        cout << "\nFelicidades!!! Adivino mi palabra. Desea jugar otra vez? si/no \n"; 
        cin >> continuar;
        if(continuar == "si")
        {
          palabrax = "xxxxx";
          intentos = 0;
          perdio = 0;
          cout << "\n\n ////   NUEVO JUEGO   //// \n"; 
        }
        else
        {
          break;
        }
      }
    }
    else
    {
      cout << "\n(No) Fallaste no hay esa letra\n";
      perdio++;
      hombresito(perdio);
      intentos ++;
      cout << "\nNumero de intentos: "<<intentos<<"\n";
    }
  }
}
