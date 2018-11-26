#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int sou[1000][1000];
int main(){
	int m, n;
	printf("请输入您所要求传递闭包的矩阵的行数和列数：\n");
	scanf("%d%d",&m,&n);
	printf("请输入关系矩阵：\n");
	for (int i = 0; i < m; ++i){
		for (int j = 0; j < n; ++j){
			scanf("%d",&sou[i][j]);
		}
	}
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			if (sou[j][i]==1){
				for (int k = 0; k < m; ++k){
					sou[j][k] = max(sou[j][k], sou[i][k]);
				}
			}
		}
	}
	for (int i = 0; i < m; ++i){
		for (int j = 0; j < n; ++j){
			printf("%d ",sou[i][j]);
		}
		printf("\n");
	}
	system("pause");
}