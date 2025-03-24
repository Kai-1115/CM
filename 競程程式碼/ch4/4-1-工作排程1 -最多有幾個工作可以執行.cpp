#include<iostream>
#include<algorithm>
using namespace std;
struct job{
  int s;
  int e; 
};
bool cmp(job a,job b){
  return a.e<b.e;
}
int main(){
  int n,now,ans;
  job jb[101];
  while(cin>>n){
    for(int i=0;i<n;i++){
      cin >> jb[i].s>>jb[i].e; 
    }
    sort(jb,jb+n,cmp);
    ans=0;
    now=-1;
    for(int i=0;i<n;i++){
      if (now<=jb[i].s) {
        ans++;
        now=jb[i].e;
      }
    }
    cout << ans << endl;
  }
}
