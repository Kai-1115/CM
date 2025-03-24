#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
using namespace std;
int main() {
  int n;
  int ch[26];
  string s;
  cin >> n;
  cin.ignore();
  for(int j=0;j<n;j++){
    getline(cin,s);
    memset(ch,0,sizeof(ch));
    for(int i=0;i<s.length();i++){
      if (isalpha(s[i])) ch[tolower(s[i])-'a']++;        
    }
    for(int i=0;i<26;i++){
    	if (ch[i]>0) cout << (char)('a'+i) << " " << ch[i] << endl;        
    }             
  }
}
