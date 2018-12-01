#include<iostream>
#include<algorithm>
#include<cstring>
const int maxn = 1000005;
using namespace std;
int n, m;
int t[maxn];
int p[10005];	int knext[10005];
void getnext(int p[], int knext[]){
	knext[0] = 0;
	int i = 0;
	int j = 1;
	while (j < m){
		if (p[i] == p[j]){
			knext[j] = knext[j - 1] + 1;
			i++;
			j++;
		}
		else{
			knext[j] = 0;
			i = 0;
			j++;
		}
	}
}

void kmp(int t[], int p[], int knext[]){
	int i = 0;
	int j = 0;
	while (i < n&&j < m){
		if (p[j] == t[i]){
			i++;
			j++;
		}
		else if (j > 0 && knext[j - 1]>0){
			j = knext[j - 1];
		}
		else{
			i++;
			j = 0;
		}
	}
	if (j == m) printf("%d\n", i - m + 1);
	else printf("%d\n", -1);
}
int main(){

	int k;

	scanf("%d", &k);
	while (k--){
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i){
			scanf("%d", &t[i]);
		}
		for (int i = 0; i < m; ++i){
			scanf("%d", &p[i]);
		}
		getnext(p, knext);
		kmp(t, p, knext);
	}
}