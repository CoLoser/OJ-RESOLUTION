#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
const int SIZE = 1001;
char s[SIZE][16];
int cou[SIZE];
int main(){
	int n;
	while(scanf("%d", &n) == 1 && n != 0){
		char key[16];
		int MAX = -1;
		memset(cou, 0, sizeof(cou));
		for(int i = 0; i < n; ++i){
			scanf("%s", s[i]);
		}
		int pos = 0;
		for(int i = 0; i < n; ++i){
			for(int j = i; j < n; ++j){
				if(strcmp(s[i], s[j]) == 0){
					cou[i]++;
				}
			}
			if(MAX < cou[i]){
				MAX = cou[i];
				pos = i;
			}
		}
		printf("%s\n", s[pos]);
		
	}
	return 0;
}