#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
int main(){
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF){
		if(m == 0 && n == 0) return 0;
		char map[n+2][m+2];
		int mark[n+2][m+2];
		memset(mark, 0, sizeof(mark));
		memset(map, '!', sizeof(map));
		for(int i = 1; i <= n; ++i){
			scanf("%s", map[i]+1);
		}
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= m; ++j){
				if(map[i][j] == '.'){
					if(map[i+1][j-1] == '*') mark[i][j]++;
					if(map[i+1][j] == '*') mark[i][j]++;
					if(map[i+1][j+1] == '*') mark[i][j]++;
					if(map[i-1][j-1] == '*') mark[i][j]++;
					if(map[i-1][j] == '*') mark[i][j]++;
					if(map[i-1][j+1] == '*') mark[i][j]++;
					if(map[i][j-1] == '*') mark[i][j]++;
					if(map[i][j+1] == '*') mark[i][j]++;
					
				}
			}
		}
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= m; ++j){
				if(map[i][j] == '.'){
					printf("%d", mark[i][j]);
				}else{
					printf("%c", map[i][j]);
				}
			}
			printf("\n");
		}
		printf("\n");
	}
}