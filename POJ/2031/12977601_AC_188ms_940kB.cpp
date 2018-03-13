
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

struct _Node{
	double x, y, z, r;
	_Node(){}
	_Node(double _x, double _y, double _z, double _r): x(_x), y(_y), z(_z), r(_r){};
};

struct _Edge{
	int from, to;
	double dist;
	_Edge(){};
	_Edge(int _from, int _to, double _dist): from(_from), to(_to), dist(_dist){};
};
const int MAXN = 105;
const int MAXM = 105*104;
int f[MAXN];
_Edge edge[MAXM];
_Node node[MAXN];

int find(int x){
	return f[x] == -1 ? x : f[x] = find(f[x]); 
}

bool cmp(_Edge e1, _Edge e2){
	return e1.dist < e2.dist;
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

double getDist(int i, int j){
	double dx = node[i].x - node[j].x;
	double dy = node[i].y - node[j].y;
	double dz = node[i].z - node[j].z;
	double dist = sqrt(dx*dx + dy*dy + dz*dz);
	double t = dist - node[i].r - node[j].r;
	if(t <= 0) return 0;
	else return t;
}
int main(){
	int n;
	while(cin >> n && n){
		for(int i = 0; i < n; ++i) cin >> node[i].x >> node[i].y >> node[i].z >> node[i].r;
		int cnt = 0;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j) {
				if(i != j){
					edge[cnt].from = i;
					edge[cnt].to = j;
					edge[cnt++].dist = getDist(i, j);
				}
			}
		printf("%.3f\n", Kruskal(cnt, n));
	}
	return 0;
}
