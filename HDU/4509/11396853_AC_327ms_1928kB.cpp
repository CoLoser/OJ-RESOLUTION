#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1440;
int arr[maxn];
int main()
{
	int t;
	int h1, m1, h2, m2;
	while(scanf("%d", &t) != EOF)
	{
		memset(arr, 0, sizeof(arr));
		int sum = 0;
		while(t--)
		{
			scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
			int start = h1*60 + m1;
			int end = h2*60 + m2;
			for(int i = start; i < end; ++i)
			{
				arr[i] = 1;
			}
		}
		for(int i = 0; i < maxn; ++i)
			if(arr[i] == 0) sum++;
		cout << sum <<endl;
	}
	return 0;
}