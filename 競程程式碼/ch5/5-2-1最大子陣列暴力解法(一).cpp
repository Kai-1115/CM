#include <iostream>
using namespace std;
int main() {
  int a[10],max,sum;
  for(int i=0;i<10;i++){
    cin >> a[i];
  }
  max=-200000000;
  for(int i=0;i<10;i++){
    for(int j=i;j<10;j++){
      sum=0;			
      for(int k=i;k<=j;k++){
        sum=sum+a[k];
      }
      if (sum>max) max=sum;
    }
  }
  cout << max << endl;
}
