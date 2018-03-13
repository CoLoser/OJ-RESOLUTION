#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 20000 + 1;

struct _Node{
	char str[22];
};

_Node arr[MAXN];
int ans[MAXN];

bool cmp(_Node rhs1, _Node rhs2)
{
	return (strcmp(rhs1.str, rhs2.str) < 0);
}

int main()
{
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF && (n || m))
	{
		memset(ans, 0, sizeof(ans));
		
		for(int i = 0; i < n; ++i) cin >> arr[i].str;
		
		sort(arr, arr + n, cmp);
		
		int t = 0;
		for(int i = 0; i < n; ++i)
		{
			t = 0;
			while(strcmp(arr[i].str, arr[i+1].str) == 0) i++, t++;
			ans[t]++;
		}
		
		for(int i = 0; i < n; ++i)
		{
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}