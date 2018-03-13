#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 200010;
int pic[maxn];
int value[maxn];
void init(){
	for(int i = 0; i < maxn; ++i){
		pic[i] = i;
	}
	memset(value, 0, sizeof(value));
}
int find(int p){
	if(pic[p] == p){
		return p;
	}else{
		int root = find(pic[p]);
		value[p] += value[pic[p]];
		return pic[p] = root;
	}
}
int main(){
	int n, m, ans = 0;
	while(scanf("%d%d", &n, &m) == 2){
		init();
		ans = 0;
		while(m--){
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			a--;
			int x = find(a);
			int y = find(b);
			if(x != y){
				pic[y] = x;
				value[y] = value[a] - value[b] + c;
			}else{
				if(value[b] - value[a] != c) ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}