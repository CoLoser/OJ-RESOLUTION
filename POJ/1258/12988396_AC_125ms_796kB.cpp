#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 105;
int cost[MAXN][MAXN];
int lowcost[MAXN];
int visit[MAXN];

int prim(int n){
	memset(visit, 0, sizeof(visit));
	for(int i = 1; i <= n; ++i) lowcost[i] = cost[1][i];
	visit[1] = 1;
	lowcost[1] = 0;
	int res = 0;
	for(int i = 2; i <= n; ++i)
	{
		int minc = INF;
		int flag = -1;
		for(int j = 1; j <= n; ++j)
		{
			if(!visit[j] && minc > lowcost[j]){
				minc = lowcost[j];
				flag = j;
			}
		}
		
		if(flag == -1) return -1;
		res += minc;
		visit[flag] = 1;
		
		for(int j = 1; j <= n; ++j){
			if(!visit[j] && lowcost[j] > cost[flag][j]){
				lowcost[j] = cost[flag][j];
			}
		}
	}
	return res;
}
int main(){
	int n;
	while(cin >> n)
	{
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)cin >> cost[i][j];
		cout << prim(n) << endl;
	}
	return 0;
}
