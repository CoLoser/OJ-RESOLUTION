#include <iostream>
#include <cstdio>
#include <cstring> 

using namespace std;

const int maxn = 105;

char map[maxn][maxn];
int index[maxn][maxn];
int n, m;

int dirx[4] = {0, 0, -1, 1};
int diry[4] = {-1, 1, 0, 0};

void dfs(int r, int c, int id){
	if(r >= n || r < 0 || c >= m || c < 0) return;
	if(map[r][c] != '@' || index[r][c] > 0) return;
	index[r][c] = id;
	for(int i = 0; i < 4; ++i){
		for(int j = 0; j < 4; ++j){
			if(dirx[i] != 0 || diry[i] != 0) dfs(r + dirx[i], c + diry[j], id);
		}
	}
}
int main(){
	while(scanf("%d%d", &n, &m) != EOF && n && m){
		memset(index, 0, sizeof(index));
		int ans = 0; 
		for(int i = 0; i < n; ++i) scanf("%s", map[i]);
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				if(index[i][j] == 0 && map[i][j] =='@') dfs(i, j, ++ans);
			}
		}
		printf("%d\n", ans); 
	}
	return 0;
} 