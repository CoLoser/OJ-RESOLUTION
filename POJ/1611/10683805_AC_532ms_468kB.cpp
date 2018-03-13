#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
const int STUDENT_SIZE = 30010;
int pic[STUDENT_SIZE];
int group[STUDENT_SIZE];
bool mark[STUDENT_SIZE];
int MAX,MIN;
using namespace std;
void init(){
	for(int i = 0; i < STUDENT_SIZE; ++i){
		pic[i] = i;
	}
	memset(group, 0, sizeof(group));
	memset(mark, false, sizeof(mark));
	MAX = -1;
	MIN = STUDENT_SIZE;
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
void MaxMin(int a, int b){
	MAX = max(a, MAX); 
	MAX = max(b, MAX);
	MIN = min(a, MIN);
	MIN = min(b, MIN);
}
int main(){
	int n,m;
	while(scanf("%d%d", &n, &m) != EOF && !(m == 0 && n == 0)){	
		init();
		int num, cnt = 0;
		while(m--){
			scanf("%d", &num);
			for(int i = 0; i < num; i ++){
				scanf("%d", &group[i]);		
			}
			for(int i = 0, j = 1; i < num - 1, j < num; ++i, ++j){
				Union(group[i],group[j]);
				MaxMin(group[i],group[j]);
			}
			//cout << "MAX= "<<MAX << "MIN= " <<MIN <<endl;
		}
		for(int i = MIN; i <= MAX; ++i){
			int x = find(0);
			int y = find(i);
			//cout << "x= " <<x<<"y= "<<y<<endl; 
			if(mark[i] && x == y){
				cnt ++;
			}
		}
		if(cnt == 0) cnt++; 
		printf("%d\n", cnt); 
	}			
	return 0;
}