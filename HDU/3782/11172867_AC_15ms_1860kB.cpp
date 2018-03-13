#include <cstdio>
using namespace std;

int main(){
	int ans;
	int n;
	while(scanf("%d", &n) != EOF && n){
		ans = 0;
		while(n != 1){
			ans++;
			if(n%2 == 0){
				n/=2;
			}else{
				n = (3*n + 1)/2;
			}
		}
		
		printf("%d\n", ans);
	}
	return 0;
}