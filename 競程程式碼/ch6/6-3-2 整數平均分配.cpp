#include <iostream>
#include <algorithm>
using namespace std;
int candy[1010];
int n,m;
bool bs(int x){ 
  int cnt=0;
  for(int i=0;i<n;i++){
    cnt+=(int)(candy[i]/x);
  }
  return (cnt >= m);
}
int main(){
  int mc,L,R,M;
  while(cin >> n){
    mc=0;
    for(int i=0;i<n;i++) {
      cin >> candy[i];
      mc=max(mc,candy[i]);
    }
    cin >> m;
    L=0;
    R=mc;
    while(L<R){ 
      M=(L+R)/2;
      if(bs(M)) {
      	if (bs(M+1)) L=M+1;
      	else {
      	  L=M;  //M´N¬O¸Ñµª 
		  break;	
		}
	  }
      else R=M-1;
    }
    cout << L <<endl;
  }
} 
