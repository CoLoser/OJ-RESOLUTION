#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXN = 800;
int f[MAXN];
struct _Node{
	double x, y;
	_Node(){};
	_Node(double _x, double _y): x(_x), y(_y){};
};
_Node node[MAXN];
struct _Edge{
	int from, to;
	double dist;
	_Edge(){};
	_Edge(int _from, int _to, int _dist): from(_from), to(_to), dist(_dist){};
};
_Edge edge[MAXN*(MAXN - 1)];

bool cmp(_Edge e1, _Edge e2){
	return e1.dist < e2.dist;
}

int find(int x){
	return f[x] == -1 ? x : f[x] = find(f[x]);
}

void Kruskal(int cnt, int n){
	sort(edge, edge + cnt, cmp);
	for(int i = 0; i < cnt; ++i){
		int x = find(edge[i].from);
		int y = find(edge[i].to);
		
		if(x != y){
			f[x] = y;
			printf("%d %d\n", edge[i].from, edge[i].to);
		}
	}
}

double getDist(int i, int j){
	double dx = node[i].x - node[j].x;
	double dy = node[i].y - node[j].y;
	return sqrt(dx*dx + dy*dy);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, t, cnt;
	int a, b;
	while(scanf("%d", &n) != EOF){
		for(int i = 1; i <= n; ++i) scanf("%lf%lf", &node[i].x, &node[i].y);
		
		cnt = 0;
		for(int i = 1; i < n; ++i)
			for(int j = i + 1; j <= n; ++j){
				edge[cnt].from = i;
				edge[cnt].to = j;
				edge[cnt++].dist = getDist(i, j);
			}
		memset(f, -1, sizeof(f));
		scanf("%d", &t);
		for(int i = 0; i < t; ++i){
			scanf("%d%d", &a, &b);
			int x = find(a);
			int y = find(b);
			if(x != y)
			{
				f[x] = y;
			}
		}
		Kruskal(cnt, n - t);
	}
	return 0;
}
