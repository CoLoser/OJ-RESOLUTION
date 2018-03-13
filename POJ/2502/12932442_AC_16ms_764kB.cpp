#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

const double subspeed = 40*1000/60;
const double peospeed = 10*1000/60;
const double INF = 0x3f3f3f3f;
const int MAXN = 250;
int visit[MAXN];
double cost[MAXN][MAXN];
double dist[MAXN];
double t[MAXN][2];
double EurDist(int t1, int t2) {
	double x1 = t[t1][0], y1 = t[t1][1];
	double x2 = t[t2][0], y2 = t[t2][1];
	return sqrt((x1 - x2)*(x1 - x2)*1.0 + (y1 - y2)*(y1 - y2)*1.0);
}

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
			if(!visit[j] && dist[pre] + cost[pre][j] < dist[j]) dist[j] = cost[pre][j] + dist[pre];
		for(int j = 1; j <= n; ++j)
			if(!visit[j] && MIN > dist[j])
			{
				MIN = dist[j];
				pre = j;
			 }
		visit[pre] = 1;
	}
}

int main() {

	for(int i = 0; i < MAXN; ++i)
		for(int j = 0; j < MAXN; ++j) cost[i][j] = (i == j) ? 0 : INF;
	int cnt = 1;
	cin >> t[1][0] >> t[1][1] >> t[2][0] >> t[2][1];
    cnt = 3;

    while( cin >> t[cnt][0] >> t[cnt][1] ){
        cnt++;
        while( cin >> t[cnt][0] >> t[cnt][1], !( t[cnt][0] == -1 && t[cnt][1] == -1 ) ){
            cost[cnt][cnt - 1] = cost[cnt - 1][cnt] = EurDist( cnt - 1, cnt) / subspeed;
            cnt++;
        }
    }

	cnt--;
	
	for(int i = 1; i < cnt; ++i)
		for(int j = i + 1; j <= cnt; ++j)
			cost[i][j] = cost[j][i] = min(cost[i][j], EurDist(i, j)/peospeed);
//	for(int i = 1; i <= cnt; ++i) {
//		for(int j = 1; j <= cnt; ++j)
//			cout << cost[i][j] << " ";
//		cout << endl;
//	}

	dijkstra(1, cnt);
	printf("%d\n", (int)(dist[2] + 0.5));
	return 0;
}