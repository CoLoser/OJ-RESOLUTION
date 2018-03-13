#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1000005;
const int maxm = 10005;
int Next[maxm];
int target[maxn];
int pattern[maxm];


void getNext(int ne[], int s[], int len)
{
	ne[0] = -1;
	int i = 0, j = -1;
	
	while(i < len)
	{
		if(j == -1 || s[j] == s[i])
		{
			i++;
			j++;
			ne[i] = j;
		}else
			j = ne[j];
	}
}

int main()
{
	int t;
	int n, m;
	
	scanf("%d", &t);
	while(t--)
	{
		memset(Next, 0, sizeof(Next));
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; ++i) scanf("%d", &target[i]);
		for(int j = 0; j < m; ++j) scanf("%d", &pattern[j]);
		getNext(Next, pattern, m);
		int i = 0, j = 0;
		while(i < n && j < m)
		{
			if(j == -1 || target[i] == pattern[j])
			{
				i++;
				j++;
			}else{
				j = Next[j];
			}
		}
		if(j == m)printf("%d\n", i - j + 1);
		else printf("-1\n");
	}
	return 0;
}