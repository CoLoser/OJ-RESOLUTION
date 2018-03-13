#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int maxn = 100005;
char s[maxn];
char t[maxn];
char st[maxn<<1];

int main()
{
	char *p;
	while(scanf("%s%s", s, t) != EOF)
	{
		strcpy(st, s);
		strcat(st, s);

		p = strstr(st, t);
		printf("%s\n", p?"yes":"no");
	}
	return 0;
}