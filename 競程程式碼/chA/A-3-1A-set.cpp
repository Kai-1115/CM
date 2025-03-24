#include <iostream>
#include <set>
using namespace std;
int main (){
  set<int> mset;
  set<int>::iterator itl,it;
  for (int i=1; i<10; i++) mset.insert(i); 
  itl=mset.find(4); 
  mset.erase(itl); 
  for (it=mset.begin(); it!=mset.end();it++){
    cout << *it << ' ';
  } 
  cout << endl;
}
