#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10005;
const int INF = 0x3f3f3f3f;
int dp[MAXN]; 	//dp[v] 大小为v的存钱罐存满能存最少的钱
struct _Coin {
	int p, w;
};
_Coin coin[500];

int main() {
	int t, n, a, b;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &a, &b);
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)scanf("%d%d", &coin[i].p, &coin[i].w);
		memset(dp, INF, sizeof(dp));
		dp[0] = 0;
		int v = b - a;
		for(int i = 0; i < n; ++i) {
			for(int j = coin[i].w; j <= v; ++j) {
				dp[j] = min(dp[j], dp[j - coin[i].w] + coin[i].p);
			}
		}
		if(dp[v] == INF)
			printf("This is impossible.\n");
		else
			printf("The minimum amount of money in the piggy-bank is %d.\n", dp[v]);
	}
}