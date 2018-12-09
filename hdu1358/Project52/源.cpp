/*
题目：hdu 1358

Problem Description

For each prefix of a given string S with N characters (each character has an ASCII code
between 97 and 126, inclusive), we want to know whether the prefix is a periodic string.
That is, for each i (2 <= i <= N) we want to know the largest K > 1 (if there is one)
such that the prefix of S with length i can be written as AK , that is A concatenated K 
times, for some string A. Of course, we also want to know the period K.

Input

The input file consists of several test cases. Each test case consists of two lines. 
The first one contains N (2 <= N <= 1 000 000) – the size of the string S. The second 
line contains the string S. The input file ends with a line, having the number zero on 
it.


 


Output

For each test case, output “Test case #” and the consecutive test case number on a 
single line; then, for each prefix with length i that has a period K > 1, output the
prefix size i and the period K separated by a single space; the prefix sizes must be 
in increasing order. Print a blank line after each test case.

Sample Input

3
aaa
12
aabaabaabaab
0
题意：给出一个长度为N的字符串 求出他的所有的周期前缀，并且求出该周期前缀的循环节个数的最大值
题型：kmp算法的next[]数据组的运用
解法：已知题意是求解中欧琪前缀及其最大循环节，设变量j = i-next[i],则如果i%j==0的话，就表示字符串的前i
个字符是N的一个周期前缀，且此时j表示该周期前缀的最小循环节的长度，则i/j表示循环节的个数的最大值
*/

#include<iostream>
#include<cstring>
#include<algorithm>
char p[1000010];
int knext[1000010];
using namespace std;
void getnext(int n) {
	int j = -1;
	int i = 0;
	knext[0] = -1;
	while (i < n){
		if (j == -1 || p[i] == p[j]){
			i++;
			j++;
			knext[i] = j;
		}
		else j = knext[j];
	}
}

int main(){
    int k = 1;
	int n;
	while (scanf("%d", &n) && n){
           scanf("%s", p);
		   printf("Test case #%d\n",k++);
	       getnext(n);
		   for (int i = 2; i <= n; ++i){
			   if (i % (i - knext[i]) == 0 && i - knext[i] != i){
				   printf("%d %d\n",i,i/(i-knext[i]));
			   }
		   }
		   printf("\n");
	}
	system("pause");
	return 0;
}