#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
const int maxn = 1002;
queue<char> q;
char s[maxn];
int main(){
	while(scanf("%s", s) != EOF){
		int len = strlen(s);
		int ans = 0;
		while(!q.empty()) q.pop();
		for(int i = 0; i < len; ++i){
			if(s[i] == 'B'){
				while(!q.empty()){
					ans ++;
					q.pop();
				}
				break;
			}
			if(s[i] == '(') q.push('(');
			else if(s[i] == ')') q.pop();
		}
		printf("%d\n", ans);
		
	}
	return 0;
}
