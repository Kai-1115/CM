#include <iostream>
#include <queue>
#include <cstring>
#include <deque>
#include <string>
#include <map>
using namespace std;
map<string,int> nmap;
struct Edge{
  int from,to;
  int w;
  bool operator<(const Edge &rhs) const{
    return (rhs.w < w);     
  }      
};
deque<Edge> G[100];
bool v[100];
int dis[100];
int getCityIndex(string p){
  if (nmap.find(p)==nmap.end()){
    int s=nmap.size();
    nmap[p]=s;
  }
  return nmap[p];
}
int main(){
  int n,m,a,b,w,s;
  string x,y;
  priority_queue<Edge> pq;
  Edge tmp,pqedge; 
  cin >> n >> m;
  for(int i=0;i<n;i++){
    G[i].clear();              
  }
  for(int i=0;i<m;i++){
    cin >> x >> y >> w;
    a=getCityIndex(x);
    b=getCityIndex(y);
    tmp.from=a;
    tmp.to=b;
    tmp.w=w;     
    G[a].push_back(tmp);
    tmp.from=b;
    tmp.to=a;
    tmp.w=w;     
    G[b].push_back(tmp);    
  }
  memset(v,0,sizeof(v));
  memset(dis,0x6f,sizeof(dis));
  cin >> x;
  s=getCityIndex(x);
  pqedge.from=s;
  pqedge.w=0;
  dis[s]=0;
  pq.push(pqedge); 
  while(!pq.empty()){         
    pqedge=pq.top();
    pq.pop();
    int from=pqedge.from;
    if (v[from]==0) {
      v[from]=1;
      for(int i=0;i<G[from].size();i++){
        if (v[G[from][i].to]==0){
          if (dis[G[from][i].to]>dis[from]+G[from][i].w) {
            dis[G[from][i].to]=dis[from]+G[from][i].w; 
            tmp.from=G[from][i].to;
            tmp.w=dis[G[from][i].to];
            pq.push(tmp);                                                    
          }  
        }                
      }
    }     
  }
  for(int i=0;i<n;i++){
    cout << dis[i]<<" ";
  } 
  cout << endl;           
}
