#include <iostream>
#include <deque>
#include <string>
#include <cstring>
#include <map>
using namespace std;
deque<int> G[210];
int V[210];
int md;
map<string,int> nmap;
int getCityIndex(string);
void DFS(int,int);
int main(){
  string x,y,start;
  int a,b,n,m,startv;
  while(cin >> n){
    md=0;
    nmap.clear(); 
    for(int i=0;i<n;i++){
      G[i].clear();        
      V[i]=0;      
    }
    cin >> m;
    for(int i=0;i<m;i++){
      cin >> x >> y;
      a=getCityIndex(x);
      b=getCityIndex(y);      
      G[a].push_back(b);
      G[b].push_back(a);     
    }
    cin >> start;
    startv=getCityIndex(start);
    memset(V,0,sizeof(V)); 
    V[startv]=1;            
    DFS(startv,0);       
    cout << md <<endl;
  }          
}
int getCityIndex(string p){
  if (nmap.find(p)==nmap.end()){
    int s=nmap.size();
    nmap[p]=s;
  }
  return nmap[p];
} 
void DFS(int x,int level){
  int target;
  for(int i=0;i<G[x].size();i++){
    if (level>md) md=level;
    target=G[x][i];
    if (V[target] == 1) continue;        
    V[target]=1;
    DFS(target,level+1);           
  }       
}
