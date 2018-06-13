#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 105;
const int MAXM = 105*105 + 10;

bool visit[MAXN];
bool g[MAXN][MAXN];
bool bestx[MAXN];
int cnt, bestn, n, m;


void dfs(int x){
    bool flag;
    if(x > n){
        bestn = cnt;
        memcpy(bestx, visit, sizeof(visit));
        return;
    }

    flag = true;
    for(int i = 1; i < x; ++i){
        if(visit[i] && !g[i][x]){   //此点被标记过且两个节点不连接 不能构成团
            flag = false;
            break;
        }
    }

    if(flag){
        cnt++;
        visit[x] = true;
        dfs(x+1);
        visit[x] = false;
        cnt--;
    }

    if(cnt + n - x > bestn){ //剪枝
        dfs(x + 1);
    }
}
int main(){
    int T, a, b;
    scanf("%d", &T);

    while(T--){
        memset(g, 1, sizeof(g));
        memset(visit, 0, sizeof(visit));
        memset(bestx, 0, sizeof(bestx));
        scanf("%d%d", &n, &m);
        for(int i = 0; i < m; ++i){
            scanf("%d%d", &a, &b);
            //构建补图
            g[a][b] = g[b][a] = 0;
        }
        cnt = bestn = 0;
        dfs(1);
        printf("%d\n", bestn);
        for(int i = 0; i <= n; ++i) if(bestx[i])printf("%d ", i);printf("\n");
    }
    return 0;
}