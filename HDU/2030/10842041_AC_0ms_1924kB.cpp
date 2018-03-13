#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	
	int n;
	scanf("%d", &n);
	getchar();
	while(n --){
		char key;
		int ans = 0;
		
		for(;;){
			if((key = getchar()) == '\n') break;
			if(key < 0) ans ++;
		}
		cout << ans/2 <<endl;
	}
}