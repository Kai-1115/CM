#include <iostream>
#include <cstring>
using namespace std;
int G[100][100];
int main(void){
  int n,a,b,w;
  memset(G,0,sizeof(G));
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> a >> b >> w;
    G[a][b]=w;
    G[b][a]=w;
  }
}
