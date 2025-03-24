#include <iostream>
#include <algorithm>
using namespace std;
void find(int,int);
int step[100],num[100];
int n,m;
int main(){
  while (cin>>n){
    for(int i=0;i<n;i++){
      cin >> num[i];        
    }    
    cin >> m;
		sort(num,num+n);
    find(0,0);  
  }   
}
void find(int curStep,int start){
  int j;
  if (curStep == m){
    for(int i=0;i<m;i++){
      cout << num[step[i]] << " ";      
    }
    cout << endl;                
  }else{     
    for(j=start;j<n;j++){
      step[curStep]=j;
      find(curStep+1,j+1);      
    }
  }     
}
