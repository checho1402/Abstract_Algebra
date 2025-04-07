#include <NTL/ZZ.h>
#include <iostream>
#include <sstream>
using namespace std;
using namespace NTL;
#include <math.h>
#include <sys/time.h>
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::system_clock;

ZZ mod(ZZ a, ZZ b){
	ZZ q= a/b;
	ZZ	r= a- (q*b);
	if(a<ZZ(0)){
		ZZ ar=r;
	    r= b+ar;
	}
	return r;
}

ZZ string_a_int(string conversion){
  istringstream convertido(conversion);
  ZZ entero;
  convertido >> entero;
  return entero;
}
string int_a_string(ZZ conversion)
{
  ostringstream convertido;
  convertido << conversion;
  return convertido.str();
}
ZZ pot(ZZ base, ZZ exponente) {
    if (exponente == 0) return ZZ(1);
    ZZ x = pot(base, exponente/2);
    if (mod(exponente,ZZ(2))==0) return x*x;
    return x*x*base;
}

ZZ newTime()
{
    ZZ x;
    auto millisec_since_epoch = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    x = ZZ(millisec_since_epoch);

    x = string_a_int(int_a_string(x).substr(6,9));

    x = pot(x+5,ZZ(3));
    return x;
}


ZZ middleSquareNumber(ZZ number, ZZ bits) {
   ZZ intervalo_mayor = pot(ZZ(2),bits)-1;
   ZZ intervalo_menor = pot(ZZ(2),bits)/2;

   ZZ sqn = number * number, next_number = number;
   while(next_number < intervalo_mayor)
   {
     int tam1  = int_a_string(next_number).length();
     int t = (tam1 / 2);
     ZZ limite = pot(ZZ(10),conv<ZZ>(t));
      sqn =  next_number / limite;
      next_number = sqn * sqn * sqn;

   }
   next_number = mod(next_number, intervalo_mayor);
   if(next_number < intervalo_menor)
   {
     next_number += intervalo_menor;
   }

   return next_number;
}
int main() {
    int n = 3;
    ZZ key = newTime();
    cout << "key: " << key<< endl;
   for (int i = 1; i < n; i++) {
      key = middleSquareNumber(key, ZZ(2048));
      cout << key << endl<< endl;
   }

}
