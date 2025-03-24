#include <iostream>
#include <cstring>
using namespace std;
int main(){
  int n,t,now,ans; 
  int arr[200],time[200],ser[600];
  while(cin >> t){
  	cin >> n;
  	for(int i=0;i<n;i++){
    	cin >> arr[i] >> time[i];      
  	}
  	memset(ser,0,sizeof(ser));
  	now=-1;//服務目前客人完成的時間 
  	ans=0;
  	for(int i=0;i<n;i++){
  		if (now>=t*60) break; //超過服務時間 
    	if (arr[i]>=now){//客人較晚到或剛好客人離開 
    		for(int j=arr[i];j<arr[i]+time[i];j++){
    			if (j>=t*60) break;//超過服務時間 
					ser[j]=1;//ser[]為1，表示服務客人 
				}
				now=arr[i]+time[i];//服務目前客人完成的時間 
			}else{//客人需要等待 
    		for(int j=now;j<now+time[i];j++){
    			if (j>=t*60) break;//超過服務時間
    			ser[j]=1;//ser[]為1，表示服務客人
				}
				now=now+time[i];//服務目前客人完成的時間 				
			}    
  	}
		for(int i=0;i<t*60;i++){//計算沒有客人的時間 
    	if (ser[i]==0){
    		ans++;
			}     
  	}
		cout << ans << endl;  	
	}   
}
