#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 105;
struct node{
	int rank;
	int value;
	node(int vv, int rr){
		rank = rr;
		value = vv;
	}
	node(){
	}
};
queue<node> q;
void init(){
	while(!q.empty()) q.pop();
}
void SortQueue(int maxRank){
	node current = q.front();
	while(maxRank != current.rank){
		q.push(current);
		q.pop();
		current = q.front();
	}
}
int findMaxRank(){
	queue<node> x;
	x = q;
	int maxRank = -1;
	while(!x.empty()){
		maxRank = max(maxRank, x.front().rank);
		x.pop();
	}
	return maxRank;
}
void Print(){
	queue<node> x;
	x = q;
	while(!x.empty()){
		cout << "value = " << x.front().value << "rank = " << x.front().rank<<endl;
		x.pop();
	}
}
int main(){
	int t;
	int n, m;
	int sum = 0;
	int maxRank = -1;
	scanf("%d", &t);
	while(t--){
		sum = 0;
		maxRank = -1;
		int r;
		init();
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; ++i){
			scanf("%d", &r);
			q.push(node(i, r));
			maxRank = max(maxRank, r);
		}
		maxRank = findMaxRank();
		SortQueue(maxRank);
		node current = q.front();
		if(current.value == m) sum ++;
		while(current.value != m){
			maxRank = findMaxRank();
			SortQueue(maxRank);
			current = q.front();
			q.pop();
			
			sum ++;
		}
		printf("%d\n", sum);
	}
}