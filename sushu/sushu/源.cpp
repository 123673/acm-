#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
bool isprime(int n){
	int sum = 0;
	for (int i = 1; i <= n / 2 + 1; ++i){
		if (n%i == 0) sum ++ ;
	}
	if (sum == 1) return true;
	else return false;
}
int main(){
	int n;
	while (~scanf("%d", &n)){
		if (isprime(n)) printf("%d is prime\n",n);
		else printf("%d is not prime\n",n);
	}
	return 0;
}