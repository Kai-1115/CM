#include <iostream>
#include <list>
using namespace std;
int main(){
  list<int> mlist;
  list<int>::iterator it,its;
  for (int i=1; i<=4; ++i) mlist.push_back(i);//1 2 3 4
  for (its=mlist.begin(); its!=mlist.end(); ++its){ 
    cout << *its << ' ';
  }
  cout << endl; 
  it = mlist.begin();
  ++it;
  mlist.insert (it,5);//1 5 2 3 4
  for (its=mlist.begin(); its!=mlist.end(); ++its){ 
    cout << *its << ' ';
  }
  cout << endl; 
  --it;
  mlist.insert (it,4); //1 4 5 2 3 4              
  for (its=mlist.begin(); its!=mlist.end(); ++its){ 
    cout << *its << ' ';
  }
  cout << endl;
  mlist.remove(4);//1 5 2 3
  for (its=mlist.begin(); its!=mlist.end(); ++its){ 
    cout << *its << ' ';
  }
  cout << endl;
}
