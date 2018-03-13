#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
using namespace std;
const int MAXN = 90;
char key[MAXN];
map<char, int> m;

int main()
{
	gets(key);
	for(int i = 0; i < strlen(key); ++i)
		m[key[i]]++;
	printf("%d %d %d %d %d\n", m['a'], m['e'], m['i'], m['o'], m['u']);
}