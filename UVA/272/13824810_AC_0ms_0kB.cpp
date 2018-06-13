#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;

int main() {
	char key;
	bool flag = 1;
	while((key = getchar()) != EOF){
		if(key != '\"') printf("%c", key);
		else{
			printf("%s", flag ? "``" : "''");
			flag = !flag;
		}
	}
	return 0;
}