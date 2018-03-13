#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
map<char, int> m;
void init()
{
	m.clear();
	m['a'] = m['e'] = m['i'] = m['o'] = m['u'] = 0;
}
int main()
{
	
	int t;
	scanf("%d", &t);
	getchar();
	while(t--)
	{
		init();
		char key;
		while(key = getchar())
		{
			if(key == '\n') break;
			if(key == 'a')m[key]++;
			if(key == 'e')m[key]++;
			if(key == 'i')m[key]++;
			if(key == 'o')m[key]++;
			if(key == 'u')m[key]++;
		}
		for(map<char, int>::iterator it = m.begin(); it != m.end(); ++it)
			printf("%c:%d\n",it->first, it->second);
		if(t>=1)printf("\n");
	}
}