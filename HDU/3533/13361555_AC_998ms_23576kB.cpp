#include <iostream>
#include <cstdio>
#include <queue>
using  namespace  std;

const int  MAXN = 105;
const int  UPDATE[][2] = {{1,0},{0,1},{0,0}};
int  N,M,K,E;
bool  times[MAXN][MAXN][1005];
bool  visit[MAXN][MAXN][1005];
bool  castle[MAXN][MAXN];
struct  _Node {
	int  x,y,t,e;
	bool  check(void) {
		if(x < 0 || x > N || y < 0 || y > M || t > E || visit[x][y][t] || castle[x][y] ||
		        times[x][y][t] || !e || N - x + M - y > e)
			return  false;
		return  true;
	}
};
struct  Cas {
	char  ch;
	int  t,v,x,y;
};

void init() {
	for(int i = 0; i < MAXN; ++i)
		for(int j = 0; j < MAXN; ++j) {
			for(int k = 0; k < 1005; ++k) {
				times[i][j][k] = 0;
				visit[i][j][k] = 0;
			}
			castle[i][j] = 0;
		}

}
void  deal(char ch,int t,int v,int x,int y) {
	if(ch == 'W') {
		int  stop = 0;
		for(int j = y - 1; j >= 0; j --)
			if(castle[x][j]) {
				stop = j;
				break;
			}
		for(int j = y - v,ini = 1; j >= stop; j -= v,ini ++)
			for(int k = ini; k <= E; k += t)
				times[x][j][k] = true;

	} else  if(ch == 'E') {
		int  stop = M;
		for(int j = y + 1; j <= M; j ++)
			if(castle[x][j]) {
				stop = j;
				break;
			}

		for(int j = y + v,ini = 1; j <= stop; j += v,ini ++)
			for(int k = ini; k <= E; k += t)
				times[x][j][k] = true;
	} else    if(ch == 'N') {
		int    stop = 0;
		for(int j = x - 1; j >= 0; j --)
			if(castle[j][y]) {
				stop = j;
				break;
			}
		for(int j = x - v,ini = 1; j >= stop; j -= v,ini ++)
			for(int k = ini; k <= E; k += t)
				times[j][y][k] = true;
	} else    if(ch == 'S') {
		int    stop = N;
		for(int j = x + 1; j <= N; j ++)
			if(castle[j][y]) {
				stop = j;
				break;
			}
		for(int j = x + v,ini = 1; j <= stop; j += v,ini ++)
			for(int k = ini; k <= E; k += t)
				times[j][y][k] = true;
	}
}

void  bfs() {
	_Node  start;
	start.x = start.y = start.t = 0;
	start.e = E;
	queue<_Node>    que;
	que.push(start);
	visit[0][0][0] = true;

	while(!que.empty()) {
		_Node cur = que.front();
		que.pop();

		for(int i = 0; i < 3; i ++) {
			_Node next = cur;
			next.x += UPDATE[i][0];
			next.y += UPDATE[i][1];
			next.t ++;
			next.e --;
			if(!next.check())
				continue;
			if(next.x == N && next.y == M) {
				printf("%d\n",next.t);
				return  ;
			}
			visit[next.x][next.y][next.t] = true;
			que.push(next);
		}
	}
	printf("Bad luck!\n");
}
int  main(void) {
	Cas  temp[105];
	while(scanf("%d%d%d%d",&N,&M,&K,&E) != EOF) {
		init();

		for(int i = 0; i < K; i ++) {
			scanf(" %c%d%d%d%d",&temp[i].ch,&temp[i].t,&temp[i].v,&temp[i].x,&temp[i].y);
			castle[temp[i].x][temp[i].y] = true;
		}
		if(castle[N][M]) {
			printf("Bad luck!\n");
			continue;
		}
		for(int i = 0; i < K; i ++)
			deal(temp[i].ch,temp[i].t,temp[i].v,temp[i].x,temp[i].y);
		bfs();
	}
	return  0;
}

