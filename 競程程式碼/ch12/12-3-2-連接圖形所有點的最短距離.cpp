#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
struct Edge{
  int x;
  int y;
  double w;        
};
Edge edge[5000];
double x[100],y[100];
bool compare (Edge a,Edge b){
  return a.w < b.w; 
}
int num[100],parent[100];
int findParent(int a){ 
  while(a!=parent[a]){
    a=parent[a];                  
  }    
  return a;   
}
int main(){
  int n,m,numEdge,s;  
  double result;
  while(cin >> n){
    for(int i=0;i<n;i++){
      cin >> x[i] >> y[i];            
    }
    s=0;
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        edge[s].x=i;
        edge[s].y=j;
        edge[s].w=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
        s++;      
      }              
    }
    for(int i=0;i<n;i++){ 
      parent[i]=i;
      num[i]=1;            
    }
    sort(edge,edge+s,compare);
    result=0,numEdge=0;   
    for(int i=0;i<s && numEdge<n;i++){
      int a,b;
      a=findParent(edge[i].x); 
      b=findParent(edge[i].y); 
      if (a != b){ 
        if (num[a]>num[b]){ 
          parent[b]=a;
          num[a]+=num[b];                   
        } else {
          parent[a]=b;
          num[b]+=num[a];                   
        }
        result+=edge[i].w;
        numEdge++;                                         
      } 
    }
    if (numEdge == (n-1)) {
      cout << result << endl;
    }   
  }    
}
