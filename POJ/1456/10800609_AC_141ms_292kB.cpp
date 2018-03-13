#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 10010;

struct node{
	int time;
	int price;
}ac[maxn];
bool vis[maxn];
bool comp(const node n1, const node n2){
	if(n1.price == n2.price) return n1.time > n2.time;
	return n1.price > n2.price;
}
int main(){
	int n;
	
	while(scanf("%d", &n) != EOF){
		memset(vis, false, sizeof(vis));
		for(int i = 0; i < n; ++i){
			scanf("%d%d", &ac[i].price, &ac[i].time);
		}
		int sum = 0;
		sort(ac, ac+n, comp);
		for(int i = 0; i < n; ++i){
			int tem = ac[i].time;
			for(int j = tem; j >=1; --j){
				if(!vis[j]){
					vis[j] = true;
					sum += ac[i].price;
					break;
				}
			}
		}
		printf("%d\n", sum);
	}
	return 0;
} 