#include <iostream>
#include <cstring>
#include <deque>
using namespace std;
int chess[501][501];
int gor[8]={1,-1,-2,-2,-1,1,2,2}; 
int goc[8]={2,2,1,-1,-2,-2,-1,1};
int stopr[8]={0,0,-1,-1,0,0,1,1}; 
int stopc[8]={1,1,0,0,-1,-1,0,0};
struct Point{
  int r;
  int c;
  int step;        
};
deque<Point> myq;
int bound(int row,int col){
  if (((row>=0)&&(row<500))&&((col>=0)&&(col<500))) return 1;
  else return 0;    
}
int main(){ 
  int n,r,c,sr,sc,tr,tc,minstep;
  Point myp,nextp;
  while (cin >> n){
    minstep=9999999;
    memset(chess,0,sizeof(chess));
    for(int i=0;i<n;i++){
      cin >> r >> c;        
      chess[r][c]=1;
    }
    cin >> sr >> sc;
    cin >> tr >> tc;
    chess[tr][tc]=999;
    chess[sr][sc]=2;
    myp.r=sr;
    myp.c=sc;
    myp.step=1;
    myq.push_back(myp);
    while (myq.size()>0){
      nextp=myq.front();
      myq.pop_front();     
      for(int i=0;i<8;i++){
        if ((bound(nextp.r+stopr[i],nextp.c+stopc[i]))&&
        (chess[nextp.r+stopr[i]][nextp.c+stopc[i]] != 1)) {
          if (bound(nextp.r+gor[i],nextp.c+goc[i])&&
          (chess[nextp.r+gor[i]][nextp.c+goc[i]] == 0)){ 
            chess[nextp.r+gor[i]][nextp.c+goc[i]]=2;
            myp.r=nextp.r+gor[i];
            myp.c=nextp.c+goc[i];
            myp.step=nextp.step+1;
            myq.push_back(myp); 
          }
          if (bound(nextp.r+gor[i],nextp.c+goc[i])&&
          (chess[nextp.r+gor[i]][nextp.c+goc[i]]==999)) { 
            if (minstep > (nextp.step+1)) {
              minstep=nextp.step+1;
              myq.clear();
              break;
            }
          }
        }
      }
    }
    if (minstep == 9999999) cout << "無法到達" <<endl;
    else cout << minstep << endl;
  }
}
