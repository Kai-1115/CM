#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
map<string,int> nmap;	//ㄏノmap盢name锣Θ计
map<string,int>::iterator it; 
int getCityIndex(string p){	//盢name锣Θ计计眖0秨﹍ 
  if (nmap.find(p)==nmap.end()){
    int s=nmap.size();
    nmap[p]=s;
  }
  return nmap[p];
} 
int main(){
  string s[5]={"カ","穝カ","いカ","玭カ","蔼动カ"};
  for(int i=0;i<5;i++){
    int index=getCityIndex(s[i]);
    cout << s[i] << " " << index <<endl;
  }
  for(it=nmap.begin();it!=nmap.end();it++){
    cout << it->first << " " << it->second << endl;
  }	
}
