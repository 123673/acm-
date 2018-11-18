/*

*/

#include<iostream>
#include<algorithm>
#include<cstring>
int dp[100010][20];
int input[100010][20];
using namespace std;
int main(){
	int n,m;
	int t, p;
	while (~scanf("%d", &n)&&n){ 
	   memset(dp, 0, sizeof(dp));
	   memset(input, 0, sizeof(input));
	   m = 0;
	   while (n--){
		scanf("%d%d",&p,&t);
		if (t > m) m = t;
		input[t][p]++;
	   }
	   for (int i = m; i >= 0; --i){
		    for (int j = 0; j <= 10; ++j){
			    dp[i][j]=input[i][j] + max(dp[i+1][j+1],max(dp[i+1][j-1],dp[i+1][j]));
		   }
	  }
	   printf("%d\n",dp[0][5]);
	}
}