#include<iostream>
#include<algorithm>
#include<cstring>
const int maxn = 1000005;
char t[maxn], p[10005];
int knext[10005];
void getnext(char p[], int knext[]){
	int len = strlen(p);
	int i = 0;
	int j = -1;
	knext[0] = -1;
	while (i < len){
		if (j == -1 || p[i] == p[j]){
			i++;
			j++;
			knext[i] = j;
		}
		else j = knext[j];
	}
}

void kmp(char t[], char p[], int knext[]){
	int sum = 0;
	int len = strlen(p);
	int len1 = strlen(t);
	int i = 0;
	int j = 0;
	while (i < len1){
		if (j == -1 || p[j] == t[i]){
			if (j == len - 1) sum++;
			i++;
			j++;
		}
		else j = knext[j];
	}
	printf("%d\n",sum);
}
int main(){

	int n;
	scanf("%d",&n);
	while (n--){
		scanf("%s%s",p,t);
		getnext(p,knext);
		kmp(t,p,knext);
	}
}