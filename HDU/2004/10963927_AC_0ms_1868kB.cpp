#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	char s[] = "EEEEEEDCBAA";
	
	int key;
	while(scanf("%d", &key) != EOF){
		if(key <= 100 && key >= 0){
			printf("%c\n", s[key/10]);
		}else{
			printf("Score is error!\n");
		}
	}
	return 0;
}