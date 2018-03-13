#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 20;
int prime[MAXN<<1];
int ans[MAXN];
int visit[MAXN];

int n;

void solve()
{
	memset(prime, 1, sizeof(prime));
	for(int i = 2; i < MAXN*2; ++i) if(prime[i])
		for(int j = i * i; j < MAXN*2; j += i) prime[j] = 0;
}

void Print()
{
	for(int i = 1; i <= n; ++i)
		printf("%d%c", ans[i], (i == n) ? '\n' : ' ');
}
void dfs(int cnt)
{
	if(cnt == n)
	{
		if(prime[ans[cnt] + ans[1]]) Print();
	}else{
		for(int i = 2; i <= n; ++i)
			if(!visit[i] && prime[i + ans[cnt]])
			{
				ans[cnt + 1] = i;
				visit[i] = 1;
				dfs(cnt+1);
				visit[i] = 0;
			}
	}
}
int main()
{
	solve();
	int kase = 0;
	while(scanf("%d", &n) != EOF)
	{
		printf("Case %d:\n", ++kase);
		memset(visit, 0, sizeof(visit));
		ans[1] = 1;
		visit[1] = 1;
		
		dfs(1);
		printf("\n");
	}
}