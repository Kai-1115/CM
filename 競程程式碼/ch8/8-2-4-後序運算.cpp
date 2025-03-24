#include <iostream>
#include <stack>
#include <sstream>
using namespace std;
int main(void){
  string s,c;
  int num,a,b;
  while(getline(cin,s)){
    stringstream ss;
    ss<<s;
    stack<int> st;
    while (ss>>c){
      if (c=="+"){
         a=st.top();
         st.pop();
         b=st.top();
         st.pop();
         st.push(b+a);                                                             
      }else if (c=="-"){
         a=st.top();
         st.pop();
         b=st.top();
         st.pop();
         st.push(b-a);                         
      }else if (c=="*"){
         a=st.top();
         st.pop();
         b=st.top();
         st.pop();
         st.push(b*a);                         
      }else if (c=="/"){
         a=st.top();
         st.pop();
         b=st.top();
         st.pop();
         st.push(b/a);             
      }else{
        num=0;
        for(int i=0;i<c.length();i++){
          num=num*10+c[i]-'0';          
        }
        st.push(num);
      }               
    }
    cout << st.top() << endl;
  }
}
