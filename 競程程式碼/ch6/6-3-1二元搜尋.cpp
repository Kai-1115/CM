#include <iostream>
using namespace std;
int main(){
  int score[10]={45, 59, 62, 67, 70, 78, 83, 85, 88, 92};  
  int mid=5,left=0,right=9;
  while (score[mid] != 59){
    cout << "檢查score[" << mid << "]=" << score[mid] << "是否等於59" << endl; 
    if (left >=right){
      break;         
    }
    if (score[mid] > 59) {
      right=mid-1;       
    }else {
      left=mid+1;    
    }          
    mid=(left+right)/2;
    cout << "right更新為" << right << endl;
    cout << "left更新為" << left << endl; 
    cout << "mid更新為" << mid << endl;   
  }
  if (score[mid] == 59){
    cout << "找到59分" << endl;               
  } else {
    cout << "找不到59分" << endl;     
  }
}
