#include <iostream>
#include <cctype>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn = 105;
char s[maxn];

int main()
{
	while(gets(s))
	{
		bool flag = true;
		s[0] -= 'a' - 'A';
		for(int i = 0; i < strlen(s); ++i)
		{
			if(!flag){
				s[i] -= 'a' - 'A';
				flag = true;
			}
			if(s[i] == ' '){
				flag = false;
			}
		}
		puts(s);
	}
}