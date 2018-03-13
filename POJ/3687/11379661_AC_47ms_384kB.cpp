#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int maxn = 205;

int g[maxn][maxn];
int out[maxn];  //每一个节点的出度
int n, m;
priority_queue<int> pq;
int weight[maxn];

bool topoSort()
{
	while(!pq.empty()) pq.pop();
	for(int i = 1; i <= m; ++i)
	{
		if(out[i] == 0) pq.push(i);
	}
	int x = m;
	while(!pq.empty())
	{
		
		int v = pq.top();
		pq.pop();
		weight[v] = x--;
		for(int i = 1; i <= m; ++i)
		{
			//cout <<"i = " <<i <<" v = " << v << "g[i][v] = " << g[i][v] <<endl;
			if(g[i][v] == 1){
				out[i] -- ;
				if(out[i] == 0) pq.push(i);
			}
		}
	}
	return  x == 0;
}

void init()
{
	memset(out, 0, sizeof(out));
	for(int i = 0; i < maxn; ++i)
	{
		for(int j = 0; j < maxn; ++j)
		{
			g[i][j] = 0;
		}
	}
}
int main()
{
	int kase;
	scanf("%d", &kase);
	
	while(kase--)
	{
		scanf("%d%d", &m, &n);
		init();
		int a, b;
		for(int i = 0; i < n; ++i)
		{
			scanf("%d%d", &a, &b);
			if(g[a][b] == 0)
			{
				g[a][b] = 1;
				out[a]++;
			}
		}
		
		if(!topoSort()) printf("-1\n");
		else{
			for(int i = 1; i <= m; i ++)
			{
				printf("%d%c", weight[i], i == m ? '\n' : ' ');
			}
		}
	}
	return 0;
}