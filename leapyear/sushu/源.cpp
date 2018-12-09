#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
bool isleapyear(int n){
	if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0)
		return true;
	else return false;
}
int main(){
	int n;
	while (~scanf("%d", &n)){
		if (isleapyear(n)) printf("%d is leapyear\n",n);
		else printf("%d is not leapyear\n",n);
	}
	return 0;
}