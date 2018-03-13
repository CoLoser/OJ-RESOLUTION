#include <cstdio>
#include <algorithm>
using namespace std;
const int SIZE = 101;
int s[SIZE];
int a[6] = {100, 50, 10, 5, 2, 1};
int main(){
	int n;
	while(scanf("%d", &n) == 1 && n != 0){
		for(int i = 0; i < n; ++i){
			scanf("%d", &s[i]);
		}
		sort(s, s+n);
		int sum = 0;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < 6; ++j){
				sum += s[i]/a[j]; 
				s[i] %= a[j];
			}
		}
		printf("%d\n", sum);
	}
}