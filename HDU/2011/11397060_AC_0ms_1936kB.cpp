#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
	int t, n;
	cin >> t;
	while(t--)
	{
		double ans = 0.0;
		int flag = 1;
		cin >> n;
		for(int i = 1; i <= n; ++i)
		{
			ans += 1.0/i * flag;
			flag *= -1;
		}
		printf("%.2f\n", ans);
	}
}