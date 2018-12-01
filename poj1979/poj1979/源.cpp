/*
ÌâÄ¿;Red and Black
There is a rectangular room, covered with square tiles. Each tile is colored either red or black. A man is standing on
a black tile. From a tile, he can move to one of four adjacent tiles. But he can't move on red tiles, he can move only 
on black tiles.

Write a program to count the number of black tiles which he can reach by repeating the moves described above.
Input
The input consists of multiple data sets. A data set starts with a line containing two positive integers W and H; W and
H are the numbers of tiles in the x- and y- directions, respectively. W and H are not more than 20.

There are H more lines in the data set, each of which includes W characters. Each character represents the color of a tile
as follows.

'.' - a black tile
'#' - a red tile
'@' - a man on a black tile(appears exactly once in a data set)
The end of the input is indicated by a line consisting of two zeros.
Output
For each data set, your program should output a line which contains the number of tiles he can reach from the initial
tile (including itself).
Sample Input
6 9
....#.
.....#
......
......
......
......
......
#@...#
.#..#.
11 9
.#.........
.#.#######.
.#.#.....#.
.#.#.###.#.
.#.#..@#.#.
.#.#####.#.
.#.......#.
.#########.
...........
11 6
..#..#..#..
..#..#..#..
..#..#..###
..#..#..#@.
..#..#..#..
..#..#..#..
7 7
..#.#..
..#.#..
###.###
...@...
###.###
..#.#..
..#.#..
0 0
Sample Output
45
59
6
13
*/


#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int x[4] = { 0, 0, -1, 1 };
int y[4] = { -1, 1, 0, 0 };
int vis[25][25];
char blk[25][25];
int num;
int m, n;
void dfs(int i ,int j){
	vis[i][j] = 1;
	for (int k = 0; k < 4; ++k){
		int ex = i + x[k];
		int ey = j + y[k];
		if (vis[ex][ey] == 0 && ex < m&&ex>=0&&ey>=0&&ey < n&&blk[ex][ey] =='.'){
			num++;
			dfs(ex, ey);
		}
	}
}
int main(){
	
	while (~scanf("%d%d", &n, &m)){
		if (m == 0 && n == 0){
			break;
		}
		num = 1;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < m; ++i){
			scanf("%s",blk[i]);
		}
		for (int i = 0; i < m; ++i){
			for (int j = 0; j < n; ++j){
				if (blk[i][j]=='@'){
					dfs(i, j);
				}
			}
		}
		printf("%d\n",num);
	}
	system("pause");
}