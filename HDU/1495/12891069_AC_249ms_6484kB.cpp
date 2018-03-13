#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN = 105;
struct _Node{
	int a, b, c, step;
	_Node(){
	}
	_Node(int _a, int _b, int _c, int _step)
	{
		a = _a; b = _b; c = _c; step = _step; 
	}
};
int s, n, m;
int visit[MAXN][MAXN][MAXN];
void pour(int *a, int *b, int *av, int *bv){
	if(*a > 0){
		int need = *bv - *b;
		if(need > *a){
			*b = *a + *b;
			*a = 0;
		}else{
			*b = *bv;
			*a = *a - need;
		}
	}
	return ;	
}

bool isok(int a, int b, int c)
{
	if(a == b && c == 0) return 1;
	if(a == c && b == 0) return 1;
	if(b == c && a == 0) return 1;
	return 0;
}
void bfs()
{
	memset(visit, 0, sizeof(visit));
	queue<_Node> q;
	q.push(_Node(s, 0, 0, 0));
	visit[s][0][0] = 1;
	
	while(!q.empty())
	{
		_Node u = q.front(); q.pop();
		int a = u.a, b = u.b, c = u.c, step = u.step;
		if(isok(a, b, c)){
			cout << step << endl;
			return ; 
		}
		//a->b;
		pour(&a, &b, &s, &n);
		if(!visit[a][b][c]) q.push(_Node(a, b, c, step + 1)), visit[a][b][c] = 1;
		
		//b->a;
		a = u.a; b = u.b; c = u.c; step = u.step;
		pour(&b, &a, &n, &s);
		if(!visit[a][b][c]) q.push(_Node(a, b, c, step + 1)), visit[a][b][c] = 1;
	
		//a->c;
		a = u.a; b = u.b; c = u.c; step = u.step;
		pour(&a, &c, &s, &m);
		if(!visit[a][b][c]) q.push(_Node(a, b, c, step + 1)), visit[a][b][c] = 1;
	
		//c->a
		a = u.a; b = u.b; c = u.c; step = u.step;
		pour(&c, &a, &m, &s);
		if(!visit[a][b][c]) q.push(_Node(a, b, c, step + 1)), visit[a][b][c] = 1;
		
		//b->c;
		a = u.a; b = u.b; c = u.c; step = u.step;
		pour(&b, &c, &n, &m);
		if(!visit[a][b][c]) q.push(_Node(a, b, c, step + 1)), visit[a][b][c] = 1;
		
		//c->b;
		a = u.a; b = u.b; c = u.c; step = u.step;
		pour(&c, &b, &m, &n);
		if(!visit[a][b][c]) q.push(_Node(a, b, c, step + 1)), visit[a][b][c] = 1;
	}
	printf("NO\n");
} 
int main()
{
	while(cin >> s >> n >> m && m + s + n)
	{
		if(s % 2 != 0) printf("NO\n");
		else bfs();
	}
}