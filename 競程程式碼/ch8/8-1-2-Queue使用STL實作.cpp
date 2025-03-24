#include <iostream> 
#include <queue> 
using namespace std;
int main (){
	queue<int> mqueue;
	for (int i=1; i<=4; i++) {
	  mqueue.push(i);
  }
	while (!mqueue.empty()){
		cout  << mqueue.front() <<" ";
		mqueue.pop();
	}
	cout << endl;
}
