#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 30;
int a[MAXN], b[MAXN], c[MAXN], acount, bcount, ccount;
int prime[26] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};

int main()
{
	int i, j;
	char key;
	while(1)
	{
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		
		i = 0;
		for(;;)
		{
			scanf("%d%c", &a[i], &key);
			if(key == ' ') break;
			else i++;
		}
		acount = i;
		
		i = 0;
		for(;;)
		{
			scanf("%d%c", &b[i], &key);
			if(key == '\n') break;
			else i++;
		}
		bcount = i;
		if(acount == 0 && bcount == 0 && a[0] == 0 && b[0] == 0) break;
		ccount = max(acount, bcount);
		
		for(i = acount, j = 0; i >= 0; i--, j++) c[j] += a[i];
		for(i = bcount, j = 0; i >= 0; i--, j++) c[j] += b[i];
		
		for(i = 0; i <= ccount; ++i)
		{
			if(c[i] >= prime[i])
			{
				c[i] -= prime[i];
				c[i+1]++;
			}
		}
		
		if(c[ccount+1])
			ccount++;

		for(i = ccount; i > 0; i--)
			printf("%d,", c[i]);
		printf("%d\n", c[0]);
		
	}
}