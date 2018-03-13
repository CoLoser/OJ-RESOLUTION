#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1005;
int a[MAXN], dp[MAXN];

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
		
		//dp
		int res = -1;
		for(int i = 0; i < n; ++i)
		{
			dp[i] = 1;
			for(int j = 0; j < i; ++j)
				if(a[j] < a[i]) dp[i] = max(dp[i], dp[j]+1);
			res = max(res, dp[i]);
		}
		printf("%d\n", res);
	}
	return 0;
}