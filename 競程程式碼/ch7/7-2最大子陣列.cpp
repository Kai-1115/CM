#include <iostream>
using namespace std;
int main() {
	int a[10],max,sum;
	for(int i=0;i<10;i++){
		cin >> a[i];
	}
	max=-200000000;
	sum=0;
	for(int i=0;i<10;i++){
		sum=sum+a[i];
    if (sum<0) sum=0;				
		if (sum>max) max=sum;
	}
	cout << max << endl;
}
