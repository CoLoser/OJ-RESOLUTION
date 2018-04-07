#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;
const int MAXN = 1005;
char key[MAXN];

int main()
{
	while(cin.getline(key, 1005) && key[0] != '#')
	{
		ll ans = 0;
		for(int i = 0; i < strlen(key); ++i)
		{
			if(key[i] != ' ')
			{
				ans += (key[i] - 'A' + 1) * (i + 1);
			}
		}
		cout << ans <<endl;
	}
}