#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 110005;
char key[MAXN];
char target[MAXN<<1];
int p[MAXN<<1];

void init()
{
	target[0] = '$';
	target[1] = '#';
	int idx = 1;
	for(int i = 0; key[i]; ++i)
	{
		target[++idx] = key[i];
		target[++idx] = '#';
	}
	target[++idx] = '\0';
}

void Manacher(char target[])
{
	//计算p[i]
	int i, id = 0, mx = 0;
	p[0] = 0;
	
	for(i = 1; target[i]; ++i)
	{
		if(mx > i) p[i] = min(p[2*id - i], mx - i);
		else p[i] = 1;
		
		while(target[i + p[i]] == target[i - p[i]])
			p[i] ++;
		if(mx < p[i] + i)
		{
			mx = p[i] + i;
			id = i;
		}
	}
}
int main()
{
	while(scanf("%s", key) != EOF)
	{
		init();
		Manacher(target);
		int ans = -1;
		for(int i = 0; target[i] != '\0'; ++i)
			ans = max(ans, p[i] - 1);
		printf("%d\n", ans);
	}
}