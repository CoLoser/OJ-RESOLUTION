#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 250005;
int arr[maxn];

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		for(int i = 0; i < n; ++i)cin>>arr[i];
		sort(arr, arr + n);
		double median = 0.0;
		if(n%2 == 1) median = arr[n/2];
		else median = arr[n/2]/2.0 + arr[n/2-1]/2.0;
		printf("%.1f\n", median);
	}
	return 0;
}