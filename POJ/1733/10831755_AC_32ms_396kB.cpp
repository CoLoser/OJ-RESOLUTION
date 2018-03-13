#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

int n, m;
const int maxn = 5e4 + 5;
int pic[maxn], father[maxn], rank[maxn];
int cnt;

struct node{
	int x, y;
	int value;
};
node edge[maxn];

void init(){
	for(int i = 0; i <= cnt; ++i){
		father[i] = i;
		rank[i] = 0;
	}
}

int search(int x, int len){ //二分查找
	int left = 0, right = len, mid;
	while(left + 1 < right){
		mid = (right + left) >> 1;
		if(pic[mid] == x)
			return mid;
		if(pic[mid] < x)
			left = mid;
		else
			right = mid;
	}
	if(pic[left] == x)
		return left;
	else 
		return right;
}

int find(int p){
	if(p != father[p]){
		int per = father[p];
		father[p] = find(father[p]);
		rank[p] = (rank[p] + rank[per] + 2) % 2;
	}
	return father[p];
}

int main(){
	char key[20];
	while(scanf("%d%d", &n, &m) != EOF){
		cnt = 0;
		for(int i = 0; i < m; ++i){			
			scanf("%d%d%s", &edge[i].x, &edge[i].y, key);
			edge[i].x--;
			if(key[0] == 'e') edge[i].value = 0;
			else if(key[0] == 'o') edge[i].value = 1;
			pic[cnt++] = edge[i].x;
			pic[cnt++] = edge[i].y;
		}
		init();
		sort(pic, pic + cnt);
		n = unique(pic, pic + cnt) - pic;
		int i;
		for(i = 0; i < m; i++){
			int nx = search(edge[i].x, n);
			int ny = search(edge[i].y, n);
			int x = find(nx);
			int y = find(ny);
			
			if(x == y){
				if((rank[nx] + rank[ny] + 2) % 2 != edge[i].value){
					printf("%d\n", i);
					break;
				}			
			}else{
				father[y] = x;
				rank[y] = (rank[nx] - rank[ny] + 2 + edge[i].value)%2;
			}
		}
		if(i >= m) printf("%d\n", m);
	}
	return 0;
}