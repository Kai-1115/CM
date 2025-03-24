#include <iostream>
#include <queue>
#include <cstring>
#include <deque>
#define INF 0x6f6f6f6f 
using namespace std;
struct Edge{
  int from,to;
  int w;
  bool operator<(const Edge &rhs) const{
    return (rhs.w < w);   
  }      
};
deque<Edge> G[1010];
bool v[1010];
int dis[1010];
int main(){
  int n,m,a,b,w,s;
  while(1){
    cin >> n >> m >> s;
    priority_queue <Edge> pq;
    Edge tmp,pqedge;
    for(int i=0;i<n;i++){
      G[i].clear();              
    }
    for(int i=0;i<m;i++){
      cin >> a >> b >> w;
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
    pqedge.from=s;
    pqedge.w=0;
    dis[s]=0;
    pq.push(pqedge); 
    while(!pq.empty()){         
      pqedge=pq.top();
      pq.pop();
      int from=pqedge.from;
      if (!v[from]){ 
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
      if (dis[i]==INF) cout <<"點" << i <<"無法到達" <<endl;
    }
  }           
}
