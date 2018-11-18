#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
char s1[2010], s2[2010], s[4020];
int dp[4020][4020];//表示s数组的前i项与s1数组的前j项是否可以构成s数组的前i+j项
int main(){
	while (~scanf("%s%s%s",s1, s2, s)){
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		int len = strlen(s);
		int len1 = strlen(s1);
		int len2 = strlen(s2);
		if (len != len1 + len2){
			printf("No\n"); 
			continue;
		} 
		for (int i = 0; i <= len1+1; ++i){
			for (int j = 0; j <= len2+1; ++j){
				if (s1[i] == s[i+j]&&dp[i][j]==1){
					dp[i+1][j] = 1;
				}
				if (s2[j]==s[i+j]&&dp[i][j]==1){
					dp[i][j+1]=1;
				}
			}
		}
		if (dp[len1][len2] == 1) printf("Yes\n");
		else printf("No\n");
	}


}