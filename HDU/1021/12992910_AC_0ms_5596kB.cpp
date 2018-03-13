#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1000005;
int visit[MAXN];

int main()
{
	memset(visit, 0, sizeof(visit));
	int fn, fn1 = 11, fn2 = 7;
	int cnt = 2;
	while(1){	
		if(cnt >= MAXN) break;
		fn = (fn1 + fn2)%3;
		if(fn == 0) visit[cnt] = 1;
		cnt ++;
		fn2 = fn1;
		fn1 = fn;
	}
	
	int t;
	
	while(cin >> t){
		printf("%s\n", visit[t] ? "yes" : "no");
	}
	return 0;
}
