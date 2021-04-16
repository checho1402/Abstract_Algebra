#include <iostream>
using namespace std;

#include <iomanip>
using std::setw;

// prototipos
void ordenamientoSeleccion( string [], const int, bool (*)( string, string ) );
void intercambiar( int * const, int * const );
bool ascendente( string, string); // implementa el orden ascendente
bool descendente( string, string ); // implementa el orden descendente
int main()
{
const int tamanioArreglo = 10;
int orden; // 1 = ascendente, 2 = descendente
int contador; // subíndice del arreglo
string a[ tamanioArreglo ] = { "a", "b", "d", "c", "f", "g", "i", "j", "h", "k" };

cout << "Escriba 1 para orden ascendente,\n" << "Escriba 2 para orden descendente: ";
cin >> orden;
cout << "\nElementos de datos en el orden original\n";
// imprime el arreglo original
for ( contador = 0; contador < tamanioArreglo; contador++ )
cout << setw( 4 ) << a[ contador ];

// ordena el arreglo en forma ascendente; pasa la función ascendente
// como un argumento para especificar el orden ascendente

if ( orden == 1 )
{
ordenamientoSeleccion( a, tamanioArreglo, ascendente );
cout << "\nElementos de datos en orden ascendente\n";
} // fin de if

// ordena el arreglo en forma descendente; pasa la función descendente
// como argumento para especificar el orden en forma descendente
else
{
ordenamientoSeleccion( a, tamanioArreglo, descendente );
cout << "\nElementos de datos en orden descendente\n";
} // fin de la parte del if...else correspondiente al else

// imprime el arreglo ordenado
for ( contador = 0; contador < tamanioArreglo; contador++ )
 cout << setw( 4 ) << a[ contador ];

cout << endl;
return 0; // indica que terminó correctamente
} // fin de main

 // ordenamiento por selección multipropósito; el parámetro compara es
 // un apuntador a la función de comparación que determina el tipo de orden
void ordenamientoSeleccion( string trabajo[], const int tamanio,
bool (*compara)( string, string ) )
{
int menorOMayor; // índice del elemento más pequeño (o grande)

// itera a través de tamanio - 1 elements
for ( int i = 0; i < tamanio - 1; i++ )
{
menorOMayor = i; // primer índice para el vector remanente

// itera para encontrar el índice del elemento más pequeño (o más grande)
for ( int index = i + 1; index < tamanio; index++ )
if ( !(*compara)( trabajo[ menorOMayor ], trabajo[ index ] ) )
menorOMayor = index;
trabajo[menorOMayor].swap(trabajo[i]);
} // fin de if
} // fin de la función ordenamientoSeleccion


// determina si el elemento a es menor que
// el elemento b para un orden ascendente
bool ascendente( string a, string b )
{
return a < b; // devuelve true si a es menor que b
} // fin de la función ascendente

// determina si el elemento a es mayor que
// el elemento b para un orden descendente
bool descendente( string a, string b )
{
return a > b; // devuelve true si a es mayor que b
} // fin de la función descendente
