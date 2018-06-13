#include <iostream>
#include <cstring>
#include <string>
#include <map>
using namespace std;

string s1 = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main() {
	map<char, char> m;
	for(int i = 1; i < s1.size(); ++i) m[s1[i]] = s1[i-1];
	char key;
	while((key = getchar()) != EOF) {
		if(key==' ') printf(" ");
		else if(key=='\n') printf("\n");
		else printf("%c", m[key]);
	}
	return 0;
}