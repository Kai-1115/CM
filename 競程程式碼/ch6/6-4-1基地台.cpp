#include<iostream>
#include<algorithm>
using namespace std;
int n,k;
int v[50001];
bool test(int x){//耞畖x瞇籠┮Τ沮翴
  int next,count=0;
  for(int i=0;i<n;){
	next=v[i]+x;
	count++;
	if (count > k) {//膀计k
	  return false;
	}
	if ((v[n-1]<=next)&&(count<=k)) return true;//笷程狝叭膀计单k
    do{
      i++;
	}while (v[i] <= next);
  }
  return false;
}
int main(){
  int L,R,M,sta;
  while (cin>>n){
    cin >> k;
    for(int i=0;i<n;i++){
      cin >> v[i];
    }
    sort(v, v+n);
	if (k==1){
	  cout<< v[n-1]-v[0]<<endl;
	}else{
      L=1;//程畖1
      R=((v[n-1]-v[0])/k)+1;//程畖((v[n-1]-v[0])/k)+1﹚┮Τ沮翴
      while(L<=R){//ㄏノじ穓碝
        M=(L+R)/2;
        if (test(M)) R=M;
        else L=M+1;
        if (L==R) break;
      }
      cout << R <<endl;
	}
  }
}
