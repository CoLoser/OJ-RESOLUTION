#include <cstdio>

using namespace std;
typedef long long ll;
int main(){
	int t;
	int n, m;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		if(n < m)printf("0\n");
		else{
			ll ans = 1;
			for(int i = 1; i <= m; ++i)
				ans = ans * (n -i + 1)/i;
			printf("%lld\n", ans);
		}
	}
	return 0;
}