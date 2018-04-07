#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int keypad[] = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
const int MAXN = 102;

int main()
{
	char key[MAXN];
	int t;
	cin >> t;
	getchar();
	for(int i = 1; i <= t; ++i)
	{
		int cnt = 0;
		cin.getline(key, 100);
		
		for(int j = 0; j < strlen(key); ++j)
			if(isspace(key[j])) cnt ++;
			else if(isalpha(key[j])) cnt += keypad[key[j] - 'a'];
		printf("Case #%d: %d\n", i, cnt);
	}
	return 0;
}