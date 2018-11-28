#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int xx[2] = { 1, 0 };
int yy[2] = { 0, 1 };
int m, n;
int dec1[105][105];
int num;
void dfs(int x, int y){
	if (x == m - 1 && y == n - 1) { num++; return; }
	if(x<=m-1&&y<=n-1){
		for (int i = 0; i < 2; ++i){
			int ex = x + xx[i];
			int ey = y + yy[i];
			dfs(ex,ey);
		}
	}
}
int main(){
	int s;
	scanf("%d",&s);
	while (s--){
		num = 0;
	    scanf("%d%d",&m,&n);
	    dfs(0, 0);
	printf("%d\n",num);
   }	
}