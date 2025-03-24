#include <iostream>
#include <list>
using namespace std;
int main(){
  int n,m,p,pos;
  char cmd;
  list<int> mlist;
  list<int>::iterator it;
  while(cin>>n>>m){
    mlist.clear(); 
    for(int i=1;i<=n;i++) mlist.push_back(i);
    for(int i=1;i<=m;i++){
      cin >> cmd;
      if (cmd=='s') {
        cout << mlist.front() << endl;
        mlist.push_back(mlist.front());
        mlist.pop_front();
      }else{
        cin >> p >> pos;
        mlist.remove(p);
        it = mlist.begin();
        for(int i=1;i<pos;i++) it++;
        mlist.insert(it,p);
      }
    }    
  }
}
