#include<iostream>
#include<deque>
#include<cstring>
using namespace std;
int main(){
  int indeg[51],n,m,x,y,ansN;
  deque<int> G[51];
  while(cin >> n >> m){
    ansN=0;
    for(int i=0;i<n;i++) G[i].clear(); 
    memset(indeg,0,sizeof(indeg));
    for(int i=0;i<m;i++){
      cin >> x >> y;
      G[x].push_back(y);
      indeg[y]++;
    }
    for(int i=0;i<n;i++){
      if (indeg[i]==0){
        ansN++;
        cout << i << " ";
        for(int j=0;j<G[i].size();j++){ 
          indeg[G[i][j]]--;
        }
      }
      if (ansN==n) break;
      else if (i==(n-1)){ 
        i=0;
      }
    }
    cout << endl;		
  }
}
