#include <iostream>
#include <cstdio>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 100005;
int a[MAXN], b[MAXN];

int main(){
	int n, s;
	while(scanf("%d%d", &n, &s) != EOF){
		for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
		b[0] = 0;
		for(int i = 1; i <= n; ++i) b[i] = b[i - 1] + a[i];
		
		int ans = INF, i = 1;
		for(int j = 1; j <= n; ++j){
			if(b[i-1] > b[j] - s) continue;
			while(b[i] <= b[j] - s) i++;
			ans = min(ans, j - i + 1);
		} 
		
		printf("%d\n", ans == INF ? 0 : ans);
	}	
	return 0;
}