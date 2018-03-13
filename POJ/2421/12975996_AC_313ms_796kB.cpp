#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 105;
const int INF = 0x3f3f3f3f;
int cost[MAXN][MAXN];
int lowcost[MAXN];
int visit[MAXN];
int n, m;

int prim(){
	memset(visit, 0, sizeof(visit));
	for(int i = 1; i <= n; ++i)lowcost[i] = cost[1][i];
	visit[1] = 1;
	lowcost[1] = 0;
	int res = 0;
	for(int i = 2; i <= n; ++i){
		int MIN = INF;
		int flag = -1;
		for(int j = 1; j <= n; ++j){
			if(!visit[j] && MIN > lowcost[j]){
				MIN = lowcost[j];
				flag = j;
			} 
		}
		if(flag == -1) return -1;
		visit[flag] = 1;
		res += MIN;
		for(int j = 1; j <= n; ++j){
			if(!visit[j] && lowcost[j] > cost[flag][j]) lowcost[j] = cost[flag][j];
		}
	}
	return res;
}

int main(){
	while(cin >> n){
		for(int i = 0; i <= MAXN; ++i)
			for(int j = 0; j <= MAXN; ++j) cost[i][j] = (i == j) ? 0 : INF;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j) cin >> cost[i][j];
		int q, a, b;
		cin >> q;
		while(q--){
			cin >> a >> b;
			cost[a][b] = cost[b][a] = 0;
		}
		
		cout << prim() << endl;
	}
	return 0;
}
