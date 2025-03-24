#include<iostream>
using namespace std; 
int main() {     
  int h,d,n,day;
  double ch,down,r; 
  while(cin >> h){
    cin >> d >> n;
    day=0;//目前第幾天 
    ch=0;//目前爬行高度 
    down=(double)n;//晚上掉下來的距離 
    r=n/10.0;//每次多掉下來的增加距離           
    while(1){
      day++;
      ch=ch+d;//白天往上爬 
      if (ch >= h) break;//爬到樹頂           
      ch=ch-down;//晚上掉下來
			if (ch <= 0) break;//掉到地上 
      down=down+r;//每天更新掉下來的距離     
    }
    if(ch >= h) cout << "第" << day << "天爬到樹頂" << endl;
    if(ch <= 0) cout << "第" << day << "天掉到地面" << endl;                   
  }
}
