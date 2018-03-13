#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;
const int maxn = 105;

stack<int> cards[maxn];
int dis[maxn];
int array[maxn];
int l, r;
void init(){
	for(int i = 0; i < maxn; ++i){
		while(!cards[i].empty()) cards[i].pop();
	}
	for(int i = 0; i < maxn; ++i){
		cards[i].push(i);
	}
	memset(dis, 0, sizeof(dis));
	
}
void Print(int n){
	cout << "-------------" <<endl;
	for(int i = 1; i <= n; ++i){
		printf("%d ", array[i]);
	}
	cout <<endl;
	for(int i = 1; i <= n; ++i){
		printf("%d ", dis[i]);
	}
	cout <<endl;
	cout << "-------------" <<endl;
}
int main(){
	int n, m;
	int sum = 1;
	while(scanf("%d", &n) != EOF && n){
		char key;
		init();
		getchar();
		
		for(int i = 1; i <= n; ++i){
			scanf("%c", &key);
			if(key == 'U') dis[i] = 1;
			else dis[i] = -1;
		}
		l = 1;
		r = n;
		getchar();
		for(int i = 0; i <= n - 2; ++i){
			scanf("%c", &key);
			if(key == 'L'){
				while(!cards[l].empty()){
					cards[l+1].push(cards[l].top());
					cards[l].pop();
				}
				for(int j = 0; j <= l; ++j){
					dis[j] = -dis[j];
				}
				l++;
			}else {
				while(!cards[r].empty()){
					cards[r-1].push(cards[r].top());
					cards[r].pop();
				}
				for(int j = n; j >= r; --j){
					dis[j] = -dis[j];
				}
				r--;
			}
		}
		for(int i = 1; i <= n; ++i){
			array[i] = cards[r].top();
			cards[r].pop();
		}
		//Print(n);
		scanf("%d", &m);
		printf("Pile %d\n", sum++);
		int p;
		while(m--){
			scanf("%d", &p);
			printf("Card %d is a face ", p);
			if(dis[array[p]] == 1) printf("up ");
			else if(dis[array[p]] == -1)printf("down ");
			printf("%d.\n", array[p]);
		}
	}
	return 0;
}