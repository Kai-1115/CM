#include <iostream>
using namespace std;
int main() {
  int L,R;
  while(cin >> L >> R){
    for(int a=1;a<R/2;a++){
      for(int b=a+1;b<R/2;b++){
        for(int c=b+1;c<R/2;c++){
          if (((a+b+c)>=L)&&((a+b+c)<=R)){
            if (c*c==a*a+b*b) cout <<a<<" "<<b<<" "<<c<<endl;
          }
        }
      }
    }
  }
}
