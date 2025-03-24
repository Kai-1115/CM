#include <iostream>
using namespace std;
int main(){
  long long int F[50];
  int n;
  F[0]=1;
  F[1]=1;  
  for(int i=2;i<50;i++){                    
    F[i]=F[i-1]+F[i-2];
  }
  while(cin>>n){
    cout<<F[n-1]<<endl;
  }
}
