#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
const int STAR_SIZE = 10010;
const int INQUIRY_SIZE = 50010;
struct Star{
	int ID;
	int POWER;
	void setData(int id, int power){
		ID = id;
		POWER = power;
	}
};
struct Inquiry{
	int a, b;
	int flag;
	int ans;
	void setData(int f, int aa, int bb){
		a = aa;
		b = bb;
		flag = f;
	}
};
Star star[STAR_SIZE];
Inquiry inquiry[INQUIRY_SIZE];
int MAX[STAR_SIZE];
set< pair<int, int> > T;
void init(){
	T.clear();
	for(int i = 0; i < STAR_SIZE; ++i){
		star[i].setData(i, -1);
	}
	for(int i = 0; i < INQUIRY_SIZE; ++i){
		inquiry[i].setData(-1, 0, 0);
		inquiry[i].ans = -1;
	}
	memset(MAX, -1, sizeof(MAX));
} 
int find(int p){
	if(star[p].ID != p){
		int d = star[p].ID;
		star[p].ID = find(star[p].ID);
		MAX[p] = max(MAX[p], MAX[d]);
	}
	return star[p].ID;
}
void Union(int a, int b){
	int x = find(a);
	int y = find(b);
	if(x == y) return;
	if(MAX[x] < MAX[y] || (MAX[x] == MAX[y] && x > y)){
		star[x].ID = y;
	}else{
		star[y].ID = x;
	}	
}
int main(){
	int n, m, q;
	int k = 0;
	while(~scanf("%d", &n)){
		if(k++)puts("");
		init();
		char op[10];
		int a, b;
		for(int i = 0; i < n; ++i){
			scanf("%d", &star[i].POWER);
		}
		scanf("%d", &m);
		for(int i = 0; i < m; ++i){
			scanf("%d%d", &a, &b);
			if(a > b) swap(a, b);			
			T.insert(make_pair(a, b));
		}
		scanf("%d", &q);
		for(int i = 0; i < q; ++i){
			scanf("%s", op);
			if(op[0] == 'q'){
				scanf("%d", &a);
				inquiry[i].setData(0, a, 0);
			}else if(op[0] == 'd'){
				scanf("%d%d", &a, &b);
				if(a > b) swap(a, b);
				T.erase(make_pair(a, b));
				inquiry[i].setData(1, a, b);
			}
		}
		
		for(int i = 0; i < n; ++i){
			MAX[i] = star[i].POWER;
		}
		
		for(set< pair<int, int> >::iterator it = T.begin(); it != T.end(); it++){
			a = (*it).first;
			b = (*it).second;
			Union(a, b);
		}
		for(int i = q - 1; i >= 0; i--){
			if(inquiry[i].flag == 0){
				if(MAX[find(inquiry[i].a)] > star[inquiry[i].a].POWER){
					inquiry[i].ans = star[inquiry[i].a].ID;
				}else{
					inquiry[i].ans = -1;
				}
			}else if(inquiry[i].flag == 1){
				Union(inquiry[i].a, inquiry[i].b);
			}
		}
		for(int i = 0;i < q; i++)
        {
            if(inquiry[i].flag == 0)
            {
                printf("%d\n",inquiry[i].ans);
            }               
        }
	}
	return 0;
}