#include <iostream>
using namespace std;
int g[1000000]={1};//儲存在data區段，全域變數初始化為非0值 
int main(){
	static int h[1000000]={1};//儲存在data區段，靜態變數初始化為非0值 
}
