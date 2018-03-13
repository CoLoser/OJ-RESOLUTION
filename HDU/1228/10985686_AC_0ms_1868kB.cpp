#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

char s[10][10] = {
	"zero",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine"
};
char key[100];
char tmp[100];
int main(){
	
	int x1, x2;
	int idx;
	int t;
	int flag = 0;
	while(gets(key) != NULL){
		int len = strlen(key);
		idx = 0;
		x1 = x2 = 0;
		flag = 0;
		for(int i = 0; i < len; ++i){
			if(isalpha(key[i])) tmp[idx++] = key[i];
			else if(key[i] == ' ' && key[i - 1] != '+'){
				tmp[idx] = '\0';
				for(int j = 0; j < 10; ++j){
					if(!strcmp(s[j], tmp)){
						 t = j;
						 break;
					}
				}
				idx = 0;
				if(!flag) x1 = x1*10 + t;
				else x2 = x2*10 + t;
			}
			else if(key[i] =='+') flag = 1;
  		}
		if(x1 == 0 && x2 == 0) break;
		else printf("%d\n", x1 + x2);
	}
	return 0;
}