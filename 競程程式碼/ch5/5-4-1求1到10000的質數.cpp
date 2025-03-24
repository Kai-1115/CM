#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int);
int main(){
  for(int i=2;i<=10000;i=i+1){
    if (isPrime(i)){
      cout << i << endl;
    }         
  } 
}
bool isPrime(int x){
  int j=2;
	bool flag=true; 
  while (j<=sqrt(x)){
    if ((x%j) == 0){
      flag=false;
      break;          
    }
    j=j+1;
  }
  return flag;
}
