#include <iostream>
#include <queue>
using namespace std;
int main(){
  int n,v;
  queue<int> q;
  while(cin >>n){
    for(int i=0;i<n;i++){
      cin >> v;
      q.push(v);
    }
    while(q.size()>1){
      v=q.front();
      cout << "將"<<v<<"加到最後" << endl;
      q.pop();
      q.push(v);
      v=q.front();
      cout << "將"<<v<<"加到最後" << endl;
      q.pop();
      q.push(v);
      v=q.front();
      cout << "將"<<v<<"刪除" << endl;
      q.pop();      
    }
    cout << "剩餘最後一個號碼為"<<q.front()<<endl; 
  }
}
