#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int MAXN = 250;
const int INF = 0x3f3f3f3f;
double point[MAXN][2];
double cost[MAXN][MAXN];
double dist[MAXN];  	//保存一个最短的边 
int visit[MAXN];

double Distance(double x1, double y1, double x2, double y2)
{
	return sqrt((x2 - x1)*(x2 - x1)*1.0 + (y2 - y1)*(y2 - y1)*1.0);
}

//求最长路径上一个最短的边 
void dijkstra(int beg, int n)
{
	memset(visit, 0, sizeof(visit));
	for(int i = 1; i <= n; ++i) dist[i] = cost[beg][i];
	visit[beg] = 1;
	dist[beg] = 0;
	int pre = beg;
	for(int i = 1; i <= n; ++i)
	{
		double MIN = INF;
		for(int j = 1; j <= n; ++j)
		{
			if(!visit[j])
			{
				double maxx = max(dist[pre], cost[pre][j]);
				if(dist[j] > maxx)
					dist[j] = maxx;
			}
		}
		for(int j = 1; j <= n; ++j)
		{
			if(!visit[j] && dist[j] < MIN)
			{
				MIN = dist[j];
				pre = j;
			}
		}
		visit[pre] = 1;
	}
}
void init()
{
	for(int i = 0; i < MAXN; ++i)
		for(int j = 0; j < MAXN; ++j)
			cost[i][j] = (i == j)?0 : INF;
}
int main()
{
	int t;
	int cnt = 1;
	while(scanf("%d", &t) != EOF && t)
	{
		for(int i = 1; i <= t; ++i)
		{
			scanf("%lf%lf", &point[i][0], &point[i][1]);
		}
		
		for(int i = 1; i <= t - 1; ++i)
		{
			for(int j = i + 1; j <= t; ++j)
			{
				cost[i][j] = cost[j][i] = Distance(point[i][0], point[i][1], point[j][0], point[j][1]);
			}
		}
		dijkstra(1, t);
		printf("Scenario #%d\n", cnt++);
		printf("Frog Distance = %.3f\n", dist[2]);
		printf("\n");
	}
}