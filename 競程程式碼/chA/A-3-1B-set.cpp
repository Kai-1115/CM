#include <iostream>
#include <set>
using namespace std;
int main (){
  set<int,greater<int> > mset;
  set<int>::iterator it;
  for (int i=1; i<10; i++) mset.insert(i);  
  for (it=mset.begin(); it!=mset.end();it++){
    cout << *it << ' ';
  } 
  cout << endl;
}
