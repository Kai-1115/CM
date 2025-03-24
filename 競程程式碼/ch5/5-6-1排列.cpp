#include<iostream>
#include<algorithm>
using namespace std;
int n,num[100],step[100];
void perm(int);
int main(){
  while(cin>>n){
    for(int i=0;i<n;i++){
      cin>>num[i];
    }
    sort(num,num+n);
    perm(0);
  }
}
void perm(int curStep){
  if (curStep==n){
    for(int i=0;i<n;i++){
      cout <<num[step[i]]<<" ";	
    } 
    cout << endl;
  }
  for(int i=0;i<n;i++){
    bool success=true;
    for(int j=0;j<curStep;j++){
      if (step[j]==i){
        success=false;
        break;
      }
    }
    if (success) {
      step[curStep]=i;
      perm(curStep+1);
    }
  }
}
