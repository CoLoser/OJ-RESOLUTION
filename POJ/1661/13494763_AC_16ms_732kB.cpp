#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1005;
const int INF = 0x3f3f3f3f;
struct _Node {
	int xl, xr, h;
	bool operator < (const _Node rhs) const{
		return h <= rhs.h;
	}
};
_Node plat[MAXN];
int dp[MAXN][2]; //到左边和到右边的最短距离
int n, X, Y, MAX;

void toLeft(int idx) {	//从左边走的最短时间
	int front = idx - 1;
	while(front > 0 && plat[idx].h - plat[front].h <= MAX) {
		if(plat[idx].xl >= plat[front].xl && plat[idx].xl <= plat[front].xr) {
			dp[idx][0] = plat[idx].h - plat[front].h + min(dp[front][0] + plat[idx].xl - plat[front].xl, dp[front][1] + plat[front].xr - plat[idx].xl); 		//选择左边走或者右边走
			return ;
		} else
			front--;
	}

	if(plat[idx].h - plat[front].h > MAX) {
		dp[idx][0] = INF;
	} else {
		dp[idx][0] = plat[idx].h;
	}
}

void toRight(int idx) {	//从右边走的最短时间
	int front = idx - 1;
	while(front > 0 && plat[idx].h - plat[front].h <= MAX) {
		if(plat[idx].xr <= plat[front].xr && plat[idx].xr >= plat[front].xl) {
			dp[idx][1] = plat[idx].h - plat[front].h + min(dp[front][0] + plat[idx].xr - plat[front].xl, dp[front][1] + plat[front].xr - plat[idx].xr);
			return ;
		} else
			front--;
	}

	if(plat[idx].h - plat[front].h > MAX) {
		dp[idx][1] = INF;
	} else {
		dp[idx][1] = plat[idx].h;
	}
}


int solove() {

	for(int i = 1; i <= n + 1; ++i) {
		toLeft(i);
		toRight(i);
		//printf("%d %d %d\n",i,  dp[i][0], dp[i][1]);
	}

	return min(dp[n + 1][1], dp[n + 1][0]);
}
int main() {
	int t;
	scanf("%d", &t);
	
	while(t--) {
		scanf("%d%d%d%d", &n, &X, &Y, &MAX);
		for(int i = 1; i <= n; ++i) scanf("%d%d%d", &plat[i].xl, &plat[i].xr, &plat[i].h);

		plat[n+1].xl = X;
		plat[n+1].xr = X;
		plat[n+1].h = Y;
		plat[0].xl = -20000;
		plat[0].xr = 20000;
		plat[0].h = 0;
		sort(plat, plat + n + 2);
//		for(int i = 0; i <= n + 1; ++ i)
//			printf("%d %d %d\n", plat[i].xl, plat[i].xr, plat[i].h);
		printf("%d\n", solove());
	}
	return 0;
}