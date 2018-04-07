#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;

int dist[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
struct _Node{
	int x, y;
	_Node(){
	}
	_Node(int _x, int _y)
	{
		x = _x; y = _y;
	}
};

_Node path[10][10];
int maze[10][10];
int visit[10][10];
stack<_Node> s;

void INIT(){
	memset(maze, 1, sizeof(maze));
	memset(visit, 0, sizeof(visit));
}

void bfs(_Node start)
{
	queue<_Node> q;
	q.push(start);
	visit[start.x][start.y] = 1;
	path[start.x][start.y].x = path[start.x][start.y].y = -1;
	
	while(!q.empty())
	{
		_Node u = q.front(); q.pop();
		
		if(u.x == 5 && u.y == 5)
		{
			int x = u.x, y = u.y;
			while(path[x][y].x != -1 && path[x][y].y != -1)
			{
				s.push(path[x][y]);
				int xx = x;
				x = path[x][y].x;
				y = path[xx][y].y;
			}
			while(!s.empty())
			{
				printf("(%d, %d)\n", s.top().x - 1, s.top().y - 1);
				s.pop();
			}
			printf("(4, 4)\n");
		}
		
		for(int i = 0; i < 4; ++i){
			int dx = u.x + dist[i][0], dy = u.y + dist[i][1];
			
			if(!visit[dx][dy] && !maze[dx][dy])
			{
				q.push(_Node(dx, dy));
				visit[dx][dy] = 1;
				path[dx][dy].x = u.x;
				path[dx][dy].y = u.y;
			 } 
		}
	}
}
int main()
{
	INIT();
	for(int i = 1; i <= 5; ++i)
		for(int j = 1; j <= 5; ++j) cin >> maze[i][j];
	bfs(_Node(1, 1));
	return 0;
}