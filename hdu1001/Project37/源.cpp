#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	double  m;
	while (~scanf("%lf",&m)){
	   printf("%d\n\n", (int)(m*(m + 1) / 2));
	}
	return 0;
}