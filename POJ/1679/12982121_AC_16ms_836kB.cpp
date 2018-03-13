#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 105;
const int INF = 0x3f3f3f3f;
int cost[MAXN][MAXN];
int lowcost[MAXN];
int MAX[MAXN][MAXN]; 	//MST 中i->j权值最大的边
int used[MAXN][MAXN];
int pre[MAXN];
int visit[MAXN];


int prim(int n){
	memset(used, 0, sizeof(used));
	memset(MAX, 0, sizeof(MAX));
	memset(visit, 0, sizeof(visit));
	for(int i = 1; i <= n; ++i) lowcost[i] = cost[1][i], pre[i] = 1;
	visit[1] = 1;
	pre[1] = -1;
	lowcost[1] = 0;
	int res1 = 0;	//最小生成树权值
	int res2 = INF;	//次小生成树权值
	for(int i = 2; i <= n; ++i)
	{
		int minc = INF;
		int flag = -1;
		for(int j = 1; j <= n; ++j){
			if(!visit[j] && minc > lowcost[j]){
				minc = lowcost[j];
				flag = j;
			}
		}
		if(flag == -1) return -1;
		res1 += minc;
		visit[flag] = 1;
		used[flag][pre[flag]] = used[pre[flag]][flag] = 1;
		for(int j = 1; j <= n; ++j)
		{
			if(visit[j]) MAX[j][flag] = MAX[flag][j] = max(MAX[j][flag], lowcost[flag]);
			if(!visit[j] && lowcost[j] > cost[flag][j])
			{ 
				lowcost[j] = cost[flag][j];
				pre[j] = flag;
			}
		}
	}
	
	for(int i = 1; i <= n; ++i)
		for(int j = i + 1; j <= n; ++j){
			//cout << i << " " << j << " " << used[i][j] << endl;
			if(cost[i][j] != INF && !used[i][j]){
				res2 = min(res2, res1 - MAX[i][j] + cost[i][j]);
			}
		}
	//cout << "r1 " << res1 << " r2 " << res2 << endl;
	if(res1 == res2) return -2;
	else return res1;
}

int main(){
	int t, n, m;
	scanf("%d", &t);
	while(t--){
		int a, b, c;
		scanf("%d%d", &n, &m);
		for(int i = 0; i < MAXN; ++i)
			for(int j = 0; j < MAXN; ++j) cost[i][j] = (i == j) ? 0 : INF;
		for(int i = 0; i < m; ++i)
		{
			scanf("%d%d%d", &a, &b, &c);
			if(cost[a][b] > c){
				cost[a][b] = cost[b][a] = c;
			}
		}
		int t = prim(n);
		if(t == -2) printf("Not Unique!\n");
		else printf("%d\n", t);
	}
	return 0;
}
