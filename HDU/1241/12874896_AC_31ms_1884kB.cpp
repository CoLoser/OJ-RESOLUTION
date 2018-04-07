#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

//求连通块

const int MAXN = 100;
char maze[MAXN + 5][MAXN + 5];
int n, m;
int dist[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};
int visit[MAXN + 5][MAXN + 5];

bool isleagl(int x, int y)
{
	if(x >= 0 && x < n && y >= 0 && y < m) return 1;
	else return 0; 
}

void dfs(int x, int y, int id)
{
	if(!isleagl(x, y))	return ;
	if(maze[x][y] != '@' || visit[x][y] > 0) return ;
	visit[x][y] = id;
	
	for(int i = 0; i < 8; ++i)
	{
		dfs(x + dist[i][0], y + dist[i][1], id);
	}
}


int main()
{
	while(cin >> n >> m && n && m)
	{
		memset(visit, 0, sizeof(visit));
		int cnt = 0;
		for(int i = 0; i < n; ++i) cin >> maze[i];
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)if(visit[i][j] == 0 && maze[i][j] == '@') dfs(i, j, ++cnt);
		cout << cnt << endl;		
	}
} 