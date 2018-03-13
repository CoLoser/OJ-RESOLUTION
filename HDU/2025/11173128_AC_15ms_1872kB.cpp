#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 105;
char key[maxn];
int main()
{
	while(scanf("%s", &key) != EOF){
		char MAX = 0;
		for(int i = 0; i < strlen(key); ++i){
			MAX = max(MAX, key[i]);
		}
		for(int i = 0; i < strlen(key); ++i){
			printf("%c", key[i]);
			if(MAX == key[i]) printf("(max)");
		}
		printf("\n");
	}
	return 0;
}