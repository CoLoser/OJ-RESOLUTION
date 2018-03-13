#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 100010;
int pic[maxn];
bool mark[maxn];
int MAX = 100010,MIN = -1;
int find(int p){
	if(p == pic[p]){
		return p;
	}
	return find(pic[p]);
}
void init(){
	for(int i = 0; i < maxn; ++i){
		pic[i] = i;
	}
	memset(mark, false, sizeof(mark));
}
void MaxMin(int a, int b){
	MAX = max(a, MAX); 
	MAX = max(b, MAX);
	MIN = min(a, MIN);
	MIN = min(b, MIN);
}
int main(){
	int a,b;
	while(scanf("%d", &a) == 1 && a != -1){
		bool flag=true, flag2 = true, flag3 = true;
		init();	
		while(scanf("%d", &b)==1 && b != 0){
			flag3 = false;  
			if(flag2){
				MAX=a;
				MIN=b;
				flag2 = false;
			}
			MaxMin(a,b);
			mark[a] = true;
			mark[b] = true;	
			a = find(a);
			b = find(b);
			if(a == b){
				flag  = false;
			}else{
				pic[a] = b;
			}
			scanf("%d", &a); 
		}	
		int cnt=0;
		if(flag3 && a == 0 && b == 0){
			printf("Yes\n");
		}else if(flag){			
			for(int i = MIN; i <= MAX; ++i){
				if(mark[i] && pic[i] == i) {
					cnt++;					
				}
			}
			if(cnt == 1){
				printf("Yes\n");
			}else{
				printf("No\n");
			}
			
		}else{
			printf("No\n");
		}		
	}
	return 0;
}