#include <iostream>
#include <cstring>
#include <deque>
using namespace std;
int map[101][101];
int re[101][101];
int gor[4]={0,1,0,-1};
int goc[4]={1,0,-1,0};
struct Point{
  int r;
  int c;
  int dis;        
};
deque<Point> myq;
bool bound(int row,int col,int nr,int nc){ 
  if (((row>0)&&(row<=nr))&&((col>0)&&(col<=nc))) return 1;
  else return 0;    
}
int main(){   
  int r,c,sr,sc;
  Point myp,nextp;
  while(1){
    memset(re,0,sizeof(re));
    myq.clear();
    cin >> r >> c;
    for(int i=1;i<=r;i++){
      for(int j=1;j<=c;j++){
        cin>>map[i][j];        
      }
    }
    cin >> sr >> sc;
    myp.r=sr;
    myp.c=sc;
    myp.dis=1;
    re[myp.r][myp.c]=1;
    myq.push_back(myp);
    while (myq.size()>0){
      nextp=myq.front();
      myq.pop_front();  
      for(int i=0;i<4;i++){ 
        if (bound(nextp.r+gor[i],nextp.c+goc[i],r,c)&&
        (map[nextp.r+gor[i]][nextp.c+goc[i]] == 1)&&
        (re[nextp.r+gor[i]][nextp.c+goc[i]] == 0)){ 
          re[nextp.r+gor[i]][nextp.c+goc[i]]=nextp.dis+1;
          myp.r=nextp.r+gor[i];
          myp.c=nextp.c+goc[i];
          myp.dis=nextp.dis+1;
          myq.push_back(myp); 
        }                
      }
    }
    for(int i=1;i<=r;i++){
      for(int j=1;j<=c;j++){
        cout << re[i][j] << " ";        
      }
      cout << endl;
    }    
  }
}
