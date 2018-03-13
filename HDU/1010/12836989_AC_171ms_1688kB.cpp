#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

const int MAXN = 10;
char maze[MAXN][MAXN];

int dfs(int x, int y, int t)
{
	if(maze[x][y] != '.' && maze[x][y] != 'S') return 0;
	
	if(t == 1)
	{
		if(maze[x][y-1] == 'D') return 1;
		if(maze[x][y+1] == 'D') return 1;
		if(maze[x-1][y] == 'D') return 1;
		if(maze[x+1][y] == 'D') return 1; 
	}
	else{
		maze[x][y] = 'X';
		
		if(maze[x][y-1] == '.' && dfs(x, y-1, t-1)) return 1;
		if(maze[x][y+1] == '.' && dfs(x, y+1, t-1)) return 1;
		if(maze[x-1][y] == '.' && dfs(x-1, y, t-1)) return 1;
		if(maze[x+1][y] == '.' && dfs(x+1, y, t-1)) return 1;
		
		maze[x][y] = '.';
		return 0;
	}
	return 0;
}
int main()
{
	int n, m, t;
	
	int sx, sy, dx, dy;
	
	while(scanf("%d%d%d", &n, &m, &t) != EOF)
	{
		if(n == 0 && m == 0 && t == 0) break;
		memset(maze, 'X', sizeof(maze));
		getchar();
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= m; ++j)
			{
				cin >> maze[i][j];
				if(maze[i][j] == 'S')
				{
					sx = i;
					sy = j;				
				}else if(maze[i][j] == 'D')
				{
					dx = i;
					dy = j;		
				}
			}
			getchar();
		}
		
		
		if((abs(sx - dx) + abs(sy - dy) - t) & 1)
		{
			printf("NO\n");
		}else if(dfs(sx, sy, t)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
 } 