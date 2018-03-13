#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int SIZE = 650;
const int maxn = 2100;
struct node{
	int father;
	int relation; // 1 表示赢了父类, 2 表示输了父类, 0 表示和父类平手 
}pic[SIZE];

struct Activity{
	int u, v;
	int val;
}ac[maxn];

int mark[SIZE];

void init(){
	for(int i = 0; i < SIZE; ++i){
		pic[i].father = i;
		pic[i].relation = 0;
	} 
} 
int find(int p){
	if(p == pic[p].father){
		return p;
	}else{
		int x = pic[p].father;
		pic[p].father = find(pic[p].father);
		pic[p].relation = (pic[p].relation + pic[x].relation) % 3;
		return pic[p].father;
	}
}
int main(){
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF){
		int a, b, c;
		char d;
		memset(mark, -1, sizeof(mark));
		for(int i = 0; i < m; ++i){
			scanf("%d%c%d", &a, &d, &b);
			ac[i].u = a;
			ac[i].v = b;
			if(d == '<') ac[i].val = 1;
			else if(d == '>') ac[i].val = 2;
			else if(d == '=') ac[i].val = 0; 
		}
		
		
		
		for(int i = 0; i < n; ++i){
			init();
			
			for(int j = 0; j < m; ++j){
				a = ac[j].u;
				b = ac[j].v;
				c = ac[j].val;
				if(a == i || b == i) continue;
				
				int x = find(a);
				int y = find(b);
				
				if(x == y){
					int r = (pic[b].relation - pic[a].relation + 3) % 3;
					
					if(r != c){
						mark[i] = j + 1;
						break; 
					}
				}else{
					pic[y].father = x;
					pic[y].relation = (pic[a].relation - pic[b].relation + c +3)%3;
				}
			}
		}
		int cnt = 0, a1 = 0, a2 = 0;
		for(int i = 0; i < n; ++i){
			if(mark[i] == -1){
				cnt ++;
				a1 = i;
			}
			a2 = max(a2, mark[i]);
		}
		if(cnt==0) cout<<"Impossible\n"; 
        else if(cnt>1) cout<<"Can not determine\n";  
        else printf("Player %d can be determined to be the judge after %d lines\n",a1,a2);
	}
	return 0;
}