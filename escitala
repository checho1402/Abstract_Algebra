#include <iostream>
#include <string>
using namespace std;
class Personas{
  private:

    int filas = 3;
    int columnas = 6;

  public:

  string cifrado(string mensaje){
  string auxiliar;
  for(int i=0; i<columnas ; i++)
    {
    for(int j=i; j<size(mensaje) ; j+=6)
    {
       auxiliar += mensaje[j];
    }
    }
  return auxiliar;
  }

  string decifrado(string mensaje){
  string auxiliar;
  for(int i=0; i<filas ; i++)
    {
    for(int j=i; j<size(mensaje) ; j+=3)
    {
       auxiliar += mensaje[j];
    }
    }
  return auxiliar;
  }
};

int main() {

  Personas Emisor;
  Personas Receptor;

  string mensaje = "Hola como estan   ";
  string mensajecifrado = Emisor.cifrado(mensaje);
  cout << mensajecifrado<<"/ \n";
  string mensajeoriginal = Receptor.decifrado(mensajecifrado);

  cout << mensajeoriginal<<"/ \n";
}
