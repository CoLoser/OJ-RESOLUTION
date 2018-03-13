#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	int n, m;
	double ans = 0;
	while(scanf("%d%d", &n, &m) != EOF)
	{
		double t = n;
		ans = 0;
		while(m--)
		{
			ans += t;
			t = sqrt(t);
		}
		printf("%.2f\n", ans);
	}
}