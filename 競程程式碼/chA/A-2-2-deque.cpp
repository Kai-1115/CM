#include <iostream>
#include <deque>
using namespace std;
int main(){
  deque<int> dq;
  for(int i=1;i<=5;i++){
    dq.push_front(i);
  }
  while(!dq.empty()){
    cout << dq.front() << endl;
    dq.pop_front();
  }
  for(int i=1;i<=5;i++){
    dq.push_back(i);
  }
  while(!dq.empty()){
    cout << dq.front() << endl;
    dq.pop_front();
  }
}
