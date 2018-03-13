#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int MAXN = 10000 + 1;
int visit[MAXN];

void init()
{
	memset(visit, 0, sizeof(visit));
	visit[0] = 1;
	visit[1] = 1;
	for(int i = 2; i <= sqrt(MAXN); ++i) if(!visit[i])
		for(int j = 2 * i; j < MAXN; j += i) visit[j] = 1;
}

int main()
{
	int n;
	init();
	while(scanf("%d", &n) != EOF)
	{
		int a = n/2, b = n/2;
		while(visit[a]) a--;
		while(visit[b]) b++;
		while(a + b != n)
		{
			if(a + b > n) a--;
			else b++;
			
			while(visit[a]) a--;
			while(visit[b]) b++;
		}
		printf("%d %d\n", a, b);
	}
	return 0;
}