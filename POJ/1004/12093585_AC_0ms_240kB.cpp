#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	double t, sum;
	for(int i = 0; i < 12; ++i)
	{
		cin >> t;
		sum += t;
	}
	printf("$%.2f\n", sum/12);
	return 0;
}