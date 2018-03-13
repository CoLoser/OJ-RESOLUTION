#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 10005;
int prime[MAXN];

void find()
{
	memset(prime, 0, sizeof(prime));
	prime[1] = 1;
	for(int i = 2; i < MAXN; ++i) if(!prime[i])
		for(int j = i*i; j < MAXN; j += i) prime[j] = 1;
}

int main()
{
	int t;
	find();
	while(scanf("%d", &t) != EOF && t)
	{
		int cnt = 0;
		int sum = 0;
		for(int i = 1; i <= t; ++i)
		{
			if(!prime[i])
			{
				for(int j = i; j <= t; ++j)
				{
					if(sum >= t) break;
					if(!prime[j])
					{
						sum += j;
					}
				}
				if(sum == t) cnt++;
				sum = 0;
			}
		}
		cout << cnt <<endl;
			
	}
}