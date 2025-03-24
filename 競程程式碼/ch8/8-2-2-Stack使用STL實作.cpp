#include <iostream> 
#include <stack> 
using namespace std;
int main (){
	stack<int> mstack;
	for (int i=1; i<=4; i++) {
	  mstack.push(i);
  }
	while (!mstack.empty()){
		cout  << mstack.top() <<" ";
		mstack.pop();
	}
	cout << endl;
}
