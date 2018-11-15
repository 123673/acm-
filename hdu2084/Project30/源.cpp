#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[105][105];
int tower[105][105];

int main(){
	int n, m;
	scanf("%d",&n);
	while (n--){
		memset(dp, 0, sizeof(dp));
		scanf("%d",&m);
		for (int i = 0; i < m; ++i){
			for (int j = 0; j <= i; ++j){
				scanf("%d",&tower[i][j]);
			}
		}
		for (int i = m - 1; i >= 0; --i){
			for (int j = 0; j <= i; ++j){
				dp[i][j] = tower[i][j] + max(dp[i+1][j],dp[i+1][j+1]);
			}
		}
		printf("%d\n", dp[0][0]);
	}
	system("pause");
	return 0;
}