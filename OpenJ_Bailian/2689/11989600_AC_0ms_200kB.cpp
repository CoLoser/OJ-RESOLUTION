#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 100;
char key[MAXN];

int main()
{
	gets(key);
	for(int i = 0; i < strlen(key); ++i)
	{
		if(islower(key[i])) key[i] -= 32;
		else if(isupper(key[i])) key[i] += 32;
	}
	puts(key);
}