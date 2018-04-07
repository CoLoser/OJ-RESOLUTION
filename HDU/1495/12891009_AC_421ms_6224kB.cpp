#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue> 
using namespace std;

const int maxn = 105;

struct node{
	int s, n, m;
	int svalue, nvalue, mvalue;
	int step;
	void setData(int ss, int nn, int mm){
		s = ss;
		n = 0;
		m = 0;
		svalue = ss;
		nvalue = nn;
		mvalue = mm;
		step = 0;
	}
} p;

int mark[maxn][maxn][maxn];

bool isOk(int s, int n, int m){
	if(s == n && m == 0) return true;
	if(s == m && n == 0) return true;
	if(m == n && s == 0) return true;
	return false;
}

void pourWater(int *a, int *b, int *av, int *bv, int *step){
	if(*a > 0){
		if(*a >= *bv - *b){
			*a = *a - (*bv - *b);
			*b = *bv;
			*step =*step + 1;
		}else{
			*b = *a + *b;
			*a = 0;
			*step = *step + 1;
		}
	}
	return ;	
}
int bfs(){
	queue<node> q;
	q.push(p);
	while(!q.empty()){
		node t = q.front();
		q.pop();
				
		p = t;
		pourWater(&p.s, &p.n, &p.svalue, &p.nvalue, &p.step);
		if(!mark[p.s][p.n][p.m]){
			q.push(p);
			mark[p.s][p.n][p.m] = 1;
		}
		if(isOk(p.s, p.n, p.m)) return p.step;
		
		p = t;	
		pourWater(&p.s, &p.m, &p.svalue, &p.mvalue, &p.step);
		if(!mark[p.s][p.n][p.m]){
			q.push(p);
			mark[p.s][p.n][p.m] = 1;
		}
		if(isOk(p.s, p.n, p.m)) return p.step;
		
		p = t;
		pourWater(&p.n, &p.m, &p.nvalue, &p.mvalue, &p.step);
		if(!mark[p.s][p.n][p.m]){
			q.push(p);
			mark[p.s][p.n][p.m] = 1;
		}
		if(isOk(p.s, p.n, p.m)) return p.step;
				
		p = t;
		pourWater(&p.n, &p.s, &p.nvalue, &p.svalue, &p.step);
		if(!mark[p.s][p.n][p.m]){
			q.push(p);
			mark[p.s][p.n][p.m] = 1;
		}
		if(isOk(p.s, p.n, p.m)) return p.step;
						
		p = t;	
		pourWater(&p.m, &p.s, &p.mvalue, &p.svalue, &p.step);
		if(!mark[p.s][p.n][p.m]){
			q.push(p);
			mark[p.s][p.n][p.m] = 1;
		}
		if(isOk(p.s, p.n, p.m)) return p.step;
		
		p = t;
		pourWater(&p.m, &p.n, &p.mvalue, &p.nvalue, &p.step);
		if(!mark[p.s][p.n][p.m]){
			q.push(p);
			mark[p.s][p.n][p.m] = 1;
		}
		if(isOk(p.s, p.n, p.m)) return p.step;


	}
	return -1;
	
}
int main(){
	int s1, n1, m1;
	while(scanf("%d%d%d", &s1, &n1, &m1) != EOF && s1 + m1 + n1 != 0){
		if(s1 % 2 != 0){
			printf("NO\n");
			continue;
		}
		
		memset(mark, 0, sizeof(mark));
		p.setData(s1, n1, m1);
		
		int ans = bfs();
		if(ans > 0) printf("%d\n", ans);
		else printf("NO\n");
	}
	return 0;
}