#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int arr[21] = {1, 1, };
	for(int i = 2; i < 21; ++i)
		arr[i] = arr[i-1] + arr[i-2];
	int t, n;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		printf("%d\n", arr[n-1]);
	}
		
}