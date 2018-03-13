#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const double len = 10000.0;

int main()
{
	int n, m;
	while(scanf("%d%d", &n, &m)!= EOF)
	{
		double ans = 0.0;
		for(int i = 1; i <= n; ++i)
		{
			double pos = (double)(i*1.0)/n*(n+m); //需要移动的点的坐标
			ans += fabs(pos - floor(pos + 0.5))/(n + m); //累加, pos - floor(pos + 0.5) 将其移动到距离最近的点
		}
		printf("%.4lf\n", ans*len);
	}
	return 0;
}