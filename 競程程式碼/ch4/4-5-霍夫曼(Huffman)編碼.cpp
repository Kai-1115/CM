#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;
struct node{
  int id;//索引值
  char ch;//字元 
  int w;//頻率 
  bool t;//t為true表示為字元節點 
  int le;//左邊的索引值 
  int ri;//右邊的索引值 
};
node hf[101];
deque<node> tmp;
char code[10];
bool cmp(node a,node b){//頻率越少的排前面 
  return a.w<b.w;
}
void dfs(int id,int level){//由dfs走訪所有節點，印出字元與對應的編碼 
  if (!hf[id].t){
    code[level]='0';//左邊編碼0 
    dfs(hf[id].le,level+1);
    code[level]='1';//右邊編碼1 
    dfs(hf[id].ri,level+1);
  }else{
    cout << hf[id].ch <<" ";
    for(int i=0;i<level;i++) cout << code[i];
    cout << endl;
  }
}
int main(){
  int n,w,num;
  char c;
  while(cin>>n){
    tmp.clear();
    for(int i=0;i<n;i++){
      cin >> c >> w; 
      hf[i].id=i;
      hf[i].ch=c;
      hf[i].w=w;
      hf[i].t=true;
      tmp.push_back(hf[i]);
    }
    num=n;
    sort(tmp.begin(),tmp.end(),cmp);//頻率越少的排前面 
    while(tmp.size()>1){
      node a,b,s;
      a=tmp.front();
      tmp.pop_front();
      b=tmp.front();
      tmp.pop_front();
      s.id=num;
      s.t=false;
      s.le=a.id;
      s.ri=b.id;
      s.w=a.w+b.w;
      hf[num]=s;
      tmp.push_back(s);
      sort(tmp.begin(),tmp.end(),cmp);//頻率越少的排前面 
      num++;
    }
    dfs(tmp[0].id,0);
  }
}
