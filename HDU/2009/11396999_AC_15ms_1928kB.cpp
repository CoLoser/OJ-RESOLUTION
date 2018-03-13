#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n, m;
	double ans = 0;
	while(cin>>n>>m)
	{
		ans = 0;
		double t = n*1.0;
		while(m --)
		{
			ans += t;
			t = sqrt(t);
		}
		printf("%.2f\n", ans);
	}
	return 0;
}