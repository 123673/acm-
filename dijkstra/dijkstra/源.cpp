/*
dijkstra算法：一种高效的计算单源最短路径的方法：
与bellman-ford算法不同的是，此法使用邻接矩阵实现,比bellman-ford 算法更加高效，但是只能用于DAG图上
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int INF = 100000000;
int v, e, s, ed;
int from, to;
int d[10000];
int cost[10000][10000];
int used[10000];
void short_path(){
	while (1){
		int ve = -1;
		for (int i = 1; i <= v; ++i){
			if (!used[i] && (ve == -1 || d[ve] > d[i])) ve = i;
		}
		if (ve == -1) break;
		used[ve] = true;
		for (int i = 1; i <= v; ++i){
			d[i] = min(d[i], d[ve] + cost[ve][i]);
		}
	}
}
int main(){
	scanf("%d%d%d",&v, &s, &ed);
	//fill(d,d+v,INF);
	//fill(used,used+v,false);
	memset(used, 0,sizeof(used));
	for (int i = 1; i <= v; ++i) d[i] = INF;
	d[s] = 0;
	for (int i = 1; i <= v; ++i){
	  for (int j = 1; j <= v; ++j) cost[i][j] = INF;
	}
	 
	for (int i = 1; i <= v; ++i){
		scanf("%d%d",&from, &to);
		scanf("%d", &cost[from][to]);
	}
	short_path();
	printf("%d\n",d[ed]);
	system("pause");
}