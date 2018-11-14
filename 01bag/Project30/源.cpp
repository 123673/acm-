#include<iostream>
#include<cstring>
#include<algorithm>
int dp[1005][1005];
int value[1005], volum[1005];
int bone, vol;
using namespace std;
int rec(int i,int j){

	if (dp[i][j] >= 0) return dp[i][j];
	int res;
	if (i == bone) res = 0;
	else if (volum[i] > j) res = rec(i + 1,j);
	else {res = max(rec(i + 1, j), rec(i + 1, j - volum[i]) + value[i]);}
	return dp[i][j] = res;
}
int main(){
	int n;
	scanf("%d",&n);
	while (n--){
		memset(dp, -1, sizeof(dp));
		scanf("%d%d",&bone, &vol);
		for (int i = 0; i < bone; ++i) scanf("%d",&value[i]);
		for (int i = 0; i < bone; ++i) scanf("%d",&volum[i]);
		printf("%d\n",rec(0,vol));
	}
	return 0;
}