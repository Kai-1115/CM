#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n, m, k, now;
  vector<int> p;
  while (cin >> n >> m >> k) {
	p.clear();
	for (int i = 1; i <= n; i++) {
	  p.push_back(i);
	}
	now = 0;
	for (int i = 0; i<k; i++) {
	  now = (now + m - 1) % p.size();
	  p.erase(p.begin() + now);//§R°£²^¨Oªº¤H
	}
	now = now%p.size();
    cout << p[now]<<endl;
  }
}
