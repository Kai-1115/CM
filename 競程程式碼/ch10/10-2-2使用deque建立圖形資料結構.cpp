#include <iostream>
#include <deque>
using namespace std;
deque<int> G[100];
int main(){
  int n,a,b;
  cin >> n;
  for(int i=0;i<n;i++){
    G[i].clear();              
  }
  for(int i=0;i<n;i++){
    cin >> a >> b;     
    G[a].push_back(b);
    G[b].push_back(a);     
  }         
}
