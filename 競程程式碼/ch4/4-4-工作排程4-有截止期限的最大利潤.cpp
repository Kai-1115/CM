#include<iostream>
#include<algorithm>
using namespace std;
struct job{
  int x;
  int ic; 
};
bool cmp1(job a,job b){ 
  if (a.ic==b.ic) a.x<b.x;//若獲利相同，截止時間早的排在前面
  return a.ic>b.ic;//獲利高的排在前面
}
bool cmp2(job a,job b){
  return a.x<b.x;//截止時間早的排在前面
}
int main(){
  int n,now,c;
  job jb[101],ans[101];
  while(cin>>n){
    for(int i=0;i<n;i++){
      cin >> jb[i].x >> jb[i].ic; 
    }
    sort(jb,jb+n,cmp1);//獲利高的排在前面，若獲利相同，截止時間早的排在前面
    ans[0]=jb[0];//陣列ans儲存確定會執行的工作 
    c=1;
    for(int i=1;i<n;i++){
      int j;
      bool found=false;
      for(j=0;j<c;j++){//將jb[i]加入會影響，比jb[i].x相同或大一點(沒有相同時)截止時間 
        if (ans[j].x >= jb[i].x){//找尋陣列ans中的x，有沒有大於或等於jb[i].x的工作 
          found=true;
          break;
        }
      }
      while((found)&&(j<(c-1))&&(ans[j+1].x==ans[j].x)) j++;//將陣列ans中找到最後不等於ans[j].x的元素為止 
      if (!found){//若陣列ans中的x沒有大於等於jb[i].x，jb[i]可以執行加入陣列ans 
        ans[c]=jb[i];
        c++;
        sort(ans,ans+c,cmp2);//截止時間早的排在前面
      }else	if ((j+1)<jb[i].x) {//若陣列ans中的x有元素大於等於jb[i].x，(j+1)表示目前小於或等於jb[i].x個數，若 (j+1)<jb[i].x表示有缺額 
        ans[c]=jb[i];
        c++;
        sort(ans,ans+c,cmp2);//截止時間早的排在前面
      }
    }
    int sum=0;
    for(int i=0;i<c;i++){
      sum+=ans[i].ic;
    }
    cout << sum << endl;
  }
}
