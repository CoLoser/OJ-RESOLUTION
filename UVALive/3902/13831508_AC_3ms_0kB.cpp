#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector> 
using namespace std;

const int MAXN = 1005;
int fa[MAXN];							//fa表示父节点 
vector<int> gr[MAXN], nodes[MAXN]; 		//gr存储无向图， nodes存储深度为d的叶子节点
int n, s, k;
bool covered[MAXN];

void dfs(int u, int v, int d){	//找到所有叶子节点， 建树 
	fa[u] = v;	//v的父节点为u;
	int nc = gr[u].size();
	if(nc == 1 && d > k) nodes[d].push_back(u);
	for(int i = 0; i < nc; ++i){
		int f = gr[u][i];
		if(v != f) dfs(f, u, d+1);
	} 
} 

//新的服务器放置点将覆盖的范围更新 
void dfs2(int u, int v, int d){
	covered[u] = true;
	int nc = gr[u].size();
	
	for(int i = 0; i < nc; ++i){
		int f = gr[u][i];
		if(v != f && d < k) dfs2(f, u, d + 1);	//更新覆盖范围 
	} 
} 

int solove(){
	int ans = 0;
	memset(covered, 0, sizeof(covered));
	
	for(int d = n - 1; d > k; --d){
		for(int i = 0; i < nodes[d].size(); ++i){
			int u = nodes[d][i];			//深度为d的叶子节点
			
			if(covered[u]) continue;
			
			int v = u;
			for(int j = 0; j < k; ++j) v = fa[v]; 	//查找叶子节点的k级祖先
			dfs2(v, -1, 0);			//更新覆盖范围 
			ans ++; 
		}
	} 
	return ans;
} 
 
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d",&n, &s, &k);
		for(int i = 1; i <= n; ++i){
			gr[i].clear();
			nodes[i].clear();
		} 
		for(int i = 0; i < n - 1; ++i){
			int u, v;
			scanf("%d%d", &u, &v);
			gr[u].push_back(v);
			gr[v].push_back(u);		//无向图 
		}
		dfs(s, -1, 0);
		printf("%d\n", solove());
	}	
	return 0;
}