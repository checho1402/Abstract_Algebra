#include <iostream>
using namespace std;

int residuo(int a, int n){
  int q,r;
  int division = a/n;
  int residuo =a-(division*n);
  if (a-(division*n)<0){
    if (a<0 && n<0){
      return (a-(division+1)*n);
    }
    return (a-(division-1)*n);
  }
  return residuo;
}


string descifrado(string mensaje, string Alfabeto, int clave)
{
  int tam = mensaje.length();
  string resultado;
  
  for(int i = 0; i < tam ; i++)
  {
    int pos_letra = Alfabeto.find(mensaje[i]);
    int adi_clave = pos_letra - clave;
    
    if(adi_clave > 0)
    {
      resultado += Alfabeto[adi_clave]; 
    }
    else
    {
      int adi_clave2 = residuo(adi_clave,Alfabeto.length());
      resultado += Alfabeto[adi_clave2]; 
    }
  }
  return resultado;
}


string criptoanalisis(string mensaje)
{
  string frecuencias = "aeroinctlsdmupbghfvzjqyxkw";
  string Alfabeto_espanol = "abcdefghijklmnopqrstuvwxyz";
  string Alfabeto = "abcdefghijklmnñopqrstuvwxyz";
  int tam = mensaje.length();
  string resultado;
  int posicion = Alfabeto.find_first_not_of(mensaje);
  while(posicion != string::npos)
  {
    Alfabeto.replace(posicion,1,".");
    posicion = Alfabeto.find_first_not_of( mensaje, posicion + 1 );
  }

  int posicion2 = Alfabeto.find_first_of(".");
  while(posicion2 != string::npos)
  {
    Alfabeto.erase(posicion2,1);
    posicion2 = Alfabeto.find_first_of( ".", posicion + 1 );
  }
    int mayor_num=1;
    string mayor_letra;
  for(int i = 0; i<Alfabeto.length();i++)
  { 
        int contador = 0;
          string letra;
          for(int j=0; j<mensaje.length(); j++){
            if(mensaje[j] == Alfabeto[i]){
              contador++;
              letra = mensaje[j];
            }
          }
            if(contador>mayor_num)
            {
              mayor_letra = letra;
              mayor_num = contador;
            }
  }
    cout << "La letra que mas se repite en el mensaje es... \n";
        cout << "letra: "<<mayor_letra<<"\n";
    cout << "Numero de repeticiones: "<<mayor_num<<"\n";
    cout << "Analizaremos a partir de esta letra \n";
  int posicion3 = Alfabeto_espanol.find_first_of(mayor_letra);
  for(int k=0; k<Alfabeto_espanol.length();k++)
  {
    int posicion4 = Alfabeto_espanol.find_first_of(frecuencias[k]);
    int clave= posicion3 - posicion4; 
    if(clave < 0)
    {

      clave = posicion3 + (Alfabeto_espanol.length()-posicion4);
    }
    string mensajito = descifrado(mensaje, Alfabeto_espanol, clave);
    bool continuar = true;
    string encontrado;
    if(continuar == true)
    {
      cout << "\nClave: "<<clave<< " \nMensaje: "<<mensajito<<"\n";
      cout << "¿Crees que este es el mensaje original? (si/no): ";
      cin >> encontrado;
      if(encontrado == "si")
      {
        resultado = mensajito;
        break;
      }
    }
  }
  return resultado;
}
int main() {
  string mensaje = "krodfrprhvwdv";

  string mensaje_original = criptoanalisis(mensaje);
  cout << "\nCriptoanálisis exitoso\n";
    cout << "Mensaje original: "<<mensaje_original<<"\n";
}
