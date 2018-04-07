#include <iostream>
#include <cstring>
#include <cstdio>
//hdu-2181 哈密顿绕行世界问题 
using namespace std;

const int MAXN = 30;
int G[MAXN][MAXN];
int visit[MAXN];
int path[MAXN];
int m, cnt;
void dfs(int start, int depth)
{
	if(depth == 20 && G[start][m] == 1)
	{
		cout << ++ cnt << ":  ";
		for(int i = 1; i <= 20; ++i) printf("%d ", path[i]);
		printf("%d\n", m);
		return ;
	}
	
	for(int i = 1; i <= 20; ++i)
	{
		if(!visit[i] && G[start][i] == 1)
		{
			visit[i] = 1;
			path[depth + 1] = i;
			dfs(i, depth + 1);
			visit[i] = 0;
		}
	}
	return ;
}
int main()
{
	int a, b, c;
	memset(G, 0, sizeof(G));
	for(int i = 1; i <= 20; ++i)
	{
		cin >> a >> b >> c;
		G[i][a] = G[i][b] = G[i][c] = 1;
	}
	while(cin >> m && m)
	{
		memset(visit, 0, sizeof(visit));
		visit[m] = 1;
		path[1] = m;
		cnt = 0;
		dfs(m, 1);
	}
	return 0;
}