#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

const int MAXN = 1000;
int dist[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char key[MAXN][MAXN];
struct _Node {
	int x, y;
};
_Node ghosts[2];
int step;
int t, n, m;
bool check(_Node t) {
	if(t.x<1 || t.x>n || t.y<1 || t.y>m) return false;
	for(int i=0; i<2; i++) {
		if(abs(t.x-ghosts[i].x)+abs(t.y-ghosts[i].y)<=2*step || key[t.x][t.y]=='X' || key[t.x][t.y]=='\0') return false;
	}
	return true;
}
queue<_Node> q[2], qt;
bool bfs(int flag, int s, char sta, char en) {
	qt = q[flag];
	for(int i=0; i<s; i++) {
		while(!qt.empty()) {
			_Node u = qt.front();
			qt.pop(), q[flag].pop();
			if(!check(u)) continue;
			for(int i=0; i<4; i++) {
				_Node next = u;
				next.x+=dist[i][0], next.y+=dist[i][1];
				if(!check(next)||key[next.x][next.y]==sta) continue;
				if(key[next.x][next.y]==en) return true;
				key[next.x][next.y]=sta;
				q[flag].push(next);
			}
		}
		qt = q[flag];
	}
	return false;
}

int solove(_Node start, _Node end) {
	step = 0;
	while(!q[0].empty()) q[0].pop();
	while(!q[1].empty()) q[1].pop();
	while(!qt.empty()) qt.pop();
	q[0].push(start), q[1].push(end);
	while(!q[0].empty() && !q[1].empty()) {
		step++;
		bool flag1 = bfs(0,3,'M','G');
		bool flag2 = bfs(1,1,'G','M');
		if(flag1||flag2) return step;
	}
	return -1;
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n >> m;
		memset(key, 'X', sizeof(key));
		_Node start, end;
		for(int k=0,i=1; i<=n; i++) {
			scanf("%s", key[i]+1);
			for(int j=1; j<=m; j++) {
				if(key[i][j]=='M') start.x=i, start.y=j;
				if(key[i][j]=='G') end.x=i, end.y=j;
				if(key[i][j]=='Z') ghosts[k].x=i, ghosts[k].y=j, k++;
			}
		}
		printf("%d\n", solove(start, end));
	}
	return 0;
}