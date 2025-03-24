#include <cstdio>
#include <deque>
#include <algorithm>
#define MAX 100001
using namespace std;
deque<int> F[MAX];
int md;
int DFS(int x) {
  int max1, max2, result;
  if (F[x].size() == 0) return 0;//沒有小孩，遞迴中止
  if (F[x].size() == 1) return DFS(F[x][0])+1;//小孩只有一個
  else {//小孩超過兩個以上
	for (int i = 0; i<F[x].size(); i++) {//走訪每一個小孩，找出最長深度的前兩名，最長深度儲存到max1，第二長深度儲存到max2
	  result = DFS(F[x][i]) + 1;//該小孩的深度
	  if (i == 0) max1 = result; //走訪第一個小孩時
	  else if (i == 1) {//走訪第二個小孩時
	    if (max1 >= result) max2 = result;
		else {
		  int tmp = max1;
		  max1 = result;
		  max2 = tmp;
		}
	  } else {//走訪第三個以後的小孩時
		if (max1 <= result) {
		  max2 = max1;
		  max1 = result;
		}else if (max2 < result) max2 = result;
	  }
	}
    md = max(md, max1 + max2);//中間的節點分支度大於等於2，最大血緣關係為小孩中最長深度與第二長深度相加
    return max1;//由上到下找尋過程，祖先分支度只有1時，呼叫「DFS(F[x][0])+1」，需要回傳DFS(F[x][0])的結果，就是回傳max1
  }
}
int main() {
  int a, b,root,rd,n;
  bool isChild[MAX];
  while (scanf("%d", &n) != EOF) {
	md = 0;
	for (int i = 0; i<n; i++) {
	  F[i].clear();
	  isChild[i] = false;
	}
	for (int i = 1; i<n; i++) {//建立由雙親到小孩的有向圖
	  scanf("%d %d", &a, &b);
	  F[a].push_back(b);
	  isChild[b] = true;//b是小孩，設定isChild為true
	}
	for (int i = 0; i < n; i++) {//找出root
	  if (!isChild[i]) {//只要不曾經是小孩，就是root
		root = i;
		break;
	  }
	}
	rd = DFS(root);//rd為從root出發最長長度，函式DFS過程會計算子孫節點的多個小孩的最長兩個小孩長度相加到md
	md=max(rd,md);//md為子孫節點的多個小孩的最長兩個小孩長度相加，rd與md取最大
	printf("%d\n", md);
  }
}
