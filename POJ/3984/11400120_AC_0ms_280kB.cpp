#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
int visit[6][6];
int maze[6][6];
struct node{
	int x, y;
	int pre;
	node(int xx, int yy):x(xx), y(yy){
	}
	node(){
	}
};

queue<node> q;
node ans[1000];

void Print(int t)
{
	if(t == -1) return;
	Print(ans[t].pre);
	printf("(%d, %d)\n", ans[t].x, ans[t].y);
}
void bfs(int x, int y)
{
	q.push(node(x, y));
	ans[0].pre = -1;
	ans[0].x = x;
	ans[0].y = y;
	int rare = 1;
	int front = 0;
	while(!q.empty())
	{
		node t = q.front();
		q.pop();
		if(t.x == 4 && t.y == 4) Print(front);
		for(int i = 0; i < 4; ++i)
		{
			int dirx = t.x + dx[i];
			int diry = t.y + dy[i];
			
			if(dirx < 0 || dirx >= 5 || diry < 0 || diry >= 5) continue;
			if(maze[dirx][diry] == 0)
			{
				ans[rare].x = dirx;
				ans[rare].y = diry;
				ans[rare].pre = front;
				rare++;
				q.push(node(dirx, diry));
				maze[dirx][diry] = 1;
			}
		}
		front++;
	}
}
int main()
{
	memset(visit, 0, sizeof(visit));
	for(int i = 0; i < 5; ++i)
		for(int j = 0; j < 5; ++j)
			cin >> maze[i][j];
	bfs(0, 0);

	return 0;
}