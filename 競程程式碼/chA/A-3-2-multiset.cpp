#include <iostream>
#include <set>
using namespace std;
int main (){
  multiset<int> mmset;
  multiset<int>::iterator it;
  for (int i=1; i<6; i++) mmset.insert(i);
  for (it=mmset.begin(); it!=mmset.end();it++){
    cout << *it << ' ';
  }
  cout << endl;
  for (int i=1; i<6; i++) mmset.insert(i);
  for (it=mmset.begin(); it!=mmset.end();it++){
    cout << *it << ' ';
  }
  cout << endl;
  mmset.erase(4); 
  for (it=mmset.begin(); it!=mmset.end();it++){
    cout << *it << ' ';
  } 
  cout << endl;
}
