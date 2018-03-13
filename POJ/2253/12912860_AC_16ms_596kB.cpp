#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int MAXN = 205;
double cost[MAXN][MAXN];
double point[MAXN][2];
int visit[MAXN];
const double INF = 0x3f3f3f3f;
double dist[MAXN];	//最短路径上两个节点的最短长度
int n, m;

double calDist(double x1, double y1, double x2, double y2) {
	return  sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

void dijkstra(int beg) {
	memset(visit, 0, sizeof(visit));
	for(int i = 1; i <= n; ++i) dist[i] = cost[beg][i];
	visit[beg] = 1;
	dist[beg] = 1;
	int pre = beg;
	
	for(int i = 1; i <= n; ++i){
		double MIN = INF;
		for(int j  = 1; j <= n; ++j){
			if(!visit[j])
			{
				double maxx = max(dist[pre], cost[pre][j]);
				if(maxx < dist[j]) dist[j] = maxx;
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
		for(int j = 0; j < MAXN; ++j) cost[i][j] =  (i == j ? 0 : INF);
} 
int main() {
	int cnt = 1;
	while(cin >> n && n)
	{
		init();
		for(int i = 0; i < n; ++i) cin >> point[i][0] >> point[i][1];
		
		for(int i = 0; i < n - 1; ++i)
			for(int j = i + 1; j < n; ++j) cost[i + 1][j + 1] = cost[j + 1][i + 1] = calDist(point[i][0], point[i][1], point[j][0], point[j][1]);
		dijkstra(1);
		printf("Scenario #%d\n", cnt++);
		printf("Frog Distance = %.3f\n", dist[2]);
		printf("\n"); 
	}
}