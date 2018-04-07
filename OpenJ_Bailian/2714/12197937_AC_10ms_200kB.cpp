#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int t;
	double a, sum;
	cin >> t ;
	for(int i = 0; i < t; ++i)
	{
		cin >> a;
		sum += a;
	}
	printf("%.2lf", sum/t);
	return 0;
}