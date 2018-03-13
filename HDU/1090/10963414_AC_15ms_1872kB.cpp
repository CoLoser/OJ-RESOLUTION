#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int a, b;
	int n;
	scanf("%d", &n);
	while(n--){
		scanf("%d%d", &a, &b);
		printf("%d\n", a + b);
	}
	return 0;
}