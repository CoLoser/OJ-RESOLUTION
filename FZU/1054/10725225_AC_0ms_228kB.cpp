#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		getchar();
		char s[201];
		while(n--){
			gets(s);
			for(int i = strlen(s) - 1; i >= 0; --i){
				printf("%c", s[i]);
			}
			printf("\n");
		}
	}
}