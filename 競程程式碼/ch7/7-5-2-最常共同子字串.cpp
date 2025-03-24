#include <iostream>
#include<cstring>
using namespace std;
string s1,s2,s3;
int lcs[101][101],map[101][101];
void pr(int,int);
int main() {
  int s1n,s2n;
  while(getline(cin,s1)){
    getline(cin,s2);
    s1n=s1.length();
    s2n=s2.length();
    memset(lcs,0,sizeof(lcs));
    memset(map,0,sizeof(map));          
    for(int i=0;i<s1n;i++){
      for(int j=0;j<s2n;j++){
        if (s1[i]==s2[j]) {
          lcs[i+1][j+1]=lcs[i][j]+1;
          map[i+1][j+1]=3;      
        }else {
          if(lcs[i][j+1]>lcs[i+1][j]) {
            lcs[i+1][j+1]=lcs[i][j+1];
            map[i+1][j+1]=1;
          }else{
            lcs[i+1][j+1]=lcs[i+1][j];
            map[i+1][j+1]=2;
          }             
        }                    
      }
    }
    cout << lcs[s1n][s2n] << endl; 
    pr(s1n,s2n);
    for(int i=s3.length()-1;i>=0;i--) cout << s3[i];
    cout <<endl;    
  }
}
void pr(int x,int y){
  if (x==0 || y==0) return;
  if (map[x][y]==3){
    s3=s3+s1[x-1];
    pr(x-1,y-1);
  }else if (map[x][y]==1){
    pr(x-1,y);
  }else if (map[x][y]==2){
    pr(x,y-1);   
  }
}
