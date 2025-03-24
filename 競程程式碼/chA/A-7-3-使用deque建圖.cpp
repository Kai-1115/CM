#include <iostream>
#include <deque>
using namespace std;
deque<int> F[4];
int main(){
  int x,y,m;
  cin >> m;//m表示邊的個數 
  for(int i=0;i<m;i++){
    cin >> x >> y;      
    F[x].push_back(y);
    F[y].push_back(x);     
  }
  cout << endl;
  for(int i=0;i<4;i++){
    cout << i << "=>";      
    for(int j=0;j<F[i].size();j++){
      cout << F[i][j] << " ";	
    }
    cout << endl;     
  } 
}
