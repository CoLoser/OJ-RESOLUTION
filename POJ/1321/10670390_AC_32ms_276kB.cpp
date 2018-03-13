#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 10;

char pic[maxn][maxn];
int n,k, index[maxn];
int count=0,num;
void dfs(int d){
	if(num == k){
		count ++ ;
		return ;
	}
	if(d >= n){
		return ;
	}
	for(int i = 0; i < n; i++){
		if(!index[i] && pic[d][i] == '#'){
			index[i] = 1;
			num ++;
			dfs(d+1);
			num --;
			index[i] = 0;
		}
	}
	dfs(d+1);
}
int main(){
	while(scanf("%d%d", &n, &k) != -1){
		if(n==-1 || k == -1){
			return 0;
		}
		count = 0;
		num = 0;
		for(int i = 0; i < n; ++i){
			scanf("%s",&pic[i]);
		}
		memset(index,0,sizeof(index));
		dfs(0);
		cout<<count<<endl;
	}
	return 0;
}