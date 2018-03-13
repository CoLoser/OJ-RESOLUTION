#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

const int MAXN = 1e5+1;
int visit[MAXN];
int arr[MAXN];

void solove()
{
	int cnt = 0;
	memset(visit, 0, sizeof(visit));
	visit[0] = 1;
	visit[1] = 1;
	for(int i = 2; i <= sqrt(MAXN); ++i) if(!visit[i])
		for(int j = 2 * i; j < MAXN; j += i) visit[j] = 1;
	for(int i = 0; i < MAXN; ++i)
		if(!visit[i]) arr[i] = ++cnt;
		else arr[i] = cnt;
}
int main()
{
	solove();
	int a, b;
	while(scanf("%d%d", &a, &b)!= EOF)
	{
		if(a > b) swap(a, b);
		printf("%d\n", arr[b] - arr[a - 1]);
	}
		
	return 0;
}