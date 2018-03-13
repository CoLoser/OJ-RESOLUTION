#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 105;
const int MAXM = 105 * 104;

struct _Edge{
	int from, to;
	double dist;
	_Edge(){};
	_Edge(int _from, int _to, double _dist): from(_from), to(_to), dist(_dist){};
};
struct _Node{
	double x, y;
	_Node(){};
	_Node(double _x, double _y): x(_x), y(_y){};
};

_Node node[MAXN];
_Edge edge[MAXM];
int f[MAXN];

bool cmp(_Edge e1, _Edge e2){
	return e1.dist < e2.dist;
}
int find(int x){
	return f[x] == -1 ? x : f[x] = find(f[x]);
}
double Kruskal(int cnt, int n){
	memset(f, -1, sizeof(f));
	sort(edge, edge + cnt, cmp);
	double res = 0;
	int t = 0;
	for(int i = 0; i < cnt; ++i){
		int a = find(edge[i].from);
		int b = find(edge[i].to);
		if(a != b){	
			f[a] = b;
			res += edge[i].dist;
			t++;
		}
		if(t == n - 1) break;
	}
	if(t < n - 1) return -1;
	else return res;
}
double getDist(int i, int j)
{
	double dx = node[i].x - node[j].x;
	double dy = node[i].y - node[j].y;	
	return sqrt(dx*dx + dy*dy);
}

int main(){
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		int cnt = 0;
		for(int i = 0; i < n; ++i) cin >> node[i].x >> node[i].y;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
			{
				if(i != j)
				{
					double dist = getDist(i, j);
					if(dist <= 1000 && dist >= 10){
						edge[cnt].from = i;
						edge[cnt].to = j;
						edge[cnt++].dist = dist*100;
					}
				}
			}
		double tmpx = Kruskal(cnt, n);
		if(tmpx == -1) printf("oh!\n");
		else printf("%.1lf\n", tmpx);
	}
	return 0;
}
