#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


int main()
{
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF)
	{
		int sum2 = 0, sum3 = 0;
		if(m < n) swap(m, n);
		for(int i = n; i <= m; ++i)
		{
			if(i % 2 == 0) sum2 += i*i;
			else sum3 += i*i*i;
		}
		printf("%d %d\n", sum2, sum3);
	}
	return 0;
}