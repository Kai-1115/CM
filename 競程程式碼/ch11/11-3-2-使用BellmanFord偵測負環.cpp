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
};
deque<Edge> G[100];
int n,m;
int getCityIndex(string p){
  if (nmap.find(p)==nmap.end()){
    int s=nmap.size();
    nmap[p]=s;
  }
  return nmap[p];
}
bool BellmanFord(int s){
  queue<Edge> qu;
  Edge tmp,quedge;
  bool inqu[100];
  int dis[100],cnt[100];
  memset(inqu,0,sizeof(inqu));
  memset(cnt,0,sizeof(cnt));
  memset(dis,0x6f,sizeof(dis));
  quedge.from=s;
  dis[s]=0;
  inqu[s]=1;
  qu.push(quedge); 
  while(!qu.empty()){         
    quedge=qu.front();
    qu.pop();
    int from=quedge.from;
    inqu[from]=0;
    for(int i=0;i<G[from].size();i++){
      if (dis[G[from][i].to]>dis[from]+G[from][i].w) {
        cnt[G[from][i].to]++;
        if (cnt[G[from][i].to]>=n){
          return true;
        }
        dis[G[from][i].to]=dis[from]+G[from][i].w; 
        if (inqu[G[from][i].to]==0){
          tmp.from=G[from][i].to;
          qu.push(tmp);
          inqu[tmp.from]=1;          
        }  
      } 
    }                
  }
  return false;    
}
int main(){
  int a,b,w,s;
  string x,y;
  bool ans;
  Edge tmp;
  while(cin >> n >> m){
    ans=false;
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
    }
    for(int i=0;i<n;i++){
      if (G[i].size()>0) {
        ans=BellmanFord(i);
        if (ans) break; 
      }     
    }
    if (ans) cout <<"找到負環"<<endl;
    else cout <<"找不到負環"<<endl;       
  }           
}
