#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 200;
char s[MAXN];


int main()
{
	char c;
    int i;

    i = 0;
    while((c = getchar()) != '\n') {
        if(c == ' ')
            continue;
        s[i++] = tolower(c);
    }
    s[i] = '\n';

    i = 0;
    while((c = getchar()) != '\n') {
        if(c == ' ')
            continue;
        if(tolower(c) != s[i])
            break;
        i++;
    }
	
	printf("%s\n", c == s[i] ? "YES" : "NO");
	return 0;
}