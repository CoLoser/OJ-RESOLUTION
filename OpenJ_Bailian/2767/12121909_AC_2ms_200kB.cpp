#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 205;
char key[] = "VWXYZABCDEFGHIJKLMNOPQRSTU";

int main()
{
	char t[MAXN];
 	while(cin.getline(t, 200))
	{
		for(int i = 0; i < strlen(t); ++i)
			if(isalpha(t[i])) t[i] = key[t[i] - 'A'];
		cout << t <<endl;
	}
}