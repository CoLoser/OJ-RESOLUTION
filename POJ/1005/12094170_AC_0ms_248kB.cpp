#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const double PI = 3.1415926;
const int MAXN = 1000;
double arr[MAXN];

int main()
{
	for(int i = 0; i < MAXN; ++i)
		arr[i] = sqrt((50.0*i)*2/PI);
	int t;
	cin >> t;
	for(int j  = 1; j <= t; ++j)
	{
		double x, y;
		cin >> x >> y;
		double dis = sqrt(x*x + y*y);
		for(int i = 0; i < MAXN; ++i)
			if(dis <= arr[i])
			{
				printf("Property %d: This property will begin eroding in year %d.\n", j, i);
				break;
			}
	}
	printf("END OF OUTPUT.\n");
}