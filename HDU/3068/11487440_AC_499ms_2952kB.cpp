#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 110005;
char target[maxn];
char target01[maxn<<1];
int p[maxn<<1];

void Manacher(char target01[])
{
	//计算p[i]
	int i, id = 0, mx = 0;
	p[0] = 0;
	for(i = 1; target01[i]; ++i)
	{
		if(mx > i) p[i] = min(p[2*id - i], mx - i);
		else p[i] = 1;
		
		while(target01[i+p[i]] == target01[i-p[i]])
			p[i]++;
		if(mx < p[i] + i)
		{
			mx = p[i] + i;
			id = i;
		}
	}
}
void init()
{
	int j = 2;
	target01[0] = '$';
	target01[1] = '#';
	for(int i = 0; target[i]; ++i)
	{
		target01[j++] = target[i];
		target01[j++] = '#';
	}
	target01[j] = '\0';
}
int main()
{
	while(scanf("%s", target) != EOF)
	{
		init();
		Manacher(target01);
		int ans = 0;
		for(int i = 1; target01[i] != '\0'; ++i)
		{
			ans = max(ans, p[i]);
		}
		printf("%d\n", ans - 1);
	}
}