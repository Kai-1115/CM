#include <iostream>
using namespace std;
int g[1000000];//儲存在bss區段，全域變數未初始化 
int main(){
	static int h[1000000];//儲存在bss區段，靜態變數未初始化
}
