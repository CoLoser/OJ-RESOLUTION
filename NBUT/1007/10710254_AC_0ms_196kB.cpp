#include <cstdio>
using namespace std;
int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		while(n--){
			int y, m , d;
			scanf("%d%d%d", &y, &m, &d);
			int sum = 0, index = 0;
			int t[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
			for(int i = 1; i <= 12; ++i){
				t[i]+=t[i-1];
			}
			for(int i = 1; i < y; ++i){
				if(i % 4 == 0 && i % 100 != 0 || i % 400 ==0){
					index ++;
				}
			}
			if(y % 4 == 0 && y % 100 != 0 || y % 400 ==0){
				if(m >= 3) sum++;
			}
			sum += index + 365*(y-1) + t[m-1] + d;
			printf("%d\n", sum);
		}
	}
	return 0;
}