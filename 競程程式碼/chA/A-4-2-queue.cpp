#include <iostream> 
#include <queue> 
using namespace std;
int main (){
  queue<int> mqueue;
  for (int i=1; i<10; i++) mqueue.push(i);
  while (!mqueue.empty()){
    cout  << mqueue.front() << endl;
    mqueue.pop();
  }
  cout << endl;
}
