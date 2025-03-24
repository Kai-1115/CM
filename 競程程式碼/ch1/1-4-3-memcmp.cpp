#include <iostream>
#include <cstring>
using namespace std;
int main(){
  char tmp1[11]="I love C++";
  char tmp2[12]="I love Java";
  int n;
  n=memcmp(tmp1,tmp2, sizeof(tmp1) );
  if (n>0) cout << tmp1 << "大於" << tmp2 << endl;
  else if (n<0) cout << tmp1 << "小於" << tmp2 << endl;
  else cout << tmp1 << "等於" << tmp2 << endl;
}
