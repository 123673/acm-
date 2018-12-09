#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
bool ishuiwen(char *p){
	char str[100];
	strcpy(str,p);
	strrev(p);
	if (strcmp(str, p) == 0) return true;
	else return false;
}

int main(){
	char str[100];
	while (~scanf("%s", str)){
		if (ishuiwen(str)){
            strrev(str);
			printf("%s is huiwen number\n", str);
		}
		else {
			strrev(str);
            printf("%s is not huiwen number\n", str);
		}
	}

}