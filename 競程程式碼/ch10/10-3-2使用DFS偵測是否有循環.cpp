#include <iostream>
#include <deque>
using namespace std;
deque<int> G[27];
int V[27];
bool isLoop;
void DFS(int,int);
int main(){
  int n,x,y;
  char a,b;
  while (cin >> n){
    isLoop=false;
    for(int i=0;i<26;i++){
      G[i].clear();        
      V[i]=0;      
    }
    for(int i=0;i<n;i++){
      cin >> a >> b;
      x=a-'A';
      y=b-'A';             
      G[x].push_back(y);     
    }     
    for(int i=0;i<26;i++){        
      if (G[i].size()>0) DFS(i,i);
      if (isLoop) break;      
    }
    if (isLoop) cout <<"形成循環"<<endl;
    else cout << "沒有形成循環" << endl;            
  }     
}
void DFS(int x,int start){
  if (isLoop) return;
  int target;
  for(int i=0;i<G[x].size();i++){
    target=G[x][i];
    if (target == start) { 
      isLoop=true;        
      return;
    }
    if (V[target] == 1) continue;        
    V[target]=1;
    DFS(target,start);
    V[target]=0;      
  }       
}
