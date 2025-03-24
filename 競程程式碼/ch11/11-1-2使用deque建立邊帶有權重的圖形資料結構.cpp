#include <iostream>
#include <deque>
using namespace std;
struct Edge{
  int from;
  int to;
  int w;
};
deque<Edge>  G[100];
int main(){
  int n,a,b,w;
  Edge tmp;
  cin >> n;
  for(int i=0;i<n;i++){
    G[i].clear();              
  }
  for(int i=0;i<n;i++){
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
}
