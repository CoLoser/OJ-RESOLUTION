#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char _special[] = "~!@#$%^";

bool isSpecial(char c)
{
	for(int i = 0; i < strlen(_special); ++i) if(c == _special[i]) return true;
	return false;
}

int main()
{
	char key[66];
	
	int t;
	cin >> t;
	while(t--)
	{
		cin >> key;
		
		int len = strlen(key);
		
		bool flag = (len <= 16 && len >= 8) ? true : false;
		
		int flag00 = 0, flag01 = 0, flag02 = 0, flag03 = 0;
		for(int i = 0; i < len; ++i)
		{
			if(isupper(key[i])) flag00 = 1;
			if(islower(key[i])) flag01 = 1;
			if(isSpecial(key[i])) flag02 = 1;
			if(isdigit(key[i])) flag03 = 1;
		}
		
		printf("%s\n", (flag && flag00 + flag01 + flag02 + flag03 >= 3) ? "YES" : "NO");
	}
}