#include <iostream>
#include <ctime>
#include <cstdlib>
#define Size 10
using namespace std;
void printA(int *a,int s){
  for(int i=0;i<s;i++){
    cout << a[i] << " ";
  }
  cout << endl;
}
int main(){
  int A[Size],tmp;
  srand(time(NULL));
  for (int i=0;i<Size;i++){
    A[i]=rand()%1000+1;
  }
  cout << "排序前" << endl;
  printA(A,Size);
  for(int i=Size-1;i>1;i--){
    for(int j=0;j<i;j++){
      if (A[j]>A[j+1]){
        tmp=A[j]; 
        A[j]=A[j+1];
        A[j+1]=tmp;                
      }                 
    }
    cout << "外層迴圈跑" << Size-i <<"次結果為" << endl;
    printA(A,Size);                  
  }
  cout << "排序後" << endl; 
  printA(A,Size);
}
