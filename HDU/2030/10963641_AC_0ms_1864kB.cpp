#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	int n;
	int ans = 0;
	char c;
	scanf("%d", &n);
	getchar();
	while(n--){
		ans = 0;
		for(;;){
			if(scanf("%c", &c) != EOF){
				if(c == '\n') break;
				if(c < 0) ans++;
			}
		}

		printf("%d\n", ans/2);
	}
	return 0;
	
}