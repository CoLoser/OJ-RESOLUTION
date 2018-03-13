#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 400005;
char target[maxn];
int next[maxn];
int result[maxn];

void setNext(char s[], int next[], int len)
{
    next[0] = -1;

    int i = 0, j = -1;
    while (i < len)
    {
        if (j == -1 || s[i] == s[j]) {
            ++i;
            ++j;
            next[i] = j;
        } else
            j = next[j];
    }
}
int main()
{
	while(scanf("%s", target) != EOF)
	{
		int len = strlen(target);
		
		setNext(target, next, len);
		int count  = 0;
		int t = next[len-1];
		while(t != -1)
		{
			if(target[t] == target[len-1])
				result[count++] = t + 1;
			t = next[t];
		}
		for(int i = count - 1; i >= 0; --i)
			printf("%d ", result[i]);
		printf("%d\n", len);
	}
	return 0;
}