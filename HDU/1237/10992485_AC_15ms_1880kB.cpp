#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 205;
double ans[maxn];
double sum = 0;

int main(){
	double x;
	while(scanf("%lf", &ans[0]) != EOF){
		char key;
		sum = 0;
		int idx = 0;
		key = getchar();
		if(ans[0] == 0 && key == '\n') break;
		while(scanf("%c %lf", &key, &x) != EOF){
			if(key == '*') ans[idx] *= x;
			else if(key == '/') ans[idx] /= x;
			else if(key == '+') ans[++idx] = x;
			else ans[++idx] = -x;
			key = getchar();
			if(key == '\n') break;
		}
		for(int i = 0; i <= idx; ++i){
			sum += ans[i];
		}
		printf("%.2f\n", sum);
	}
	return 0;
}