#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
//拓扑排序

using namespace std;

const int maxn = 105;
int Graph[maxn][maxn];
int n, m;
int stack[maxn], visited[maxn];
int u, v;
int pos = 0;
void dfs(int u){
	visited[u] = -1;
	for(int i = 1; i <= n; ++i){
		if(!visited[i] && Graph[u][i])
			dfs(i);
	}
	stack[pos++] = u;
	visited[u] = 1;
}
int main(){
	while(scanf("%d%d", &n, &m) != EOF && (n || m)){
		memset(Graph, 0, sizeof(Graph));
		memset(visited, 0, sizeof(visited));
		for(int i = 0; i < m; ++i){
			scanf("%d%d", &u, &v);
			Graph[u][v] = 1;
		}
		for(int i = 1; i <= n; ++i){
			if(!visited[i]) dfs(i);
		}
		while(pos){
			printf("%d", stack[--pos]);
			printf("%c", pos > 0 ? ' ' : '\n');
		}
	}
	return 0;
}