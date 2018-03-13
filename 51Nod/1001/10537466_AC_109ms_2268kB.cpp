#include "iostream"
#include "algorithm"
#include "stdio.h"
using namespace std;
void sort(int *arr, int Len);
int arr[51000];
int main(int argc, char const *argv[])
{
	int N, K;
	scanf("%d%d", &K, &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + N);
	bool flag = false;
	int end = N - 1, start = 0;
	while (start < end)
	{
		int sum = arr[end] + arr[start];
		if ( sum == K && arr[end] > arr[start])
		{
			printf("%d %d\n", arr[start], arr[end] );
			flag = true;
			start++;
		}
		else if (sum > K)
		{
			end--;
		}
		else if (sum < K)
		{
			start++;
		}
	}
	if (!flag)
	{
		printf("No Solution\n");
	}
	return 0;
}