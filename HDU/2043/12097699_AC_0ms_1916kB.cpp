#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

char alpha[] = "~!@#$%^";
const int MAXN = 55;
char key[MAXN];

bool is_special_alpha(char c)
{
	for(int i = 0; i < strlen(alpha); ++i)
		if(c == alpha[i]) return true;
	return false;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0;
		cin >> key;
		int len = strlen(key);
		for(int i = 0; i < len; ++i)
		{
			if(islower(key[i])) flag1 = 1;
			if(isupper(key[i])) flag2 = 1;
			if(isdigit(key[i])) flag3 = 1;
			if(is_special_alpha(key[i])) flag4 = 1;
		}
		int cnt = flag1 + flag2 + flag3 + flag4;
		printf("%s\n", cnt >= 3 && len >= 8 && len <= 16 ? "YES" : "NO");
	}
	return 0;

}