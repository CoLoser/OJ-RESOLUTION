#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const char Start[] = "START";
const char End[] = "END";
const char EndOfInput[] = "ENDOFINPUT";
const char key[] = "VWXYZABCDEFGHIJKLMNOPQRSTU";
const int MAXN = 205;
char arr[MAXN];

int main()
{
	while(cin.getline(arr, MAXN)&& strcmp(arr, EndOfInput))
	{
		if(strcmp(arr, Start) && strcmp(arr, End))
		{
			for(int i = 0; i < strlen(arr); ++i)
				if(isupper(arr[i])) arr[i] = key[arr[i] - 'A'];
			cout << arr <<endl;
		}
	}
	return 0;
}