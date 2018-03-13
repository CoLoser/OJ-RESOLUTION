#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

char key[10];
char op[10];

int dist[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
char strpath[10]={'d','u','r','l'};
int factor[10];
int visit[400000];
struct _Node
{
	int val, pos;
	
	_Node(){
	}
	_Node(int _val, int _pos)
	{
		val = _val;
		pos = _pos;
	}
};

struct _Path{
	int from, dist;
} path[400000];

int cantor()
{
	int res = 0;
	
	for(int i = 0; key[i]; ++i)
	{
		for(int j = i + 1; key[j]; ++j)
			if(key[i] > key[j]) res += factor[8 - i];
	}
	return res;
}

void cantor_reverse(int val)
{
	int vis[10], tmp[10];
	memset(vis, 0, sizeof(vis));
	
	for(int i = 0; i < 9; ++i) tmp[i] = val/factor[8 - i], val %= factor[8 - i];
	
	for(int i = 0; i < 9; ++i)
	{
		int num = 0;
		for(int j = 0; j < 9; ++j)
		{
			if(vis[j] == 0) num++;
			
			if(num == tmp[i] + 1)
			{
				vis[j] = 1;
				key[i] = '0' + j + 1;
				if(key[i] == '9') key[i] = 'x';
				break;
			}
		}
	}
}

void bfs()
{
	queue<_Node> q;
	q.push(_Node(0, 8));
	path[0].from = -1; path[0].dist = -1; visit[0] = 1;
	
	while(!q.empty())
	{
		_Node x = q.front();
		q.pop();
		
		int a = x.pos/3, b = x.pos%3;
		cantor_reverse(x.val);
		
		//cout << "---" <<endl;
		for(int i = 0; i < 4; ++i)
		{
			int dx = a + dist[i][0], dy = b + dist[i][1];
			
			if(!(dx <= 2 && dx >= 0 && dy <= 2 && dy >= 0)) continue;
			
			int curpos = 3 * dx + dy;
			
			swap(key[curpos], key[x.pos]);
			
			int t = cantor();
			
			if(visit[t]){
				swap(key[curpos], key[x.pos]);
				continue;
			}
			
			path[t].from = x.val;
			path[t].dist = i;
			
			q.push(_Node(t, curpos));
			visit[t] = 1;
			
			swap(key[curpos], key[x.pos]);
		}
	}
	return ;
}
void INIT()
{
	factor[0] = 1;
	for(int i = 1; i <= 8; ++i) factor[i] = i * factor[i-1];
	memset(visit, 0, sizeof(visit));	
}

int main()
{
	INIT();
	bfs();
	while(scanf("%s", op) != EOF)
	{
		key[0] = op[0];
		for(int i = 1; i <= 8; ++i)
		{
			scanf("%s", op);
			key[i] = op[0];
		 } 
		 
		int t = cantor();
		
		//cantor_reverse(t);
		//cout << key << endl;
		//cout << t << endl;
		
		 if(visit[t] == 0) cout << "unsolvable" << endl;
		 else{
		 	while(1)
			 {
			 	if(path[t].from == -1) break;
				printf("%c", strpath[path[t].dist]);
			 	t = path[t].from;
			 }
			 cout << endl;
		 } 
		 
	}
}