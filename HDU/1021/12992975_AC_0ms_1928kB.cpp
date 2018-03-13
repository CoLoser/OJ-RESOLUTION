#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int t;
	while(cin >> t){
		printf("%s\n", t%4 == 2 ? "yes" : "no");
	}
	return 0;
}
