#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int MAXN = 1000;
int arr[MAXN][MAXN];

int main()
{
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF)
	{
		int key;
		int MAX = -1;
		int x, y;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
			{
				cin >> key;
				arr[i][j] = key;
				if(MAX < abs(key))
				{
					MAX = abs(key);
					x = j;
					y = i;
				}
			}

		printf("%d %d %d\n", y + 1, x + 1, arr[y][x]);
	}
}