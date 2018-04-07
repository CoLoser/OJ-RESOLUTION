#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
//#include <bits/stdc++.h>
using namespace std;
int idist[6][3] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}}; //上下左右前后
const int MAXN = 30;
char maze[MAXN + 2][MAXN + 2][MAXN + 2];
int visit[MAXN + 2][MAXN + 2][MAXN + 2];
struct _Node{
	int x, y, z;
	int t;
	
	_Node(){
	}
	_Node(int _x, int _y, int _z, int _t){
		x = _x; y = _y; z = _z; t = _t;
	}
};
int n, m, p;

void INIT()
{
	for(int i = 0; i < MAXN + 2; ++i)			
		for(int j = 0; j < MAXN + 2; ++j)			
			for(int k = 0; k < MAXN + 2; ++k)
				maze[i][j][k] = '#';		
	memset(visit, 0, sizeof(visit));
}

int bfs(_Node start){
	queue<_Node> q;
	q.push(start);
	visit[start.z][start.x][start.y] = 1;
	
	while(!q.empty())
	{
		_Node u = q.front();
		q.pop();
		
		for(int i = 0; i < 6; ++i)
		{
			int dx = u.x + idist[i][0], dy = u.y + idist[i][1], dz = u.z + idist[i][2];
			
			//cout << dz << " " << dx << " " << dy << endl; 
			if(!visit[dz][dx][dy] && maze[dz][dx][dy] != '#')
			{
				visit[dz][dx][dy] = 1;
				
				q.push(_Node(dx, dy, dz, u.t + 1));
			}
			
			if(maze[dz][dx][dy] == 'E') return u.t + 1;
		}
	}
	return -1;
}
int main()
{
	while(scanf("%d%d%d", &n, &m, &p) != EOF && n && m && p)
	{
		INIT();
		_Node start;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
				for(int k = 1; k <= p; k ++){
					cin >> maze[i][j][k];
					if(maze[i][j][k] == 'S'){
						start.x = j;
						start.y = k;
						start.z = i;
						start.t = 0;
					}
				}
		
		//cout << start.z <<" " <<start.x << " " << start.y<< endl;
		int t = bfs(start);
		
		if(t == -1) printf("Trapped!\n");
		else printf("Escaped in %d minute(s).\n", t);		
	}
	return 0;
}