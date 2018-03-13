#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int MAXN = 1001;
double arr[MAXN];

int main()
{
	arr[0] = 0.0;
	for(int i = 1; i < MAXN; ++i)
		arr[i] = arr[i-1] + 1.0/(i+1);

	double t;
	while(scanf("%lf", &t) != EOF && fabs(t) > 1e-6)
	{
		for(int i = 1; i < MAXN; ++i)
		{
			if(arr[i] >= t){
				printf("%d card(s)\n", i);
				break;
			}
		}
	}
	return 0;
}