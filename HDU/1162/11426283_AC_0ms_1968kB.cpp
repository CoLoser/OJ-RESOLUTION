#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn = 105;

int n;
struct Edge{
	int from, to;
	double value;
}edges[maxn*(maxn-1)];
double Point[maxn][2];

int UF[maxn];
int cnt;
void init()
{
	for(int i = 0; i < maxn; ++i)
		UF[i] = i;
}
double calArea(double x1, double y1, double x2, double y2)
{
	return sqrt((y2 - y1)*(y2 - y1) + (x2 - x1)*(x2 - x1));
}
void readin()
{
	for(int i = 1; i <= n; ++i)
	{
		scanf("%lf%lf", &Point[i][0], &Point[i][1]);
	}

	cnt = 0;
	for(int i = 2; i <= n; ++i)
	{
		for(int j = 1; j < i; ++j)
		{
			edges[cnt].from = i;
			edges[cnt].to = j;
			edges[cnt].value = calArea(Point[i][0], Point[i][1], Point[j][0], Point[j][1]);
			cnt ++;
		}
	}
}


int find(int t)
{
	return t == UF[t] ? t : find(UF[t]);
}

double Union(int a, int b, double ans, int idx)
{
	int x = find(a);
	int y = find(b);
	
	if(x != y)
	{
		UF[y] = x;
		ans += edges[idx].value;
	}
	return ans;
	
}

bool cmp(Edge e1, Edge e2)
{
	return e1.value < e2.value;
}
double Kruskal()
{
	double ans = 0;
	sort(edges, edges+cnt, cmp);
	
	init();
	for(int i = 0; i < cnt; ++i)
	{
		ans = Union(edges[i].from, edges[i].to, ans, i);
	}
	return ans;
}
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		readin();
		printf("%.2lf", Kruskal());
		printf("\n");
	}
	return 0;
}
