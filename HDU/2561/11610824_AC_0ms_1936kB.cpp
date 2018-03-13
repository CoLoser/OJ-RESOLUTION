#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 15;
int arr[MAXN];

int main()
{
	int t, n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 0; i < n; ++i) cin >> arr[i];
		sort(arr, arr + n);
		cout << arr[1] <<endl;
	}
}