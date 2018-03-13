#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int FRIEND_SIZE = 1010;
int pic[FRIEND_SIZE];
bool mark[FRIEND_SIZE];
void init(){
	for(int i = 0; i < FRIEND_SIZE; ++i){
		pic[i] = i;
	}
	memset(mark, false, sizeof(mark));
}
int find(int p){
	if(p == pic[p]) return p;
	else return find(pic[p]);
}
void Union(int a, int b){
	int x = find(a);
	int y = find(b);
	mark[a] = true;
	mark[b] = true;
	if(x != y){
		pic[x] = y;
	}
}
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		init();
		int m, n, cnt = 0;
		scanf("%d%d", &n, &m);
		for(int i = 0; i < m; ++i){
			int a, b;
			scanf("%d%d", &a, &b);
			Union(a, b);
		}
		for(int i = 1; i <= n; i ++){
			if(i == pic[i]){
				cnt++;
			}
		}
		printf("%d\n", cnt); 
	}
} 