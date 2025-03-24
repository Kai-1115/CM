#include <iostream>
#include <cstring>
#include <deque>
using namespace std;
int chess[21][21],r,c;
int gor[8]={1,-1,-2,-2,-1,1,2,2}; 
int goc[8]={2,2,1,-1,-2,-2,-1,1};
struct Point{
  int r;
  int c;
  int step;        
};
deque<Point> myq;
int bound(int ir,int ic){
  if (((ir>=1)&&(ir<=r))&&((ic>=1)&&(ic<=c))) return 1;
  else return 0;    
}
int main(){    
  int sr,sc;
  Point myp,nextp;
  while (cin >> r >> c){
    cin >> sr >> sc;
    memset(chess,0,sizeof(chess));
    chess[sr][sc]=1;
    myp.r=sr;
    myp.c=sc;
    myp.step=1;
    myq.push_back(myp);
    while (myq.size()>0){
      nextp=myq.front(); 
      myq.pop_front();
      for(int i=0;i<8;i++){ 
        if (bound(nextp.r+gor[i],nextp.c+goc[i])&&
        (chess[nextp.r+gor[i]][nextp.c+goc[i]] == 0)){
          chess[nextp.r+gor[i]][nextp.c+goc[i]]=nextp.step+1;
          myp.r=nextp.r+gor[i];
          myp.c=nextp.c+goc[i];
          myp.step=nextp.step+1;
          myq.push_back(myp);
       }
      }
    }
    for(int i=1;i<=r;i++){
      for(int j=1;j<=c;j++){
        cout << chess[i][j]<<" ";
      }
      cout << endl;
    }
  }
}
