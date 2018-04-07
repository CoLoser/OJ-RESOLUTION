#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef unsigned long long ull;
int visit;
void dfs(ull n, int m, int k)
{
	if(visit) return;
	if(n % m == 0)
	{
		printf("%I64u\n", n);
		visit = 1;
		return ;
	}
	if(k == 19) return;
	
	dfs(n*10, m, k+1);
	dfs(n*10 + 1, m, k + 1);
}
int main()
{
	int t;
	while(scanf("%d", &t) != EOF && t)
	{
		visit = 0;
		dfs(1, t, 0);
	}
	return 0;
 } 