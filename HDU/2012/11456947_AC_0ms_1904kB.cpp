#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define f(x) x*x + x + 41
using namespace std;

const int maxn = 10000;
int visit[maxn];
void getPrime()
{
	memset(visit, 0, sizeof(visit));
	for(int i = 2; i < maxn; ++i)if(!visit[i])
		for(int j = 2*i; j < maxn; j += i) visit[j] = 1;
}
bool isPrime(int x, int y)
{
	for(int i = x; i <= y; ++i)
	{
		int t = f(i);
		if(visit[t]) return false;
	}
	return true;
}

int main()
{
	int x, y;
	while(scanf("%d%d", &x, &y) != EOF)
	{
		if(x == 0 && y == 0) break;
		getPrime();
		if(isPrime(x, y)) printf("OK\n");
		else printf("Sorry\n");
	}
	return 0;
}