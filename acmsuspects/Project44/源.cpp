#include<iostream>
#include<algorithm>
#define maxn 40005
using namespace std;
int fa[maxn];
void build(int n){
	for (int i = 1; i <= n; ++i){ fa[i] = i; }
}
int find(int x){ return fa[x] == x ? x : fa[x] = find(fa[x]); }
void merge(int x, int y){
	if (x < y) fa[y] = x;
	else fa[x] = y;
}
int main(){
	int m, n;
	while (~scanf("%d%d", &n, &m) && (m || n)){
		build(n);
		int sum = 0;
		while (m--){
			int k, a, b;
			scanf("%d%d", &k, &a);
			for (int i = 1; i < k; ++i){
				scanf("%d", &b);
				int f1 = find(a);
				int f2 = find(b);
				if (f1 != f2) merge(f1, f2);
			}
		}
		for (int i = 0; i <= n; ++i){
			if (find(i) == 0) sum++;
		}
		printf("%d\n", sum);
	}

}