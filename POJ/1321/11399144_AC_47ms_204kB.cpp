#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn = 9;
char map[maxn][maxn];
int visit[maxn];
int n, k;
int ans;
int idx = 0;

void dfs(int p)
{
	if(idx == k)
	{
		ans ++;
		return ;
	}
	
	if(p >= n ) return ;
	
	for(int i = 0; i < n; ++i)
	{
		if(!visit[i] && map[p][i] == '#')
		{
			visit[i] = 1;
			idx ++;
			
			dfs(p+1);
			
			idx --;             //还原计数器;
			visit[i] = 0;       //还原标记;
		}
	}
	
	dfs(p + 1);  //当 k < n 时, 多余行的处理
}
int main()
{
    while(scanf("%d%d", &n, &k) != EOF)
    {
    	if(n == -1 || k == -1) break;
    	memset(visit, 0, sizeof(visit));
    	ans = 0; idx = 0;
    	for(int i = 0; i < n; ++i) scanf("%s", &map[i]);
    	dfs(0);
    	printf("%d\n",ans);
	}
	return 0;
}