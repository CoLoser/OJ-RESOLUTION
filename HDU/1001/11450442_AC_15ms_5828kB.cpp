#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 1000000;

int arr[maxn];

int main()
{
	int n;
	arr[0] = 0;
	for(int i = 1; i < maxn; ++i)
		arr[i] = arr[i-1] + i;
	while(scanf("%d", &n) != EOF)
	{
		cout << arr[n] <<endl;
		printf("\n");
	}
	return 0;
}