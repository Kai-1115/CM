#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
vector<string> name;
vector<string>::iterator it;
int getCityIndex(string p){
  it=find(name.begin(),name.end(),p);  //在name中找尋字串p  
  if (it < name.end()) return it-name.begin();
  else if (it == name.end()){  //找不到 
    name.push_back(p);         //字串p加入name     
    return name.size()-1;   
  } 
}
int main(){
  string s[5]={"台北市","新北市","台中市","台南市","高雄市"};
  for(int i=0;i<5;i++){
    int index=getCityIndex(s[i]);
    cout << s[i] << " " << index <<endl;
  }
  for(int i=0;i<5;i++){
    cout << i <<" " << name[i] <<endl;
  }	
}
