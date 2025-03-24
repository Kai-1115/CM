#include <iostream>
#include <queue>
using namespace std;
int main(){
  priority_queue <int> pq; //預設數字大的最上面 
  pq.push(4);
  pq.push(8);
  pq.push(3);
  pq.push(5);
  pq.push(2);
  while(!pq.empty()){
    cout << pq.top() << endl;
    pq.pop();
  }   
}
