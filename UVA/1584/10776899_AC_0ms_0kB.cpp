#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

const int SIZE = 101;

char s[SIZE];

int Less(const char* s, int p, int q){
	int len = strlen(s);
	for(int i = 0; i < len; ++i){
		if(s[(p+i)%len] != s[(q+i)%len]){
			return s[(p+i)%len] > s[(q+i)%len];
		}
	}
	return 0;
}
int main(){
	int T;
	while(scanf("%d", &T) != EOF){
		while(T--){
			scanf("%s", s);
			int ans = 0;
			int len = strlen(s);
			for(int i = 0; i < len; ++i){
				if(Less(s, ans, i)) ans = i;
			}
			for(int i = 0; i < len; ++i)
				cout << s[(ans + i) % len];
			cout << endl;
		}
	}
	return 0;
}