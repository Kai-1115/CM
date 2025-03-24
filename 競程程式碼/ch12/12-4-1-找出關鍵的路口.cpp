#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
deque<int> G[100];
vector<string> name;
vector<string>::iterator it;
int v[100],up[100],ar[100];
int t,cnt; 
void DFS(int p, int i) { 
  v[i] = up[i] = ++t; 
  int child=0,target; 
  bool ap = false;
  for(int a=0;a<G[i].size();a++){
    target=G[i][a];
    if (target != p){
      if (v[target]){               
        up[i] = min(up[i],v[target]);
      } else {
        child++; 
        DFS(i,target);
        up[i] = min(up[i], up[target]); 
        if (up[target] >= v[i]) ap = true;
      }
    }
  }
  if (((i == p)&&(child > 1))||((i!=p)&&(ap==true))){
    ar[i]=1;
    cnt++;  
  } 
}
int getCityIndex(string p){
  it=find(name.begin(),name.end(),p);  
  if (it < name.end()) return it-name.begin();
  else if (it == name.end()){ 
    name.push_back(p);     
    return name.size()-1;   
  } 
}
int main(){
  string x,y;
  int a,b,n,m;
  while (cin >> n >> m){
    t=0,cnt=0;
    name.clear();
    for(int i=0;i<n;i++){
      G[i].clear();             
    }
    for(int i=0;i<m;i++){
      cin >> x >> y;
      a=getCityIndex(x);
      b=getCityIndex(y);      
      G[a].push_back(b);
      G[b].push_back(a);     
    }
    memset(v,0,sizeof(v));  
    memset(ar,0,sizeof(ar));
    memset(up,0,sizeof(up));
    DFS(0,0);
    cout << cnt << endl;
    for(int i=0;i<n;i++){          
      if (ar[i]>0) cout << name[i]<<endl;       
    }    
  }         
}
