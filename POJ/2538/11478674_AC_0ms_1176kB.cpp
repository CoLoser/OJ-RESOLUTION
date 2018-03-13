#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

char key[] = "1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

char convert(char c)
{
	int len = strlen(key);
	
	for(int i = 0; i < len; ++i)
	{
		if(key[i] == c)
			return key[i-1];
	}
	return c;
}

int main()
{
	char s[1000001];
	while(gets(s))
	{
		for(int i = 0; i < strlen(s); ++i)
		{
			printf("%c", convert(s[i]));
		}
		printf("\n");
	}
}