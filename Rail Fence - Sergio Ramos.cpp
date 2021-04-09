#include <iostream>
#include <string>
using namespace std;

class Personas{
private:
  int railes = 3;

public:
  int olas;
  int ele_olas =(railes*2)-2;
  string auxiliar11,auxiliar2,auxiliar3;

  string cifrado(string mensaje){
    string auxiliaroficial;
    //Creo strings auxiliares para almacenar la infomacion de las puntas y el centro
    string auxiliar1,auxiliar2,auxiliar3;
    int resto = ele_olas - size(mensaje)%ele_olas;
    //Relleno espacios con '_'
    string mensaje1 = mensaje + string(resto,'_');
    //Para que el numero de olas sea exacto a pesar de ser decimal hago esta operación.
    olas = (double(size(mensaje))+double(ele_olas)-1)/double(ele_olas);
    int cresta = olas,base = olas, rail_central = size(mensaje1)-(cresta + base);
    //Las lineas comentadas forman parte de un intento para hacer el rail fence de mas de 3 railes, hago esas operaciones para los railes centrales 
    //cout << "rail_central:" <<rail_central  << " \n";

    int numrail = railes - 2;
    int elementos = rail_central/numrail;
    //cout << "elementos:" <<elementos  << " \n";
    string centro[rail_central];
    for(int k=0; k<numrail ; k++)
    {
      centro[k].append(elementos,'_');
    }
    //cout << "elementos:" <<centro[0]  << " \n";

    //El cifrado es concatenar el texto cifrado de la cresta, el centro y la base.
    for(int i=0; i<size(mensaje1) ; i+=(olas)-1)
    {
      auxiliar1 += mensaje1[i];
      this->auxiliar11 = auxiliar1;
    }
    for(int i=railes-1; i<size(mensaje1) ; i+=(olas)-1)
    {
      auxiliar3 += mensaje1[i];
    }
    for(int i=1; i<(olas-1)/2 ; i++)
    {
      for(int j=i; j<size(mensaje1) ; j+=(olas-1)/2)
        auxiliar2 += mensaje1[j];
    }
    this->auxiliar11 = auxiliar1;
    auxiliaroficial = auxiliar1+auxiliar2+auxiliar3;

    /*
    for(int i=0; i<numrail ; i++)
    {
      for(int j=0; j<size(mensaje1) ; j+=(olas)-1)
      {
        centro[i] = mensaje1[j];
        //auxiliar +=centro[i][j];
      }
      cout << "elementos:" <<centro[0]  << " \n";
    }
    */
    return auxiliaroficial;
  }

  string decifrado(string mensaje1){
        string auxiliar4,auxiliar5,auxiliar6;
  //Creo denuevo los auxiliares y sus contenidos
    string auxiliarsito;

        auxiliar4.append(mensaje1,0,5);
        auxiliar5.append(mensaje1,5,15);
        auxiliar6.append(mensaje1,15,20);
    //Leo los auxiliares uno por uno, en froma de ola
      for(int i=0;i<size(mensaje1); i++)
      {         
        int j = i;    
        auxiliarsito += auxiliar4[i];     
        auxiliarsito += auxiliar5[j];
        
        auxiliarsito += auxiliar6[i];
        auxiliarsito += auxiliar5[j+1];
        j+=1;
      }

    return auxiliarsito;
  }
};

int main() {
  Personas Emisor;
  Personas Receptor;
    string mensaje = "Cifrado rail fence";

  string mensajecifrado = Emisor.cifrado(mensaje);
  cout << "Mensaje cifrado :  \n";
  cout << mensajecifrado<<"/ \n";
  string mensajeoriginal = Receptor.decifrado(mensajecifrado);
  cout << "Mensaje descifrado :  \n";
  cout << mensajeoriginal<<"/ \n";

}
