#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 205;
int dist[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
struct _Node{
	int x, y, times;
	_Node(){
	}
	_Node(int _x, int _y, int _times)
	{
		x = _x; y = _y; times = _times;
	}
};
_Node yifenfei, merceki, kfc;

char maze[MAXN][MAXN];
int visit1[MAXN][MAXN];
int sumy[MAXN][MAXN], summ[MAXN][MAXN];
const int INF = 0x3f3f3f3f;

int n, m;

void bfs(_Node start, int sum[][MAXN]) 
{
	memset(visit1, 0, sizeof(visit1));
	queue<_Node> q1, q2;
	q1.push(start);
	visit1[start.x][start.y] = 1;
	while(!q1.empty())
	{
		_Node u1 = q1.front();
		q1.pop();

		for(int i = 0; i < 4; ++i)
		{
			int dx1 = u1.x + dist[i][0], dy1 = u1.y + dist[i][1];
			if(maze[dx1][dy1] != '#' && !visit1[dx1][dy1])
			{
				q1.push(_Node(dx1, dy1, u1.times + 1));
				visit1[dx1][dy1] = 1;
				if(maze[dx1][dy1] == '@') sum[dx1][dy1] = u1.times + 1;
			}
		}
	}
}

void INIT()
{
	memset(sumy, 0, sizeof(sumy));
	memset(summ, 0, sizeof(summ));
	for(int i = 0; i < MAXN; ++i)
		for(int j = 0; j < MAXN; ++j) maze[i][j] = '#';
}
int main()
{
	int n, m;
	while(cin >> n >> m)
	{
		INIT();
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= m; ++j)
			{
				cin >> maze[i][j];
				if(maze[i][j] == 'Y')yifenfei.x = i, yifenfei.y = j, yifenfei.times = 0;
				if(maze[i][j] == 'M')merceki.x = i, merceki.y = j, merceki.times = 0;
			}
		}
		bfs(yifenfei, sumy);
		bfs(merceki, summ);	
		
		int MIN = INF;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
				if(MIN > sumy[i][j] + summ[i][j] && sumy[i][j] && summ[i][j])
					MIN = sumy[i][j] + summ[i][j];
		printf("%d\n", MIN * 11);
	}
	return 0;
}