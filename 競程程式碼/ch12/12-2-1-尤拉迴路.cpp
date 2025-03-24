#include <iostream>
#include <deque>
#include <cstring>
using namespace std;
bool v[20];
deque<int> G[20];
void dfs(int  x){
  v[x]=true;
  for(int i=0;i<G[x].size();i++){
    if (!v[G[x][i]]) {
      dfs(G[x][i]);
   }
  }
}
int main(){
  int indeg[20],outdeg[20],dul[2000];
  int n,m,x,y,nout,nin,nequ,nal,start;
  bool success,used[20];
  while(cin >> m){
    for(int i=0;i<20;i++) G[i].clear();
    memset(indeg,0,sizeof(indeg));
    memset(outdeg,0,sizeof(outdeg));
    memset(used,0,sizeof(used)); 
    memset(v,0,sizeof(v));
    memset(dul,0,sizeof(dul)); 
    nout=nin=nequ=nal=0;
    success=false;
    for(int i=0;i<m;i++){
      cin >> x >> y;
      if (dul[x*100+y]==0){
        G[x].push_back(y);
        dul[x*100+y]=1;
      }
      outdeg[x]++;
      indeg[y]++;
      used[x]=true;
      used[y]=true;
    }
    for(int i=0;i<20;i++) if (used[i]) nal++;
    for(int i=0;i<20;i++) {
      if (indeg[i]!=outdeg[i]){
        if ((indeg[i]-outdeg[i])==1){
          nin++;
        }else if ((outdeg[i]-indeg[i])==1) {
          nout++;
          start=i;
        }else {
          break;
        }
      }else{
        if (used[i]) nequ++;
      }
    }
    if ((nin==1) && (nout==1) && (nequ==(nal-2))) success=true;
    if ((nin==0) && (nout==0) && (nequ==nal)) success=true;
    if (success){
      if (nout==1){
        dfs(start);
      }
      if (nout==0){
        for(int i=0;i<20;i++) {
          if(outdeg[i]>0) {
            dfs(i);
            break;
          }
        }
      }
      for(int i=0;i<20;i++) {
        if(used[i]&&!v[i]){
          success=false;
          break;
        }
      }
    }
    if (success) cout<<"可以找到尤拉路徑"<<endl;
    else cout<<"無法找到尤拉路徑"<<endl;
	}
}
