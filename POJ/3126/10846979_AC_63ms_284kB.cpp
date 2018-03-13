#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;

const int maxn = 10005;

struct node{
	int value;
	int cost;
	node(int v, int c){
		cost = c;
		value = v;
	}
	node(){
	}
}p;
queue<node> q;
int visit[maxn];
int a, b;
bool isPrime(int p){
	int flag = true;
	if(p == 0 || p == 1) flag = false;
	else for(int i = 2; i <= (int)sqrt(p + 0.5); i ++){
			if(p % i == 0){
				flag = false;
				break;
			}
		}
	return flag;
}
void queue_clear(){
	while(!q.empty()) q.pop();
	return;
}
void bfs(){
	int x, cnt;
	while(!q.empty()){
		node t = q.front();
		q.pop();
		x = t.value;
		cnt = t.cost;
		if(x == b){
			printf("%d\n", cnt);
			return ;
		}
		
		//个位
		for(int i = 1; i <= 9; i ++){
			int tem = x / 10 * 10 + i;
			if(tem != x && !visit[tem] && isPrime(tem)){
				visit[tem] = 1;
				q.push(node(tem, cnt + 1)); 
			}
		} 
		
		//十位
		
		for(int i = 0; i <= 9; ++i){
			int tem =  x / 100 * 100 + i * 10 + x % 10;
			if(tem != x && !visit[tem] && isPrime(tem)){
				visit[tem] = 1;
				q.push(node(tem, cnt + 1)); 
			}
		} 
		
		//百位
		
		for(int i = 0; i <= 9; ++i){
			int tem = x / 1000 * 1000 + x % 100 + i * 100;
			if(tem != x && !visit[tem] && isPrime(tem)){
				visit[tem] = 1;
				q.push(node(tem, cnt + 1)); 
			}
		} 
		
		//千位
		
		for(int i = 1; i <= 9; ++i){
			int tem = x % 1000 + i * 1000;
			if(tem != x && !visit[tem] && isPrime(tem)){
				visit[tem] = 1;
				q.push(node(tem, cnt + 1)); 
			}
		} 
	}
	printf("Impossible\n");
	return ;
}
int main(){
	int n;
	scanf("%d", &n);
	while(n--){
		scanf("%d%d", &a, &b);
		memset(visit, 0, sizeof(visit));
		queue_clear();
		visit[a] = 1;
		p.value = a;
		p.cost = 0;
		q.push(p);
		bfs();
	}
	return 0;
}