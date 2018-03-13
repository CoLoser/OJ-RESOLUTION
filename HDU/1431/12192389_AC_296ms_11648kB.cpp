#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int MAXN = 9989899 + 1;
bool visit[MAXN];

bool judge(int n)
{
	int tmp1 = 0, tmp2 = n;
	while(n)
	{
		tmp1 = tmp1 * 10 + n % 10;
		n /= 10;
	}
	return tmp1 == tmp2;
}

void find()
{
	memset(visit, 0, sizeof(visit));
	visit[0] = 1;
	visit[1] = 1;
	for(int i = 2; i < sqrt(MAXN); ++i) if(!visit[i])
		for(int j = 2 * i; j < MAXN; j += i) visit[j] = 1;
	for(int i = 2; i < MAXN; ++i) if(!visit[i] && !judge(i)) visit[i] = 1;
}

int main()
{
	find();
	int start, end;
	while(scanf("%d%d", &start, &end) != EOF)
	{
		for(int i = start; i <= end; ++i)
			if(i < MAXN && visit[i] == 0) printf("%d\n", i);
		printf("\n");
	}
}