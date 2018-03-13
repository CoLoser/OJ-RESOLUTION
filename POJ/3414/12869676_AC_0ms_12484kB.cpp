#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <stack>
#include <string>
using namespace std;

string strpath[] = {
	"FILL(1)", "FILL(2)", "DROP(1)", "DROP(2)", "POUR(1,2)", "POUR(2,1)"
};

struct _Node{
	int val, depth;
	_Node(){
	};
	_Node(int _val, int _depth){
		val = _val; depth = _depth; 
	}
};
struct _Path{
	int from, idx;
}path[1000005];
int a, b, at, bt, ct;
stack<int> s;
int depth;

int hash(int a, int b)
{
	return a*1000 + b;
}

void reverse_hash(int val)
{
	a = val/1000;
	b = val%1000;
}
int visit[1000005];

bool judge(int end)
{
	if(a == end || b == end) return 1;
	else return 0;
}

void bfs(int start, int end)
{
	queue<_Node> q;
	q.push(_Node(start, 0));
	visit[start] = 1;
	path[start].from = path[start].idx = -1;
	while(!q.empty())
	{
		_Node x = q.front(); q.pop();
		int u = x.val;
		reverse_hash(u);
		if(judge(end)){
			while(path[u].from != -1)
			{
				if(a == 0 && b == 0) break;
				s.push(path[u].idx);
				u = path[u].from;
			}
			cout << x.depth << endl;
			while(!s.empty())
			{
				cout << strpath[s.top()] << endl;
				s.pop();
			}
			return ;
		}
		
		
		//FIll;
		int t = hash(at, b);
		if(a != at && !visit[t])
		{	
			
			q.push(_Node(t, x.depth + 1));
			visit[t] = 1;
			path[t].from = u;
			path[t].idx = 0;
		}
		t = hash(a, bt);
		if(b != bt && !visit[t])
		{		
			q.push(_Node(t, x.depth + 1));
			visit[t] = 1;
			path[t].from = u;
			path[t].idx = 1;
		}
		
		//DROP;
		t = hash(0, b);
		if(a != 0 && !visit[t])
		{	
			q.push(_Node(t, x.depth + 1));
			visit[t] = 1;
			path[t].from = u;
			path[t].idx = 2;
		}
		
		t = hash(a, 0);
		if(b != 0 && !visit[t])
		{	
			q.push(_Node(t, x.depth + 1));
			visit[t] = 1;
			path[t].from = u;
			path[t].idx = 3;
		}
		
		//POUR;
		//a -> b
		if(a > 0 && b < bt)
		{
			int need = bt - b;
			
			
			if(a > need && !visit[hash(a - need, bt)])		//bFILL
			{
				t = hash(a - need, bt);
				q.push(_Node(t, x.depth + 1));
				visit[t] = 1;
				path[t].from = u;
				path[t].idx = 4;
			}else if(a <= need && !visit[hash(0, a + b)]){	//aout
				t = hash(0, a+b);
				q.push(_Node(t, x.depth + 1));
				visit[t] = 1;
				path[t].from = u;
				path[t].idx = 4;
			}
		}
		//b -> a
		if(b > 0 && a < at)
		{
			int need = at - a;
			if(b > need &&  !visit[hash(at, b - need)]) //aFIll
			{
				t = hash(at, b - need);
				q.push(_Node(t, x.depth + 1));
				visit[t] = 1;
				path[t].from = u;
				path[t].idx = 5;
			}else if(b <= need && !visit[hash(a + b, 0)]){	//bout
				t = hash(a + b, 0);
				q.push(_Node(t, x.depth + 1));
				visit[t] = 1;
				path[t].from = u;
				path[t].idx = 5;
			}
		}
	}	
	cout << "impossible" << endl;
	return;
}
int main()
{
	while(cin >> at >> bt >> ct)
	{
		memset(visit, 0, sizeof(visit));
		memset(path, 0, sizeof(path));
		bfs(hash(0, 0), ct);
	 } 
}