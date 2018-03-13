#include <iostream>
#include <cstdio>
#include <cstring>
const int maxn = 5;

using namespace std;

int dirx[4] = {0, 0, 1, -1};
int diry[4] = {1, -1, 0, 0};
int find;
int maze[maxn][maxn];
struct node
{
	int x, y;
	int pre;
} p[1000];
void initMaze()
{
	memset(maze, 0, sizeof(maze));
}

bool legal(int i, int j)
{
	if (i >= 0 && i <= maxn - 1 && j >= 0 && j <= maxn - 1)
		return true;
	else
		return false;
}
void print(int t)
{
	if (p[t].pre == -1) return ;
	print(p[t].pre);
	printf("(%d, %d)\n", p[t].x, p[t].y);
	return ;
}

void bfs(int xx, int yy)
{
	p[0].x = xx;
	p[0].y = yy;
	p[0].pre =  -1;
	int front = 0, rear = 1;
	while (front < rear)
	{
		for (int i = 0; i < 4; ++i)
		{
			int tx = p[front].x + dirx[i];
			int ty = p[front].y + diry[i];
			if (legal(tx, ty) && maze[tx][ty] == 0)
			{
				maze[tx][ty] = 1;
				p[rear].x = tx;
				p[rear].y = ty;
				p[rear].pre = front;
				rear ++;
			}
			if (tx == 4 && ty == 4)
			{
				print(front);
				return ;
			}
		}
		front ++;
	}
	return;
}
int main()
{
	initMaze();
	for (int i = 0; i < maxn; ++i)
	{
		for (int j = 0; j < maxn; ++j)
		{
			scanf("%d", &maze[i][j]);
		}
	}
	printf("(0, 0)\n");
	bfs(0, 0);
	printf("(4, 4)\n");
	return 0;
}
