#include <cstdio>
#include <algorithm>
const int SIZE = 101;
double arr[SIZE];
using namespace std;
int main(){
	int n;
	while(~scanf("%d", &n)){
		for(int i = 0; i < n; ++i){
			scanf("%lf", &arr[i]);
		}
		sort(arr, arr+n);
		double sum = 0;
		for(int i = 1; i < n-1; ++i){
			sum += arr[i];
		}
		printf("%.2f\n", (sum)/(n-2));
	}
	return 0;
}