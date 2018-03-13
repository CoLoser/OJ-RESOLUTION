#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct Edge{
	int a, b; //货币
    double rate; //汇率
    double c;    //手续费
};
const int MAXN = 105;

int n;      //货币种类数
int m;     	//兑换点数量
int s;    	//持有货币种类
double v; 	//本金
int e;      //总边数
Edge E[MAXN<<1];
double dis[MAXN];

bool bellman_Ford()
{
	memset(dis, 0, sizeof(dis));
	dis[s] = v;
	
	bool flag;
	
	for(int i = 1; i <= n - 1; ++i)
	{
		flag = false;
		for(int j = 0; j < e; ++j)
		{
			if(dis[E[j].b] < (dis[E[j].a] - E[j].c)*E[j].rate)
			{
				dis[E[j].b] = (dis[E[j].a] - E[j].c)*E[j].rate;
				flag = true;
			}
		}
		if(!flag) break;
	}
	
	for(int i = 0; i < e; ++i)
        if(dis[E[i].b] < (dis[E[i].a] - E[i].c)*E[i].rate) return true;
	return false;
}
int main()
{
	int a, b;
    double rab, abc, rba, bac;
	while(cin >> n >> m >> s >> v)
	{
		e = 0;
		for(int i = 0; i < m; ++i)
		{
			cin >> a >> b >> rab >> abc >> rba >> bac;

			E[e].a = a;
			E[e].b = b;
			E[e].rate = rab;
			E[e++].c = abc;
			E[e].a = b;
			E[e].b = a;
			E[e].rate = rba;
			E[e++].c = bac;
		}
		if(bellman_Ford()) printf("YES\n");
		else printf("NO\n");
	}
	
	
}