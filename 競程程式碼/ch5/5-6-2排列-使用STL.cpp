#include <iostream>
#include <algorithm>
using namespace std;
int main () {
  int n,num[100];
  while(cin >> n){
  	for(int i=0;i<n;i++){
			cin>>num[i];
		}
		sort(num,num+n);
    do {
      for(int i=0;i<n;i++) {
      	cout << num[i] <<" ";
			}
      cout << endl;
    }while(next_permutation(num,num+n));
	}
}
