#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 105;
int g[MAXN][MAXN];
bool visit[MAXN]; //访问
int use[MAXN];  //匹配
int cx[MAXN*MAXN], cy[MAXN*MAXN];
int n, m, k;

bool dfs(int x){
    for(int i = 1; i <= m; ++i){
        if(g[x][i] && !visit[i]){
            visit[i] = 1;
            if(!use[i] || dfs(use[i])){
                use[i] = x;
                return true;
            }
        }
    }
    return false;
}

int getMax(){
    int sum = 0;
    memset(use, 0, sizeof(use));

    for(int i = 1; i <= n; ++i){
        memset(visit, 0, sizeof(visit));
        if(dfs(i)) sum++;
    }
    return sum;
}
int main(){
    int cnt = 0;
    while(scanf("%d%d%d", &n, &m, &k) != EOF){
        memset(g, 0, sizeof(g));
        for(int i = 0; i < k; ++i){
            scanf("%d%d", &cx[i], &cy[i]);
            g[cx[i]][cy[i]] = 1;
        }

        int ans = getMax();
        int sum = 0;
        for(int i = 0; i < k; ++i){
            //delete edge judge if edge decrease
            g[cx[i]][cy[i]] = 0;
            int t = getMax();
            g[cx[i]][cy[i]] = 1;
            if(ans > t) sum++; 
        }
        printf("Board %d have %d important blanks for %d chessmen.\n", ++cnt, sum, ans);
    }
    return 0;
}
