#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1000;
int ans[MAXN], cnt;

int solove(int n)
{
	int num = 1;
	cnt = 0;
	for(int i = 2; i < n; ++i)
	{
		if(n % i == 0)
		{
			num += i;
			ans[cnt++] = i;
		}
	}
	return num;
}
int main()
{
	for(int i = 2; i <= 1000; ++i)
	{
		if(solove(i) == i)
		{
			printf("%d its factors are 1", i);
			for(int j = 0; j < cnt; ++j)
				printf(",%d", ans[j]);
			printf("\n");
		}
	}
	return 0;
}