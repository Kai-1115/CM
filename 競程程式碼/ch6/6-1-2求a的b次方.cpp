#include <iostream>
using namespace std;
int f(int,int);
int main(){
  int a,b;
  int ans;
  while(cin >> a >> b){
    a=a%1234;
    ans=f(a,b)%1234;
    cout << ans << endl;
  }
}    
int f(int a,int b){
  if (b==0){
    return 1;
  }else if (b==1){
    return a%1234;
  }else if (b%2==0){
    int tmp=f(a,b/2)%1234;
    return (tmp*tmp)%1234;
  }else {
    return (a*f(a,b-1))%1234;
  }
}
