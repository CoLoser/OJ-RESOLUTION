#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>


using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 250;
int f[MAXN];
int cnt;
int visit[MAXN*MAXN];

struct _Edge{
	int from, to, val;
	_Edge(){};
	_Edge(int _from, int _to, int _val): from(_from), to(_to), val(_val){};
};
_Edge edge[MAXN*MAXN];

bool cmp(_Edge e1, _Edge e2){
	return e1.val < e2.val;
}
int find(int x){
	return f[x] == -1 ? x : f[x] = find(f[x]);
}

void addEdge(int u, int v, int w){
	edge[cnt].from = u;
	edge[cnt].to = v;
	edge[cnt++].val = w;
}

void kruskal(int n, int m){
	memset(f, -1, sizeof(f));
	memset(visit, 0, sizeof(visit));
	sort(edge, edge+m, cmp);
	int res1 = 0, res2 = INF;
	
	//MST
	int p = 0;
	for(int i = 0; i < m; ++i){
		int a = find(edge[i].from);
		int b = find(edge[i].to);
		int val = edge[i].val;
		
		if(a != b){
			f[a] = b;
			res1 += val;
			visit[p++] = i;
		}
		if(p == n - 1) break;
	}
	if(p < n - 1){
		printf("No way");
		return ;
	}
	//cout << "res1 = " << res1 << endl;
	//ST
	
	for(int i = 0; i < m; ++i){
		memset(f, -1, sizeof(f));
		p = 0;
		int tmp = 0;
		for(int j = 0; j < m; ++j){
			if(visit[i] == j) continue;
			int a = find(edge[j].from);
			int b = find(edge[j].to);
			int val = edge[j].val;
			
			if(a != b){
				f[a] = b;
				tmp += val;
				p++;
			}
			if(p == n - 1) break;
		}
		//cout << res2 << "  " <<  tmp << endl;
		if(p == n - 1) res2 = min(res2, tmp);	
	}
	if(res2 == INF) printf("No second way");
	else printf("%d", res2);
	return ;
}

int main(){
	int t, n, m, u, v, w;
	cin >> t;
	for(int i = 1; i <= t; ++i){
		cin >> n >> m;
		cnt = 0;
		for(int j = 0; j < m; ++j){
			cin >> u >> v >> w;
			addEdge(u, v, w);
		}
		printf("Case #%d : ", i);
		kruskal(n, cnt);
		printf("\n");
	}
}
