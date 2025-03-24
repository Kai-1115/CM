#include <string>
#include <iostream>
using namespace std;
string preo,ino;
int len,first;
struct node {
  char data;
  struct node *left;
  struct node *right;
};
node* buildTree(int,int);
void postorder(node*);
int main(){  
  while (cin >> preo){
    cin >> ino;
    first=0;
    len=ino.length();
    node *root;
    root=buildTree(0,len-1);
	  postorder(root);
    cout << endl;
  }
}
void postorder(node *p){
  if (p != NULL){     
    postorder(p->left);
    postorder(p->right);
    cout << p->data;
  }   
}
node* buildTree(int left,int right){
  int mid;
  node *bNode;
  bNode=new node;
  bNode->data=preo[first++]; 
  if (left<right){
    for(int i=left;i<=right;i++){
      if (bNode->data==ino[i]){ 
        mid=i;
        break;                  
      }                     
    } 
    if (left<=(mid-1)){
      bNode->left=buildTree(left,mid-1);
    }else{
      bNode->left=NULL;
    }               
	  if ((mid+1)<=right){
	    bNode->right=buildTree(mid+1,right); 
    }else{
      bNode->right=NULL; 
    } 
  }else{
    bNode->left=NULL;
    bNode->right=NULL;   
  }
  return bNode;
}
