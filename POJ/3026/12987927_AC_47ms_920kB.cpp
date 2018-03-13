#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int SIZE = 60;
const int dist[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char maze[SIZE][SIZE];
int f[10000];
int cnt;

int getHash(int a, int b){
	return a*100 + b;
}

struct _Edge{
	int from, to, dist;
	_Edge(int _from, int _to, int _dist): from(_from), to(_to), dist(_dist){};
	_Edge(){};
};
_Edge edge[110*119];

struct _Node{
	int x, y, dist;
	_Node(){};
	_Node(int _x, int _y, int _dist): x(_x), y(_y), dist(_dist){};
};

void BFS_GETDIST(_Node beg){
	int visit[SIZE][SIZE];
	memset(visit, 0, sizeof(visit));
	visit[beg.x][beg.y] = 1;
	queue<_Node> q;
	q.push(beg);
	while(!q.empty())
	{
		_Node u = q.front(); q.pop();
		
		if(maze[u.x][u.y] == 'A' && getHash(beg.x, beg.y) != getHash(u.x, u.y)){
			edge[cnt].from = getHash(beg.x, beg.y);
			edge[cnt].to = getHash(u.x, u.y);
			edge[cnt++].dist = u.dist;
		}
		for(int i = 0; i < 4; ++i)
		{
			int dx = u.x + dist[i][0], dy = u.y + dist[i][1];
			
			if(maze[dx][dy] != '#' && !visit[dx][dy])
			{
				q.push(_Node(dx, dy, u.dist + 1));
				visit[dx][dy] = 1;
			}
		}
	}
}

bool cmp(_Edge e1, _Edge e2){
	return e1.dist < e2.dist;
}

int find(int x){
	return f[x] == -1 ? x : f[x] = find(f[x]);
}

int Kruskal(int n)
{
	memset(f, -1, sizeof(f));
	sort(edge, edge + cnt, cmp);
	//for(int i = 0; i < cnt; ++i) cout << "from: " << edge[i].from << " to: " << edge[i].to << " dist: " << edge[i].dist << endl;
	int res = 0;
	int p = 0;
	for(int i = 0; i < cnt; ++i){
		int a = find(edge[i].from);
		int b = find(edge[i].to);
		
		if(a != b){
			f[a] = b;
			p ++;
			res += edge[i].dist;
		}
		if(p == n - 1) break;
	}
	if(p < n - 1) return -1;
	else return res;
}
int main(){
	int t, row, col, n;
	char c;
	cin >> t;
	while(t--){
		scanf("%d%d\n", &row, &col);
		_Node start;
		n = 0;
		for(int i = 0; i < SIZE; ++i)
			for(int j = 0; j < SIZE; ++j) maze[i][j] = '#';
		for(int i = 1; i <= col; i++)
		{
			for(int j = 1; j <= row; ++j)
			{
				c = getchar();
				maze[i][j] = c;
				if(maze[i][j] == 'S'){
					start.x = i;
					start.y = j;
					start.dist = 0;
					n++;
				}
				if(maze[i][j] == 'A') n++;
			}
			getchar();
		}
		//cout <<"n = " << n << endl;
		cnt = 0;
		for(int i = 1; i <= col; ++i)
			for(int j = 1; j <= row; ++j) if(maze[i][j] == 'S' || maze[i][j] == 'A') BFS_GETDIST(_Node(i, j, 0));
		
		//for(int i = 0; i < cnt; ++i) cout << "from: " << edge[i].from << " to: " << edge[i].to << " dist: " << edge[i].dist << endl;
		int t = Kruskal(n);
		printf("%d\n", t);
	}
	return 0;
}
