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
bool inqu[100];
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
  queue<Edge> qu;
  Edge tmp,quedge; 
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
  }
  memset(inqu,0,sizeof(inqu));
  memset(dis,0x6f,sizeof(dis));
  cin >> x;
  s=getCityIndex(x);
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
        dis[G[from][i].to]=dis[from]+G[from][i].w; 
        if (inqu[G[from][i].to]==0){
          tmp.from=G[from][i].to;
          qu.push(tmp);
          inqu[tmp.from]=1;          
        }                                                                                                                                                                                                                                                                      
      }                                                   
    }                
  }     
  for(int i=0;i<n;i++){
    cout << dis[i]<<" ";
  } 
  cout << endl;           
}
