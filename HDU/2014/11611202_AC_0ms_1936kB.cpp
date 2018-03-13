#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 105;
double arr[MAXN];

int main()
{
	int n;
	while(cin >> n)
	{
		for(int i = 0; i < n; ++i) cin >> arr[i];
		sort(arr, arr + n);
		
		double ans = 0.0;
		for(int i = 1; i < n - 1; ++i)
			ans += arr[i];

		printf("%.2f\n", ans/(n-2));
	}
}
