/*
floyd-warshell算法：求出任意两点之间最短路径的算法
复杂度：O（n^3）
*/
void washell(){
	for (int k = 0; k < v; ++k){
		for (int i = 0; i < v; ++i){
			for (int j = 0; j < v; ++j){
				d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
			}
		}
	}
}
/*求最短路径的路径保存方法：
在每一次路径更新时，将节点的钱去保存在pre[]数组中，之后从目标节点一直搜索到pre[]==s即可
*/