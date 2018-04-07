#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;

struct _Node{
	int val, depth;
	_Node(){
	}
	_Node(int _val, int _depth)
	{
		val = _val; depth = _depth;
	}
};

int prime[10000];

void getPrime()
{
	memset(prime, 0, sizeof(prime));
	prime[1] = 1;
	prime[0] = 1;
	for(int i = 2; i <= sqrt(10000); ++i) if(!prime[i])
		for(int j = i * i; j < 10000; j += i) prime[j] = 1;
}

void bfs(int start, int end)
{
	queue<_Node> q;
	q.push(_Node(start, 0));
	prime[start] = 2;
	
	while(!q.empty())
	{
		_Node x = q.front(); q.pop();
		
		int cnt = x.depth;
		if(x.val == end)
		{
			printf("%d\n", x.depth);
			return;
		}
		
		//cout << x.val << endl; 
		//个位
		for(int i = 1; i <= 9; i ++){
			int tem = x.val / 10 * 10 + i;
			if(tem != x.val && !prime[tem]){
				prime[tem] = 1;
				q.push(_Node(tem, cnt + 1)); 
			}
		} 
		
		//十位
		
		for(int i = 0; i <= 9; ++i){
			int tem =  x.val / 100 * 100 + i * 10 + x.val % 10;
			if(tem != x.val && !prime[tem]){
				prime[tem] = 1;
				q.push(_Node(tem, cnt + 1)); 
			}
		} 
		
		//百位
		
		for(int i = 0; i <= 9; ++i){
			int tem = x.val / 1000 * 1000 + x.val % 100 + i * 100;
			if(tem != x.val && !prime[tem]){
				prime[tem] = 1;
				q.push(_Node(tem, cnt + 1)); 
			}
		} 
		
		//千位
		
		for(int i = 1; i <= 9; ++i){
			int tem = x.val % 1000 + i * 1000;
			if(tem != x.val && !prime[tem]){
				prime[tem] = 1;
				q.push(_Node(tem, cnt + 1)); 
			}
		} 
	}
	printf("Impossible\n");
	return;
}

int main()
{
	int t;
	int a, b;
	cin >> t;
	
	while(t--)
	{	
		getPrime();	
		cin >> a >> b;
		bfs(a, b);
	}
}