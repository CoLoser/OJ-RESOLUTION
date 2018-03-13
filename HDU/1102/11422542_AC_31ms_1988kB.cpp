#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 0x3ffff;
const int maxn = 105;

int pic[maxn][maxn];
int lowcost[maxn];      //记录邻接点的最短边
int visit[maxn];
int n, m;

void readin()
{
	int t;
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
   			pic[i][j] = INF;
			scanf("%d", &t);
			if(t != 0) pic[i][j] = t;
		}
	}
	
	cin >> m;
    int x1, x2;
    for(int i = 0; i < m; ++i)
    {
		cin >> x1 >> x2;
		pic[x1][x2] = 0;
		pic[x2][x1] = 0;
	}
}

void init(int start)
{
	
	for(int i = 1; i <= n; ++i)
	{
		lowcost[i] = pic[start][i];
		visit[i] = 0;
	}
}

int prim(int start)
{
    int ans = 0;
    int min;
    init(start);

    visit[start] = 1;

    for(int i = 1; i <= n; ++i){
        min = INF;
        int flag = -1;
        for(int j = 1; j <= n; ++j){        //找到最小值
            if(!visit[j] && min > lowcost[j]){
                min = lowcost[j];
                flag = j;
            }
        }

        if(flag != -1){
            visit[flag] = 1;
            ans += min;                     //权值叠加

            for(int j = 1; j <= n; ++j){        //更新lowcost
                if(!visit[j] && pic[flag][j] < lowcost[j]){
                    lowcost[j] = pic[flag][j];
                }
            }
        }
    }
    return ans;
}
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		readin();
		cout << prim(1) <<endl;
	}
    
    return 0;
}