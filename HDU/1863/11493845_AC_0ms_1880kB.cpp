#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 105;
struct Edge{
	int from, to;
	int value;
};
bool cmp(Edge rts1, Edge rts2){
	return rts1.value < rts2.value;
}
Edge edges[maxn*(maxn-1)];
int pic[maxn];
int n, m;
int t = 0;
int find(int t)
{
	return t == pic[t] ? t : find(pic[t]);
}
int Union(int a, int b, int idx, int ans)
{
	int x = find(a);
	int y = find(b);
	if(x != y){
		pic[y] = x;
		ans += edges[idx].value;
		t++;
	} 
	return ans;
}

void init()
{
	for(int i = 0; i < maxn; ++i) pic[i] = i;
}
int Kruskal()
{
	int ans = 0;
	sort(edges, edges+m, cmp);
	for(int i = 0; i < m; ++i)
		ans = Union(edges[i].from, edges[i].to, i, ans);
	return ans;
}
int main()
{
	while(scanf("%d%d", &m, &n) != EOF && m)
	{
		init();
		t = 0;
		for(int i = 0; i < m; ++i)
		{
			scanf("%d%d%d", &edges[i].from, &edges[i].to, &edges[i].value);
		}
		int ans = Kruskal();
		if(t == n - 1)printf("%d\n", ans);
		else printf("?\n");
	}
}