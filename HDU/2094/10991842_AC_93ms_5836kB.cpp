#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
using namespace std;
const int maxn = 1005;
map<string, int> m;
int graph[maxn][maxn];
int edge[maxn];
int n;
char name1[100], name2[100];
int main(){
	while(scanf("%d", &n) != EOF && n){
		memset(graph, 0, sizeof(graph));
		memset(edge, 0, sizeof(edge));
		m.clear();
		int idx = 1;
		for(int i = 0; i < n; ++i){
   			scanf("%s%s", name1, name2);
			if(m[name1] == 0){
				m[name1] = idx ++;
			}
			if(m[name2] == 0){
				m[name2] = idx ++;
			}
			graph[m[name1]][m[name2]] = 1;
			edge[m[name2]] ++; //每个节点的度只能是一; 且首节点的度为0;
		}
		bool flag = false;
		int sum = 0;
		for(int i = 1; i < idx; ++i){
			if(edge[i] == 0) sum ++;
		}
		if(sum == 1) flag = true;
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}