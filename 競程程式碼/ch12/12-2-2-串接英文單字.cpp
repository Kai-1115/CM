#include<iostream>
#include<deque>
#include<cstring>
#include <string>
using namespace std;
bool v[26];
deque<int> G[26];
void dfs(int  x){
  v[x]=true;
  for(int i=0;i<G[x].size();i++){
    if (!v[G[x][i]]) {
      dfs(G[x][i]);
    }
  }
}
int main(){
  int indeg[26],outdeg[26],dul[2600];
  int n,m,x,y,nout,nin,nequ,nal,start;
  string s;
  bool success,used[26];
  while(cin >> m){
    for(int i=0;i<26;i++) G[i].clear();
    memset(indeg,0,sizeof(indeg));
    memset(outdeg,0,sizeof(outdeg));
    memset(used,0,sizeof(used)); 
    memset(v,0,sizeof(v));
    memset(dul,0,sizeof(dul)); 
    nout=nin=nequ=nal=0;
    success=false;
    for(int i=0;i<m;i++){
      cin >> s;
      x=s[0]-'a';
      y=s[s.length()-1]-'a';
      if (dul[x*100+y]==0){
        G[x].push_back(y);
        dul[x*100+y]=1;
      }
      outdeg[x]++;
      indeg[y]++;
      used[x]=true;
      used[y]=true;
    }
    for(int i=0;i<26;i++) if (used[i]) nal++;
    for(int i=0;i<26;i++) {
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
        for(int i=0;i<26;i++) {
          if(outdeg[i]>0) {
            dfs(i);
            break;
          }
        }
      }
      for(int i=0;i<26;i++) {
        if(used[i]&&!v[i]){
          success=false;
          break;
        }
      }
    }
    if (success) cout<<"可以串接"<<endl;
    else cout<<"無法串接"<<endl;
  }
}
