#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
  int pair;
  string s;
  stack<char> st;
  while(getline(cin,s)){
    pair=0;
    while(!st.empty()) st.pop();
    for(int i=0;i<s.length();i++){
      if(s[i]=='{') {
        st.push('{');
      }        
      if(s[i]=='}') {
        if (st.size()>0){
          st.pop();
          pair++;
        }else{
          pair=-1;
          break;
        }
      }            
    }
    if (st.size()==0 && pair>=0){
      cout<<"共有"<<pair<<"對的大括號"<<endl;
    }else{
      cout<<"配對失敗"<<endl;
    }      
  }
}
