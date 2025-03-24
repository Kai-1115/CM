#include <iostream>
#include <algorithm>
using namespace std;
int a[10];
int gMax(int,int);
int gCMax(int,int,int);
int main() {
  int ans;
  for(int i=0;i<10;i++){
    cin >> a[i];
  }
  ans=gMax(0,9);
  cout << ans << endl;
}
int gMax(int L,int R){
  int M,maxL,maxR,maxC;
  if (L==R) return a[L];
  M=(L+R)/2;
  maxL=gMax(L,M);
  maxR=gMax(M+1,R);
  maxC=gCMax(L,M,R);
  return max(maxL,max(maxR,maxC));
}
int gCMax(int L,int M,int R){
  int sumL,sumR,maxL,maxR;
  sumL=0;
  maxL=a[M];
  for(int i=M;i>=L;i--){
    sumL+=a[i];
    if (maxL<sumL) maxL=sumL;
  }
  sumR=0;
  maxR=a[M+1];
  for(int i=M+1;i<=R;i++){
    sumR+=a[i];
    if (maxR<sumR) maxR=sumR;
  }
  return max(maxL,max(maxR,maxL+maxR));
}
