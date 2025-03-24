#include<iostream>
#include<algorithm>
using namespace std;
struct obj{
  int w;
  int v;
  double vw; 
};
bool cmp(obj a,obj b){
  return (a.vw>b.vw);
}
int main(){
  int n,k,ktmp;
  double totalv;
  obj ob[101];
  while(cin>>n){
    for(int i=0;i<n;i++){
      cin >> ob[i].w >> ob[i].v;
      ob[i].vw=(double)ob[i].v/ob[i].w;
    }
    cin >> k;
    ktmp=k;
    sort(ob,ob+n,cmp);
    for(int i=0;i<n;i++){
      if (ob[i].w<=ktmp) {
        totalv+=ob[i].v;
        ktmp-=ob[i].w;
      }else{
        totalv+=(double)ob[i].vw*ktmp;
        break;
      }
    }
    cout << totalv << endl;
  }
}
