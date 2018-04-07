#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 1e6 + 5;
int visit[MAXN];

void find()
{
	memset(visit, 0, sizeof(visit));
	visit[0] = 1;
	visit[1] = 1;
	for(int i = 2; i <= sqrt(MAXN); ++i) if(!visit[i])
		for(int j = i * 2; j < MAXN; j += i) visit[j] = 1;
}

int main()
{
	int a, d, n;
	find();
	while(cin >> a >> d >> n)
	{
		if(a == 0 && d == 0 && n == 0) break;
		int idx = 0;
		for(int i = a; i < MAXN; i += d)
		{
			if(visit[i] == 0)
			{
				idx++;
				if(idx == n) printf("%d\n", i);
			}
		}
	}
	return 0;
}