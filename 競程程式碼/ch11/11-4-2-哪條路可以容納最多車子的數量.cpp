#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int dis[100][100];
int main(){
  int a,b,w,n,m;
  while (cin >> n >> m){
    memset(dis,-1,sizeof(dis));
    for(int i=0;i<n;i++){ 
      dis[i][i]=0;           
    }    
    for(int i=0;i<m;i++){ 
      cin >> a >> b >> w;
      dis[a][b]=w;
      dis[b][a]=w;           
    }
    for(int k=0;k<n;k++){
      for(int i=0;i<n;i++){  
        for(int j=0;j<n;j++){
          if ((i!=j)&&(dis[i][k]!=-1)&&(dis[k][j]!=-1)) {
            dis[i][j]=max(dis[i][j],min(dis[i][k],dis[k][j]));                                      
          }            
        }              
      }                    
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cout << dis[i][j]<<" ";
      }
      cout << endl;
    }    
  }          
}
