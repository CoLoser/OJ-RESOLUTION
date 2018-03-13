#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define m n*(n-1)/2
using namespace std;

const int maxn = 10005;

struct Edge{
	int from, to;
	int value;
}edges[maxn*(maxn-1)];

int UF[maxn];
int n;

bool cmp(Edge e1, Edge e2)
{
	return e1.value < e2.value;
}
int find(int t)
{
	return t == UF[t] ? t : find(UF[t]);
}

int Union(int a, int b, int ans, int idx)
{
	int x = find(a);
	int y = find(b);
	
	if(x != y){
		UF[y] = x;
		ans += edges[idx].value;
	}
	return ans;
}

void readin()
{
	for(int i = 0; i < m; ++i)
	{
		scanf("%d%d%d", &edges[i].from, &edges[i].to, &edges[i].value);
	}
}

void init()
{
	for(int i = 0; i < maxn; ++i)
		UF[i] = i;
}

int Kruskal()
{
	int ans = 0;
	init();
	sort(edges, edges + m, cmp);
	
	for(int i = 0; i < m; ++i)
	{
		ans = Union(edges[i].from, edges[i].to, ans, i);
	}
	return ans;
}
int main()
{
	while(scanf("%d", &n) != EOF && n)
	{
		readin();
		printf("%d\n", Kruskal());
	}
}