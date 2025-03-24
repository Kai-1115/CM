#include <iostream>
using namespace std;
long long int f(int);
int main(){
  int n;
  long long int ans;
  while(cin >> n){
    ans=f(n);
    cout << ans << endl;
  }
}    
long long int f(int n){
  if (n==1){
    return 1;
  } else{
    return n*f(n-1);
  }
}
