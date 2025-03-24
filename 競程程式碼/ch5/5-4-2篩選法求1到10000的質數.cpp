#include <iostream>
#include <cmath>
using namespace std;
bool mark[10001]; //求使用篩選法求質數，true非質數  false質數 
void erase(int x){
  int sq = (int)sqrt(x);
  mark[1] = true;//1不是質數 
  for (int i=2; i<=sq; i++){
    if (!mark[i]){//將2,3,5...倍數的數皆不是質數 
      for (int j=i*i;j<=x;j+=i){
        mark[j] = true;
      }
    }
  }
}
int main(){
  erase(10000);//啟動篩選法求質數 
  for(int n=2;n<=10000;n++){   
    if (!mark[n]){
      cout << n <<endl;               
    }  
  }
}
