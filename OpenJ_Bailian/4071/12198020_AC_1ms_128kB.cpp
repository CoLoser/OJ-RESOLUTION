#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

const int MAXN = 256;
char arr[MAXN];
int key[MAXN];

int main()
{
	int t, p;
	scanf("%d\n", &t);
	while(t--)
	{
		gets(arr);
		memset(key, 0, sizeof(key));
		int len = strlen(arr) - 1;
        while(isdigit(arr[len]))
            len--;
        p = atoi(&arr[len + 1]);
        arr[len] = '\0';
        
		int flag = 1;
		int i = 0;
		while(arr[i]) {
            key[(unsigned int)arr[i++]]++;
        }
		for(i = 1; i < MAXN; ++i)
		{
			if(key[i] == p && flag) printf("'%c'", i), flag = 0;
			else if(key[i] == p) printf(",'%c'", i);
		}
		printf("\n");
	}
	return 0;
}