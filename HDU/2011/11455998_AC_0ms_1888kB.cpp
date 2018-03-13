#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 1001;
double arr[maxn];

int main()
{
	int t = -1;
	arr[1] = 1;
	for(int i = 2; i < maxn; ++i)
	{
		arr[i] += arr[i-1] + 1.0/i*t;
		t*=-1;
	}
	int m, n;
	scanf("%d", &m);
	while(m--)
	{
		scanf("%d", &n);
		printf("%.2f\n", arr[n]);
	}
	return 0;
}