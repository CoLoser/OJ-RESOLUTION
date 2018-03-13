#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int t;
	double u, v, w, l;
	cin >> t;
	while(t--)
	{
		cin >> u >> v >> w >> l;
		printf("%.3f\n", l/(u + v) * w);
	}
	return 0;
}