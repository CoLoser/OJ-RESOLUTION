#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int SIZE = 2005;
int bugs[SIZE];
int relation[SIZE];
bool flag;
void init(){
	for(int i = 0; i < SIZE; ++i){
		bugs[i] = i;
	}
	memset(relation, 0, sizeof(relation)); 
	flag = false;
}
int find(int x){
	int p;
	if(x != bugs[x]){
		p = bugs[x];
		bugs[x] = find(bugs[x]);
		relation[x] = (relation[x] + relation[p])%2; //两种不同的状态 0表示同性 1表示异性 
	}
	return bugs[x];
}
void Union(int x, int y){
	int a = find(x);
	int b = find(y);
	if(a != b){
		bugs[a] = b;
		relation[a] = (relation[x] - relation[y] +1) %2;
	}
	find(x);
}
int main(){
	int n, b, a, i = 1;;
	scanf("%d", &n);
	while(n--){
		scanf("%d%d", &b, &a);
		init();
		while(a--){
			int x, y;
			scanf("%d%d", &x, &y);
			if(!flag) Union(x, y);
			if(relation[x] == relation[y]) flag = true;
		}
		printf("Scenario #%d:\n", i++);
		if(flag){
			printf("Suspicious bugs found!\n");  
		}else{
			printf("No suspicious bugs found!\n");
		}
		printf("\n");
	}
	return 0;
}