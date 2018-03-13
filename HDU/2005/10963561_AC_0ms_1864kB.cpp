#include <iostream>
#include <cstdio>

using namespace std;

int sum[13] = {
	0,
	31,
	31 + 28,
	31 + 28 + 31,
	31 + 28 + 31 + 30,
	31 + 28 + 31 + 30 + 31,
	31 + 28 + 31 + 30 + 31 + 30,
	31 + 28 + 31 + 30 + 31 + 30 + 31,
	31 + 28 + 31 + 30 + 31 + 30 + 31 + 31,
	31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30,
	31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31,
	31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30,
	31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + 31
};

int isOK(int yy, int mm){
	if(mm <= 2) return 0;
	else if((yy%4 == 0 && yy % 100 != 0) || yy % 400 == 0) return 1;
	else return 0;
}
int main(){
	int y, m, d;
	int ans = 0;
	while(scanf("%d/%d/%d", &y, &m, &d) != EOF){
		ans = isOK(y, m) + sum[m - 1] + d;
		printf("%d\n", ans);
	}
	return 0;
}