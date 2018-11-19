#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int sum(int n){
	if (n <= 4) return n;
	else return sum(n-1)+sum(n-3);
}
int main(){
	int n;
	while (scanf("%d",&n)&&n){
		printf("%d\n",sum(n));
	}
}

