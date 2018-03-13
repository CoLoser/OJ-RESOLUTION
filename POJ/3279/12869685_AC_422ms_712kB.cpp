#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 20;
int res[MAXN][MAXN];
int tmp[MAXN][MAXN];
int state[MAXN][MAXN];
int grid[MAXN][MAXN];

int n, m;
int ans;
const int INF = 0x3f3f3f;
int dist[5][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {0, 0}};
void flip(int x, int y){
	tmp[x][y] = 1;
	for(int i = 0; i < 5; ++i)
	{
		int dx = x + dist[i][0], dy = y + dist[i][1];
		state[dx][dy] = !state[dx][dy];
	 }
}

bool isEmpty(int n)
{
	for(int i = 1; i <= m; ++i)
	{
		if(state[n][i] == 1) return false; 
	}
	return true;
}

void solve(int s)
{
	memcpy(state, grid, sizeof(grid));
	memset(tmp, 0, sizeof(tmp));
	
	int cnt = 0;
	for(int i = 0; i < m; ++i)
	{
		if((s >> i) & 1)
		{
			flip(1, i + 1);
			cnt ++;
		}
	}
	
	for(int i = 2; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			if(state[i - 1][j] == 1)
			{
				flip(i, j);
				cnt ++;
			}
		}
	}
	
	if(isEmpty(n) && cnt < ans)
	{
		ans = cnt;
		memcpy(res, tmp, sizeof(tmp));
	}
}
int main()
{
	while(cin >> n >> m)
	{
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= m; ++j)
			{
				cin >> grid[i][j];
			}
		 } 
		
		ans = INF;
		int t = 1 << m;
		 
		for(int i = 0; i < t; ++i)
		{
			solve(i);
		}
		
		if(ans == INF) printf("IMPOSSIBLE\n");
		else{
			for(int i = 1; i <= n; ++i)	
			{
				for(int j = 1; j <= m; ++j)
				{
					printf("%d%c", res[i][j], j == m ? '\n' : ' ');
				}
			}
		}
	}
	
	return 0;
}