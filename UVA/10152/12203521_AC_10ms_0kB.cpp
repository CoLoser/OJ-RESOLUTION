#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 256;
char target[MAXN][MAXN];
char pattern[MAXN][MAXN];

int main()
{
	int t, n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		getchar();
		for(int i = 0; i < n; ++i)
			gets(target[i]);
		for(int i = 0; i < n; ++i)
			gets(pattern[i]);
			
		int p = n - 1, q = n - 1;
		
		while(p >= 0)
		{
			if(!strcmp(target[p], pattern[q])) q--;
			p--;
		}
		
		while(q >= 0) printf("%s\n", pattern[q--]);
		printf("\n");
	}
	return 0;
	
}