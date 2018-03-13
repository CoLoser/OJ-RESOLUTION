#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 20;
int map[MAXN][MAXN];
int visit[MAXN];
int ans;
int n;

void dfs(int t, int ltime, int cnt)
{
	ans = max(ans, cnt);
	if(ans == n) return ;
	
	for(int i = 1; i < n; ++i)
	{
        if(!visit[i] && map[t][i] >= ltime)
        {
        	visit[i] = 1;
        	dfs(i, map[t][i], cnt + 1);
        	visit[i] = 0;
		}
	}
}

int main()
{
	while(scanf("%d", &n) != EOF)
	{
		memset(visit, 0, sizeof(visit));
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				scanf("%d", &map[i][j]);

		visit[0] = 1;
		ans = 0;
		dfs(0, 0, 1);
		
		printf("%d\n", ans);
	}
	return 0;
}