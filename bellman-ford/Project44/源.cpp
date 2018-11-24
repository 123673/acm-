/*
bellaan算法;求DAG图的单源最短路径
题意：给出一个DAG（无圈的图），求出其中一个点到任意另一个点的最短的路径
*/
#include<iostream>
#include<algorithm>
#include<cstring>
const int INF = 100000000;
using namespace std;
int v, e, s, ed;
struct edge{
	int from;
	int to;
	int cost;
}es[1005];
int d[1005];
void short_path(int s){
	d[s] = 0;
	while (1){
		bool judge = false;
        for (int i = 0; i < e; ++i){
		    edge ew = es[i];
		    if (d[ew.from]!=INF&&(d[ew.to] > d[ew.from]+ew.cost)){
			     d[ew.to] = d[ew.from] + ew.cost;
			     judge = true;
		     }
	       }
	if (!judge) break;
	}
}
int main(){
	scanf("%d%d%d%d",&v,&e,&s,&ed);
	for (int i = 0; i < 1000; ++i) d[i] = INF;
	for (int i = 0; i < e; ++i){
		scanf("%d%d%d",&es[i].from, &es[i].to, &es[i].cost);
	}
	short_path(s);
	printf("%d\n",d[ed]);
	system("pause");
}