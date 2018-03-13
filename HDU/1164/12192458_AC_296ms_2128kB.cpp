#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int MAXN = 65535 + 1;
int visit[MAXN];

void init()
{
	memset(visit, 0, sizeof(visit));
	visit[0] = 1;
	visit[1] = 1;
	for(int i = 2; i <= sqrt(MAXN); ++i) if(!visit[i])
		for(int j = 2 * i; j < MAXN; j += i) visit[j] = 1;
}

void solove(int n)
{
	int flag = 1;
	for(int i = 2; i <= MAXN;)
	{
		if(!visit[i] && n % i == 0)
		{
			while(n % i == 0)
			{
				n /= i;
				if(flag)
				{
					printf("%d", i);
					flag = 0;
				}else{
					printf("*%d", i);
				}
			}
		}else i++;
	}
	printf("\n");
}
int main()
{
	int n;
	init();
	while(scanf("%d", &n) != EOF)
		solove(n);
	return 0;
}