#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 105;
char key[MAXN];

int atn;
int dotn;
int atidx;

int main()
{
	while(cin >> key)
	{
		bool flag = 1;
		atn = 0;
		dotn = 0;
		int len = strlen(key);
		if(key[0] == '.' || key[0] == '@' || key[len - 1] == '.' || key[len - 1] == '@')flag = 0;
		for(int i = 0; i < len; ++i)
		{
			if(key[i] == '@'){
				atn++;
				atidx = i;
			}
		}
		for(int i = atidx; i < len; ++i)
			if(key[i] == '.') dotn++;
		if(atn == 1 && dotn >= 1 && key[atidx - 1] != '.' && key[atidx + 1] != '.' && flag) printf("YES\n");
		else printf("NO\n");
			
	}
	return 0;
}