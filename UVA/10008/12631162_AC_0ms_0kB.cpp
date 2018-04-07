#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct _Node{
	char key;
	int cnt;
	bool operator < (_Node rhs)
	{
		if(rhs.cnt == cnt) return rhs.key < key;
		else return rhs.cnt > cnt;
	}
};

const int MAXN = 27;
_Node arr[MAXN];
char s[1000];

void init()
{
	for(int i = 0; i < 26; ++i)
	{
		arr[i].cnt = 0;
		arr[i].key = 'A' + i;
	}
}
int main()
{
	int t;
	cin >> t;
	init();
	getchar();
	while(t--)
	{
		gets(s);
		for(int i = 0; i < strlen(s); ++i)
		{
			if(islower(s[i])) s[i] -= 32;
			if(isupper(s[i])){
				arr[s[i] - 'A'].cnt++;
				arr[s[i] - 'A'].key = s[i];
			}
		}
	}
	sort(arr, arr + 26);
	for(int i = 25; i >= 0; --i)
	{
		if(arr[i].cnt != 0) printf("%c %d\n", arr[i].key, arr[i].cnt);
	}
	return 0;
}