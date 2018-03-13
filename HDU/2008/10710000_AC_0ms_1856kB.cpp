#include <cstdio>
using namespace std;
int main(){
	int n;
	while(scanf("%d", &n) != EOF && n != 0){
		int a = 0, b = 0, c = 0;
		double x;
		for(int i = 0; i < n; ++i){
			scanf("%lf", &x);
			if(x > 0) a ++;
			if(x < 0) b ++;
			if(x == 0) c++; 
		}
		printf("%d %d %d\n", b, c, a);
	}
	return 0;
}