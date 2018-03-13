#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

const int maxn = 1010;

char map[maxn][maxn];
int visit[maxn][maxn];
int times[maxn][maxn];

int row, col;
int Step;


struct node{
	int r, c;
	int step;
	node(int rr, int cc, int ss){
		r = rr;
		c = cc;
		step = ss;
	}
	node(){
		
	}
};

node Joe, Fire;
queue<node> q;

void clear_queue(){
	while(!q.empty()){
		q.pop();
	}
}

bool legal(int x, int y){
	if(x >= 0 && x < row && y >= 0 && y < col) return true;
	else return false;
}

bool isEscape(int x, int y){
	if(x == 0 || x == row - 1 || y == 0 || y == col - 1) return true;
	else return false;
}

void fireBfs(){
	int i;
	int tx, ty, TIME;
	while(!q.empty()){
		node nd = q.front();
		q.pop();
		
		for(int i = 0; i < 4; ++i){
			tx = nd.r + dx[i];
			ty = nd.c + dy[i];
			TIME = nd.step + 1;
			if(legal(tx, ty) && (map[tx][ty] == '.' || map[tx][ty] == 'J') && visit[tx][ty] == 0){
				visit[tx][ty] = 1;
				q.push(node(tx, ty, TIME));
				times[tx][ty] = TIME;
			}
		}
	}
}
int joeBfs(){
	int tx, ty, TIME;
	clear_queue();
	q.push(Joe);
	visit[Joe.r][Joe.c] = 1;
	while(!q.empty()){
		node nd = q.front();
		q.pop();
		
		if(isEscape(nd.r, nd.c)){
			Step = nd.step + 1;
			return 1; 
		} 
		for(int i = 0; i < 4; ++i){
			tx = nd.r + dx[i];
			ty = nd.c + dy[i];
			TIME = nd.step + 1;
			if(legal(tx, ty) && map[tx][ty] == '.' &&visit[tx][ty] == 0 && TIME < times[tx][ty]){
				visit[tx][ty] = 1;
				q.push(node(tx, ty, TIME));
			}
		}
	}
	return 0;	
}

 
int main(){
	int n;
	scanf("%d", &n);
	while(n--){
		clear_queue();

		scanf("%d%d", &row, &col);
		for(int i = 0; i < row; ++i){
			cin >> map[i];
			for(int j = 0; j < col; ++j){
				if(map[i][j] == 'F'){
					q.push(node(i, j, 0));
					times[i][j] = 0;
					visit[i][j] = 1;
				}
				if(map[i][j] == 'J'){
					Joe.r = i;
					Joe.c = j;
					Joe.step = 0;
				}
			}
		}
		memset(times, 10000, sizeof(times));
		memset(visit, 0, sizeof(visit));
		fireBfs();
		memset(visit, 0, sizeof(visit));
		int flag = joeBfs();
		if(flag) cout << Step <<endl;
		else cout << "IMPOSSIBLE" <<endl;
	}
}