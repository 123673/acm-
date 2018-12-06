#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
	char m[1005], n[1005];
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k){
		scanf("%s%s", m, n);
		printf("Case %d:\n", k);
		printf("%s + %s = ", m, n);
		int len = strlen(m);
		int len1 = strlen(n);
		strrev(m);
		strrev(n);
		int xmin = min(len, len1);
		int car = 0;
		int temp;
		for (int i = 0; i < xmin; ++i){
			if (len>len1){
				temp = m[i] + n[i] + car - '0' - '0';
				m[i] = (temp) % 10 + '0';
				car = temp / 10;
				if (i == xmin - 1){
					m[i + 1] = m[i + 1] + car;
					strrev(m);
					printf("%s\n", m);
					if (k<t) printf("\n");
				}
			}
			else if (len<len1){
				temp = m[i] + n[i] + car - '0' - '0';
				n[i] = temp % 10 + '0';
				car = temp / 10;
				if (i == xmin - 1) {
					n[i + 1] = n[i + 1] + car;
					strrev(n);
					printf("%s\n", n);
					if (k<t) printf("\n");
				}
			}
			else{
				temp = m[i] + n[i] + car - '0' - '0';
				m[i] = temp % 10 + '0';
				car = temp / 10;
				if (i == xmin - 1 && car == 1) {
					m[i + 1] = 1 + '0';
					strrev(m);
					printf("%s\n", m);
					if (k<t) printf("\n");
				}
				if (i == xmin - 1 && car == 0){
					strrev(m);
					printf("%s\n", m);
					if (k<t) printf("\n");
				}
			}
		}
	}
	system("pause");
}