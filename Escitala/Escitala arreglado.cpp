#include <iostream>
#include <string>
using namespace std;
class Personas{
  private:

    int filas = 4;
    int columnas = 11;

  public:

  string cifrado(string mensaje){
    //Si el mensaje original supera los límites de la clave, es decir(flias*columnas) entonces el algoritmo no funcionará, por lo que se solicita cambiar la clave por numeros superiores.
    if(mensaje.size() > filas*columnas){
      cout << "El mensaje supera los límites de la clave, si quiere proceder aumente los valores de la clave \n";
    //El exit es para interrumpir el programa
    exit(0);
    }
    // Un string auxiliar donde se guarde el mensaje cifrado
  string auxiliar;
  //Para que el algoritmo funcione correctamente se debe concatenar espacios en blanco '_' que completaran el mensaje hasta encajar con las dimensiones de (filas*columnas) para que el algoritmo funcione bien
  //Se utiliza un constructor para determinar los espacios que seran rellenados por '_'
  string mensaje1 = mensaje + string(filas*columnas - mensaje.size(),'_');

  //Recorro el string y lo leo para abajo en columnas
  for(int i=0; i<columnas ; i++)
    {
    for(int j=i; j<size(mensaje1) ; j+=columnas)
    {
       auxiliar += mensaje1[j];
    }
    }
  return auxiliar;
  }

  string decifrado(string mensaje){
    if(mensaje.size() > filas*columnas){
      cout << "El mensaje supera los límites de la clave, si quiere proceder aumente los valores de la clave \n";
    exit(0);
    }
  string auxiliar;
  for(int i=0; i<filas ; i++)
    {
    for(int j=i; j<size(mensaje) ; j+=filas)
    {
       auxiliar += mensaje[j];
    }
    }
  return auxiliar;
  }
};
int main() {
  //Creo los objetos Emisor y receptor
  Personas Emisor;
  Personas Receptor;
    string mensaje = "Trabaja por lo que verdaderamente amas";

  string mensajecifrado = Emisor.cifrado(mensaje);
  cout << mensajecifrado<<"/ \n";
  string mensajeoriginal = Receptor.decifrado(mensajecifrado);

  cout << mensajeoriginal<<"/ \n";
}
