#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1005;
char map[MAXN][MAXN];
int cnt = 0;

char p1[] = "girl";
char p2[] = "cat";

void dfs(int row, int col, char* p)
{
	if(map[row][col] == *p)
	{
		if(*(p+1) == '\0')
			cnt++;
		else{
			p++;
			dfs(row-1, col, p);
			dfs(row, col+1, p);
			dfs(row+1, col, p);
			dfs(row, col-1, p);
		}
	}
}

int main()
{
	int t;
	int n, m;
	scanf("%d", &t);
	while(t--)
	{
		memset(map, 0, sizeof(map));
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; ++i)
			scanf("%s", map[i] + 1);

		cnt = 0;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
				dfs(i, j, p1);
		int cnt2 = cnt;
		cnt = 0;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
				dfs(i, j, p2);
		printf("%d %d\n", cnt2, cnt);
	}
	return 0;
}