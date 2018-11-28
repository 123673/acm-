/*
题目：给定一个大小是m*n（m,n<=100）的整形数组A，求从A[0][0]到A[m-1][n-1]共有多少条路径，注意只能向右或是向下移动！
题型：动态规划
思路：找到状态转移方程：dec[i][j] = dec[i -1][j]+dec[i][j-1];此题得解
*/

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main(){
	int dec[105][105];
	int m, n;
	int s;
	scanf("%d", &s);
	while (s--){
		scanf("%d%d",&m,&n);
		for (int i = 0; i < m; ++i){
			for (int j = 0; j < n; ++j){
				if (i == 0||j==0) dec[i][j] = 1;
				else dec[i][j] = dec[i - 1][j] + dec[i][j - 1];
			}
		}
		printf("%d\n",dec[m-1][n-1]);
	}
	system("pause");
}