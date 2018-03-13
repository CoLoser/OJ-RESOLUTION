#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAXN = 105;
char key[MAXN];

int main()
{
	char *p;
	gets(key);
	
	p = key;
	while(*p)
		p++;
	
	cout << (p - key) <<endl;
}