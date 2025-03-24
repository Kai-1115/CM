#include <iostream>
#include <deque>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> name;
vector<string>::iterator it;
int getCityIndex(string p){
  it=find(name.begin(),name.end(),p); 
  if (it < name.end()) return it-name.begin();
  else{
    name.push_back(p);    
    return name.size()-1;   
  } 
}
int main(){
  int indeg[51],n,m,ansN,a,b;
  string x,y;
  deque<int> G[51];
  while(cin >> n >> m){
    ansN=0;
    for(int i=0;i<n;i++) G[i].clear(); 
    memset(indeg,0,sizeof(indeg));
    for(int i=0;i<m;i++){
      cin >> x >> y;
      a=getCityIndex(x);
      b=getCityIndex(y);
      G[a].push_back(b);
      indeg[b]++;
    }
    for(int i=0;i<n;i++){
      if (indeg[i]==0){
        ansN++;
        cout << name[i]<<endl;
        for(int j=0;j<G[i].size();j++){ 
          indeg[G[i][j]]--;
        }
      }
      if (ansN==n) break;
      else if (i==(n-1)){ 
        i=0;
      }
    }		
  }
}
