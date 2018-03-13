#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int n, k, times;
const int maxn = 1000010;
struct node{
	int position;
	int times;
}p;
int visit[maxn];
queue<node> q; 

void bfs(){
	int x, Times;
	while(!q.empty()){
		node t = q.front();
		q.pop();
		x = t.position;
		Times = t.times;
		if(x == k){
			cout << Times <<endl;
			return ;
		}
		if(x >= 1 && !visit[x - 1]){
			node nd;
			visit[x - 1] = 1;
			nd.position = x - 1;
			nd.times = Times + 1;
			q.push(nd);
		}
		if(x <= k && !visit[x + 1]){
			node nd;
			visit[x + 1] = 1;
			nd.position = x + 1;
			nd.times = Times + 1;
			q.push(nd);
		}
		if(x <= k && !visit[2 * x]){
			node nd;
			visit[2 * x] = 1;
			nd.position = 2 * x;
			nd.times = Times + 1;
			q.push(nd); 
		}
	}
}
int main(){
	while(scanf("%d%d", &n, &k) != EOF){
		p.position = n;
		p.times = 0;
		q.push(p);
		memset(visit, 0, sizeof(visit));
		bfs();
	}
}