/*DP运用之最大公共子序列
Dp的原理就是求出递推公式，然后从底层开始把前面的项按照递推公式求出
最后退出所需要求出的值，此为DP的精髓
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[1005][1005];
char str[1005];
char str1[1005];
int main(){
	int m, n;
	scanf("%s%s",str, str1);
	memset(dp,0,sizeof(dp));
	int len = strlen(str);
	int len1 = strlen(str1);
	for (int i = 0; i < len; ++i){
		for (int j = 0; j < len1; ++j){
			if (str[i] == str1[j]){
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else{
				dp[i + 1][j + 1] = max(dp[i+1][j], dp[i][j+1]);
			}
		}
		
	}printf("%d\n",dp[len][len1]);
	system("pause");
	return 0;
}