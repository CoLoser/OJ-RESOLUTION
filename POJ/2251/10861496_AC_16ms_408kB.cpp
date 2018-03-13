#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int dirx[] = {0, 0, 0, 0, -1, 1};
int diry[] = {0, 0, -1, 1, 0, 0};
int dirz[] = {-1, 1, 0, 0, 0, 0};

const int maxn = 31;

char map[maxn][maxn][maxn];
int level, row, col;

struct node{
	int x, y, z;
	int step;
	node(int xx, int yy, int zz, int s){
		x = xx;
		y = yy;
		z = zz;
		step = s;
	}
	node(){
	}
	void setData(int xx, int yy, int zz, int s){
		x = xx;
		y = yy;
		z = zz;
		step = s;
	}
}S, P;

queue<node> q;

bool isLegal(int x, int y, int z){
	if(x >= 0 && x < row && y >= 0 && y < col && z >= 0 && z < level) return true;
	else return false;
}

int visit[maxn][maxn][maxn];

void queue_clear(){
	while(!q.empty()) q.pop();
	return ;
}
int bfs(){
	q.push(S);
	int X, Y, Z, STEP;
	while(!q.empty()){
		node t = q.front();
		q.pop();
		X = t.x;
		Y = t.y;
		Z = t.z;
		STEP = t.step;
		
		int tx, ty, tz;
		for(int i = 0; i < 6; ++i){
			tx = dirx[i] + X;
			ty = diry[i] + Y;
			tz = dirz[i] + Z;
			//printf("%d - %d - %d -- %d\n", tx, ty, tz, !visit[tz][tx][ty] && map[tz][tx][ty] == '.' && isLegal(tx, ty, tz));
			if(!visit[tz][tx][ty] && map[tz][tx][ty] == '.' && isLegal(tx, ty, tz)){
				//cout << "-----------------" <<endl;
				visit[tz][tx][ty] = 1;
				t.step = STEP + 1;
				q.push(node(tx, ty, tz, t.step)); 
			}
			if(map[tz][tx][ty] == 'E') return t.step + 1;
		}
	}
	return -1;
}
int main(){
	while(scanf("%d%d%d", &level, &row, &col) != EOF && level && row && col){
		for(int i = 0; i < level; i ++){
			for(int j = 0; j < row; ++j){
				scanf("%s", map[i][j]);
				for(int k = 0; k < col; ++k){
					if(map[i][j][k] == 'S')  S.setData(j, k, i, 0);
				}
			}
		}
		memset(visit, 0, sizeof(visit));
		queue_clear();
		int x = bfs();
		if(x == -1) printf("Trapped!\n");
		else printf("Escaped in %d minute(s).\n", x);
	} 
}