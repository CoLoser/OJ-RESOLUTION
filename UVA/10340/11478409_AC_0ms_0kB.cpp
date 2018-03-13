#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 110000;
char s[maxn];
char t[maxn];

bool delstr(char s[], char t[])
{
	int slen = strlen(s);
	int tlen = strlen(t);
	int i = 0, j = 0;
	while(i < slen && j < tlen)
	{
		if(t[j] == s[i])
		{
			i ++;
			j ++;
		}else
		    j ++;
	}
	return i ==  slen;
}
int main()
{
	while(scanf("%s%s", s, t) != EOF)
	{
		if(delstr(s, t)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}