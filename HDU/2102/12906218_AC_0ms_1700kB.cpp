#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int n, m, t;
const int MAXN = 15;
char maze[5][MAXN][MAXN];
int visit[5][MAXN][MAXN];

//int dist[6][3] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}}; 
int dist[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
struct _Node{
	int x, y, z, times;
	
	_Node(){
	}
	_Node(int _x, int _y, int _z, int _times)
	{
		x = _x; y = _y; z = _z; times = _times;
	}
};


void bfs()
{
	queue<_Node> q;
	q.push(_Node(1, 1, 1, 0));
	visit[1][1][1] = 1;
	
	while(!q.empty())
	{
		_Node u = q.front(); q.pop();
		//cout << u.x << " " << u.y << " " << u.z << " " << u.times  << " " << t << " "<< maze[u.z][u.x][u.y] << endl;
		if(maze[u.z][u.x][u.y] == 'P' && t >= u.times)
		{
			printf("YES\n");
			return ;
		} 
		
		for(int i = 0; i < 4; ++i)
		{
			int dx = u.x + dist[i][0], dy = u.y + dist[i][1], dz = u.z;
					
			if(maze[dz][dx][dy] == '#')
			{
				if(dz == 1) dz = 2;
				else if(dz == 2) dz = 1;
			}
			if(maze[dz][dx][dy] == '*') continue;
			if(visit[dz][dx][dy]) continue;
			
			q.push(_Node(dx, dy, dz, u.times + 1));
			visit[dz][dx][dy] = 1;
		}
	}
	printf("NO\n");
}
void INIT()
{
	for(int k = 0; k < 5; ++k)
		for(int i = 0; i < MAXN; ++i)
			for(int j = 0; j < MAXN; ++j) maze[k][i][j] = '*';
}
int main()
{
	int x;
	cin >> x;
	while(x--)
	{
		INIT();
		memset(visit, 0, sizeof(visit));
		cin >> n >> m >> t;
		for(int k = 1; k <= 2; ++k)
			for(int i = 1; i <= n; ++i)
				for(int j = 1; j <= m; ++j)
				{
					cin >> maze[k][i][j]; 
				} 
		for(int k = 1; k <= 2; ++k)
			for(int i = 1; i <= n; ++i)
				for(int j = 1; j <= m; ++j)
				{
					if((maze[1][i][j] == '#' && maze[2][i][j] == '#') || (maze[1][i][j] == '#' && maze[2][i][j] == '*') || (maze[2][i][j] == '#' && maze[1][i][j] == '*'))  
                    {  
                        maze[1][i][j] = '*';
                        maze[2][i][j] = '*';  
                    }
				} 
		bfs();
	}
} 