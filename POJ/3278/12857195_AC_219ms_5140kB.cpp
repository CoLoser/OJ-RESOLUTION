#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int visit[1000010];
struct _Node{
	int pos, step;
	
	_Node(){
	}
	_Node(int _pos, int _step)
	{
		pos = _pos;
		step = _step;
	}
};
int bfs(int start, int end)
{
	queue<_Node> q;
	q.push(_Node(start, 0));
	visit[start] = 1;
	
	while(!q.empty())
	{
		_Node x = q.front(); q.pop();
		
		if(x.pos == end)
		{
			return x.step;
		}
		
		int curpos = x.pos;
		
		curpos = x.pos - 1;
		if(!visit[curpos] && x.pos >= 1)
		{	
			visit[curpos] = 1; 
			q.push(_Node(curpos, x.step + 1));
		}
		
		curpos = x.pos + 1;
		if(!visit[curpos] && x.pos < end)
		{
			visit[curpos] = 1; 
			q.push(_Node(curpos, x.step + 1));
		}
		
		curpos = x.pos * 2;
		if(!visit[curpos] && x.pos < end )
		{
			visit[curpos] = 1; 
			q.push(_Node(curpos, x.step + 1));
		}
		
	}
	return -1;
}
int main()
{
	int n, m;
	while(cin >> n >> m)
	{
		memset(visit, 0, sizeof(visit)); 
		int t = bfs(n, m);
		printf("%d\n", t);
	 } 
	 return 0;
}