/*
kmp算法：
求出弄模式串在子串中的位置
kmp算法思路：
设i为母串中字符的位置，j为模式串中字符的位置，设T为母串，P为模式串，易得关系
当T[i]!=P[j]时
P[0~i-1] == T[i-j~i-1]
当
P[0~k-1] == P[i-k~i-1]（表示模式串的前k个数与其后K个数相同）
有上面两式可知：
P[0~k-1] == T[i-k~i-1]
所以只需要求出K的值下次匹配字符串从P[k]开始比较即可
设K = next[j-1]，他所表示的含义是模式串中第j为与子串的第i位不匹配时，前j位字符串中字符串前缀和后缀的最大相同子串
模板：
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

void getnext(char str[], int knext[]){ //求出next[]数组
	knext[0] = 0;
	int i = 0;
	int j = 1;
	int len = strlen(str);
	while (j < len ){
		if (str[i] == str[j]){ //如果字符相等母串和模式串的位置都加1
			knext[j] = knext[j - 1] + 1;//后一位字符串的最大相同前后缀大于前一位最大相同前后缀加1
			i++;
			j++;
		}
		else{//如果匹配到的字符不相同，则i从头开始，且将next[]数组设置为0
			knext[j] = 0;
			i = 0;
			j++;
		}
	}
}

void kmp(char t[],char p[], int knext[]){//算出模式串在母串中的位置
	int i = 0;
	int j = 0;
	int len1 = strlen(p);
	int len2 = strlen(t);
	while (j<len1&&i<len2){
		if (t[i] == p[j]){
			i++;
			j++;
		}
		else if(t[i]!=p[j]&&j > 0&&knext[j-1]!=0){
			j = knext[j-1];
		}
		else {
			i++;
			j = 0;
		}
	}
	printf("%s in the position %d of %s\n",p,i-len1,t);
}
int main(){
	char p[1000], t[1000];
	int knext[1000];
	scanf("%s%s", p, t);
	getnext(p,knext);
	for (int i = 0; i < strlen(p); ++i){
	    printf("%d ",knext[i]);
	}
	printf("\n");
	kmp(t,p,knext);
	system("pause");
}