#include<iostream>
#include<cstring>
#define Size 101
using namespace std;
int main(){
  bool a[Size];
  int n,p,leave,c,i;
  while(cin >> n){
    cin >> p;
  	leave=0;//leave表示已經淘汰的人數
  	i=2;//第一個不淘汰
  	memset(a,0,sizeof(a));
  	while(leave<(n-1)){
  	  c=0;//c表示間隔幾個人
  	  while(c<p){
  		if (a[i]==0){//還沒淘汰
  		  c++;//間隔人數增加1
  		  if (i<n) i++;
  		  else i=1;//回到編號1號
		  }else{
  		  if (i<n) i++;
  		  else i=1;//回到編號1號				
		  }
	  }
	  while(a[i]==1){//若已經淘汰，找下一個未淘汰
		  if (i<n) i++;
  	    else i=1;
	    }
	    a[i]=1;//淘汰
	    leave++;//已經離開人數增加1
	  }
	  for(int j=1;j<=n;j++){//找出最後未淘汰編號
	    if (a[j]==0){
		    cout << j <<endl;
		    break; 
	    }
	  }
  }
}
