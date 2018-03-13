#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 20005;
int x[maxn];
int y[maxn];

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		for(int i = 0; i < n; ++i)
			cin >> x[i] >> y[i];

		sort(x, x+n);
		for(int i = 0; i < n; ++i)
			x[i] -= i;
		sort(x, x+n);
		sort(y, y+n);
		
		int xm, ym;
		int ans = 0;
		if(n%2 == 1)
		{
			xm = x[n/2];
			ym = y[n/2];
		}else{
			xm = (x[n/2-1] + x[n/2])/2;
			ym = (y[n/2-1] + y[n/2])/2;
		}
		
		for(int i = 0; i < n; ++i)
		{
			ans += abs(y[i] - ym) + abs(x[i] - xm);
		}
		printf("%d\n", ans);
	}
	return 0;
}