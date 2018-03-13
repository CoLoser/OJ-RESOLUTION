#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 110;

char pic[maxn][maxn];
int mark[maxn][maxn];
int n, m;

void dfs(int row, int col, int id){
	if(row < 0 || row >= n || col < 0 || col >= m) return ;
	if(mark[row][col] > 0 || pic[row][col] != '@') return ;
	
	mark[row][col] = id;
	
	for(int i = -1; i <= 1; ++ i){
		for(int j = -1; j <= 1; ++j){
			if(i != 0 || j != 0) dfs(row + i, col + j, id);
		}
	}
}
int main(){
	while(scanf("%d%d", &n, &m) == 2 && m && n){
		memset(mark, 0, sizeof(mark));
		for(int i = 0; i < n; ++i) scanf("%s", pic[i]);
		
		int cnt = 0;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				if(pic[i][j] == '@' && mark[i][j] == 0) dfs(i, j, ++ cnt);
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}