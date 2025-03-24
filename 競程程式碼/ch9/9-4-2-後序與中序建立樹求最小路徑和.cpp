#include <string>
#include <iostream>
using namespace std;
int posto[1010],ino[1010],len,mins,last;
struct node {
  int value;
  struct node *left;
  struct node *right;
};
node* buildTree(int,int);
void root2leaf(node *,int);
int main(){  
  int n;
  while (cin>>n){
    for(int i=0;i<n;i++){
      cin >> ino[i];
    }
    for(int i=0;i<n;i++){
      cin >> posto[i];
    }
    len=n;
    last=n-1;
    mins=200000000;
    node *root;
    root=buildTree(0,len-1);  
	  root2leaf(root,0);
	  cout <<mins <<endl;
  }
}
node* buildTree(int left,int right){
  int mid;
  node *bNode;
  bNode=new node;
  bNode->value=posto[last--]; 
  if (left<right){
    for(int i=right;i>=left;i--){
      if (bNode->value==ino[i]){ 
        mid=i;
        break;                  
      }                     
    }              
	  if ((mid+1)<=right){
	    bNode->right=buildTree(mid+1,right); 
    }else{
      bNode->right=NULL; 
    } 
    if (left<=(mid-1)) {
      bNode->left=buildTree(left,mid-1);
    }else{
      bNode->left=NULL;
    }    
  }else{
    bNode->left=NULL;
    bNode->right=NULL;   
  }
  return bNode;
}
void root2leaf(node *nd,int sum){
  if ((nd->left==NULL)&&(nd->right==NULL)){
    sum+=nd->value;
    if (mins>sum){
      mins=sum;
    }
  }
  sum+=nd->value;
  if (nd->left != NULL){
    root2leaf(nd->left,sum);
  }
  if (nd->right != NULL){
    root2leaf(nd->right,sum);
  }
}
