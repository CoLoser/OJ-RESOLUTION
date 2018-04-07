#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 10;
char board[MAXN][MAXN];
bool visit[MAXN];
int ans;
int n, m, k;

void INIT()
{
	memset(visit, 0, sizeof(visit));
	for(int i = 0; i < MAXN; ++i)
		for(int j = 0; j < MAXN; ++j) board[i][j] = '.';
}

void dfs(int cur)	//cur 表示当前行 
{
	if(k == m)
	{
		ans ++;
		return ;
	}
	
	if(cur > n) return ;
	for(int i = 1; i <= n; ++i)
	{
		if(!visit[i] && board[cur][i] == '#')
		{
			visit[i] = 1;
			k ++;
			dfs(cur + 1);
			k --;
			visit[i] = 0;
		}
	}
	dfs(cur + 1);
}

int main()
{
	while(cin >> n >> m && n != -1 && m != -1)
	{
		INIT();
		ans = 0;
		k = 0;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j) cin >> board[i][j];
		dfs(0);
		printf("%d\n", ans);	
	 } 
}