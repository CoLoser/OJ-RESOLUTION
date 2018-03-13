#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct _Edge{
	int from, to;
	int value;
};
const int MAXN = 2505;
const int MAXV = 505;
const int INF = 0x3f3f3f;
_Edge edges[MAXN<<1];
int dis[MAXV];
int n, m, p;

bool bellman_Ford(int len)
{
	memset(dis, INF, sizeof(dis));
	dis[1] = 0;

	bool flag;

	for(int i = 1; i <= n; ++i)
	{
		flag = true;
		for(int j = 0; j < len; ++j)
		{
			if(dis[edges[j].to] > dis[edges[j].from] + edges[j].value)
			{
				dis[edges[j].to] = dis[edges[j].from] + edges[j].value;
				flag = false;
			}
		}
		if(flag) return false;
	}

	return true;
}
int main()
{
	int t;
	int a, b, c;
	int cnt = 0;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d%d", &n, &m, &p);
		cnt = 0;
		for(int i = 0; i < m; ++i)
		{
			scanf("%d%d%d", &a, &b, &c);
			edges[cnt].from = a;
			edges[cnt].to = b;
			edges[cnt++].value = c;
			edges[cnt].from = b;
			edges[cnt].to = a;
			edges[cnt++].value = c;
		}

		for(int i = m; i < p + m; ++i)
		{
			scanf("%d%d%d", &a, &b, &c);
			edges[cnt].from = a;
			edges[cnt].to = b;
			edges[cnt++].value = -c;
		}
			
		printf("%s\n", bellman_Ford(cnt) ? "YES" : "NO");
	}
	return 0;
}