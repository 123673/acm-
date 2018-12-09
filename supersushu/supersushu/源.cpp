#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
bool isprime(int n){
	if (n == 0) return false;
	int sum = 0;
	for (int i = 1; i <= n / 2 + 1; ++i){
		if (n%i == 0) sum++;
	}
	if (sum == 1) return true;
	else return false;
}
int main(){
	char num[100];
	char str[100];
	int ssum = 0;
	int maxn = 0;
	int ssum1 = 0;
	if (isprime(0)) printf("Yes\n");
	for (int j = 100; j < 10000; ++j){
		 int sum = 0;
		 int sum1 = 1;
		 int sum2 = 0;
         sprintf(num,"%d",j);
		 int len = strlen(num);
		 for (int i = 0; i < len; ++i){
			 sum += num[i] - '0';
			 sum1 *= (num[i] - '0');
			 sum2 += (num[i] - '0')*(num[i] - '0');
	     }
		 if (isprime(sum) && isprime(sum1) && isprime(sum2)){
		          ssum++;
				  ssum1 += j;
				  maxn = max(maxn,j);
		 } 
	}
	printf("超级素数个数有%d个\n",ssum);
	printf("所有超级素数之和为：%d\n",ssum1);
	printf("最大的超级素数为%d\n",maxn);
	printf("\n");
	system("pause");
}


