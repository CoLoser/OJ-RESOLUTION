#include <iostream>
#include <cstdio>
#include <queue>
using namespace  std;

typedef unsigned long long ll;

struct _Node{
	int depth;
	ll val;
	_Node(){
	}
	_Node(int _depth, ll _val)
	{
		depth = _depth; val = _val;
	}
};
void bfs(int t)
{
	queue<_Node> q;
	q.push(_Node(0, 1));
	
	while(!q.empty()){
		_Node x = q.front(); q.pop();
		//cout << x.val << endl;
		if(x.depth == 19) return ;
		if(x.val % t == 0) 
		{
			printf("%I64u\n", x.val);
			return ;
		}
		
		q.push(_Node(x.depth + 1, x.val * 10));
		q.push(_Node(x.depth + 1, x.val * 10 + 1));
	}
}
int main()
{
	int t;
	while(scanf("%d", &t) != EOF && t)
	{
		bfs(t);
	}
	return 0;
}