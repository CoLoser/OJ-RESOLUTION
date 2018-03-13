#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 60;
const int INF = 0x3f3f3f3f;
int cost[MAXN][MAXN];
int lowcost[MAXN];
int visit[MAXN];
int n, m;

int prim(){
    memset(visit, 0, sizeof(visit));
    for(int i = 1; i <= n; ++i) lowcost[i] = cost[1][i];
    lowcost[1] = 0;
    visit[1] = 1;
    int res = 0;
    for(int i = 2; i <= n; ++i){
        int flag = -1;
        int minc = INF;
        for(int j = 1; j <= n; ++j){
            if(!visit[j] && lowcost[j] < minc){
                minc = lowcost[j];
                flag = j;
            }
        }
        if(flag == -1) return -1;
        visit[flag] = 1;
        res += minc;
        for(int j = 1; j <= n; ++j){
            if(!visit[j] && lowcost[j] > cost[flag][j]){
                lowcost[j] = cost[flag][j];
            }
        }
    }
    return res;
}

int main(){
    int u, v, w;

    while(scanf("%d", &n) != EOF && n){
        for(int i = 0; i < MAXN; ++i)
            for(int j = 0; j < MAXN; ++j) cost[i][j] = (i == j) ? 0 : INF;
        scanf("%d", &m);
        for(int i = 0; i < m; ++i){
            scanf("%d%d%d", &u, &v, &w);
            if(cost[u][v] >= w){
                cost[u][v] = cost[v][u] = w;
            }
        }
        int t = prim();
        printf("%d\n", t);
    }
    return 0;
}