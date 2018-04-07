#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 90;
char key[MAXN];

int main()
{
	int t;
	cin >> t;
	getchar();
	while(t--)
	{
		bool flag = 1;
		gets(key);
		if(!isalpha(key[0]) && !(key[0] == '_')) flag = 0;
		for(int i = 1; i < strlen(key); ++i)
		{
			if(!isdigit(key[i]) && !isalpha(key[i]) && !(key[i] == '_'))
			{
				flag = 0;
				break;
			}
		}
		printf("%d\n", flag);
	}
	return 0;
}