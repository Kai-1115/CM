#include <iostream>
#include <cstring>
using namespace std;
int main(){
  int x,n,v[10],m[50001],p[50001];
  while(cin >> n){
    for(int i=0;i<n;i++) cin >> v[i];
    cin >> x;
    memset(m,0x6f,sizeof(m));
    m[0]=0;
    memset(p,0,sizeof(p));
    for(int i=0;i<n;i++){
      for(int j=v[i];j<=x;j++){        
        if (m[j] > m[j-v[i]]+1){
          m[j]=m[j-v[i]]+1;
          p[j]=v[i]; 
        }    
      }      
    }
    cout<<m[x]<<endl;
    int k=x;
    while(k>0){
      cout << p[k] << " ";
      k=k-p[k];
    }
    cout << endl;    
  }
}
