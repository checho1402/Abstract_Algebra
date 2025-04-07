#include <iostream>
using namespace std;
#include <algorithm> 
int main() {
  int A[10];
  for(int i=0 ; i < 10 ; i++)
  {
    A[i] = rand() % (50 -1);
  }

  int U = sizeof(A) / sizeof(A[0]);
  cout <<U-1<< "\n";
  int *p = A;
  int *q = A+(U-1);
  int flag_swap = 1;
    for(int i=0; i<U;i++){
      cout <<A[i]<< "\t";
    }
  while(flag_swap == 1)
  {
    flag_swap = 0;
    if(p == q)
    {
      break;
    }
    for(int *t = p; t<q ; t++)
    {
      if(*t > *(t+1))
      {
        swap(*(t),*(t+1));
        flag_swap = 1;
      }
    }

    flag_swap = 0;
    q--;
    cout << "\n \n";
    for(int i=0; i<U;i++){
       cout <<A[i]<< "\t";
    }
    for(int *t = q; t>p ; t--)
    {
      if(*t < *(t-1))
      {
        swap(*(t),*(t-1));
        flag_swap = 1;
      }
    }
    p++;
  }
  cout << "\nRespuesta/----------------------------/ \n";
  for(int i=0; i<U;i++){
      cout <<A[i]<< "\t";
  }
}