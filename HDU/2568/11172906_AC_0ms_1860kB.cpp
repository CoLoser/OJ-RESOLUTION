#include <cstdio>

using namespace std;

int main()
{
	int ans;
	int n;
	scanf("%d", &n);
	int t;
	while(n--){
		ans = 0;
		scanf("%d", &t);
		while(t != 0){
			if(t%2 != 0){
				t--;
				ans ++;
			}else{
				t/=2;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}