#include <cstdio>
using namespace std;
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int a, flag = 1;
		double  sum = 0;
		scanf("%d", &a);
		for(int j = 1; j <= a; ++j){
			sum += flag * (1.0 / j);
			flag *= -1;
		}
		printf("%.2f\n", sum);
	}
	return 0;
}