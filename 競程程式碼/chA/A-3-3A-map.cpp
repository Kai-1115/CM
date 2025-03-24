#include <iostream>
#include <map>
using namespace std;
int main (){
  map<char,int> mmap;
  map<char,int>::iterator it;
  mmap.insert(pair<char,int>('a',97));
  mmap['b']=98;
  mmap['c']=99;
  mmap['d']=100;
  for (it=mmap.begin(); it!=mmap.end(); ++it){
    cout << it->first << " => " << it->second << endl;
  }
  it=mmap.find('c');
  mmap.erase(it);
  for (it=mmap.begin(); it!=mmap.end(); ++it){
    cout << it->first << " => " << it->second << endl;
  }
}
