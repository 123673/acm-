#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	double m[105];
	double sum = 0;
	double n;
	scanf("%lf",&n);
	for (int i = 0; i < n;++i){
		scanf("%lf", &m[i]);
	}
	for (int i = 0; i < n; ++i){
		for (double j = 1; j <= m[i]; ++j){ 
			sum += pow(-1, j + 1) / j;
		}
		printf("%.2lf\n",sum);
		sum = 0;
	}
	system("pause");
}