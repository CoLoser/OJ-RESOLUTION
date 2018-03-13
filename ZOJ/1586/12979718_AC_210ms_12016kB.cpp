
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

struct _Edge{
	int from, to, dist;
	_Edge(int _from, int _to, int _dist): from(_from), to(_to), dist(_dist){};
	_Edge(){};
};
const int MAXN = 1000;
const int MAXM = 1000000;
_Edge edge[MAXM];
int f[MAXN];
int cost[MAXN];

bool cmp(_Edge e1, _Edge e2){
	return e1.dist < e2.dist;
}

int Find(int x){
	return f[x] == -1 ? x : f[x] = Find(f[x]); 
}

int Kruskal(int cnt, int n){
	memset(f, -1, sizeof(f));
	sort(edge, edge + cnt, cmp);
	int t = 0;
	int res = 0;
	for(int i = 0; i < cnt; ++i){
		int x = Find(edge[i].from);
		int y = Find(edge[i].to);
		//cout << "x " << x << " y " << y << endl;
		if(x != y){
			f[x] = y;
			res += edge[i].dist;
			t++;
		}
		if(t == n - 1) break;
	}
	if(t < n - 1) return -1;
	else return res;
}
int main(){
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1; i <= n; ++i) cin >> cost[i];
		
		int x;
		int cnt = 0;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
			{
				cin >> x;
				if(i != j){
					edge[cnt].from = i;
					edge[cnt].to = j;
					edge[cnt].dist = x + cost[i] + cost[j];
					//cout << i << " " << j << " " << edge[cnt].dist << endl;
					cnt ++;
				}
			}
		cout << Kruskal(cnt, n) << endl;
	}
	return 0;
}
