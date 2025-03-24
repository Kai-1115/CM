#include <iostream>
using namespace std;
int main(){
  int a[100000];//區域變數，儲存在stack區段 
  cout << a << endl;
  cout << a+1 << endl;
  cout << a+2 << endl;
  int *b;
  b=new int(100000);//動態變數，儲存在heap區段 
  cout <<b << endl;
  cout <<b+1 << endl;
  cout <<b+2 << endl;
}
