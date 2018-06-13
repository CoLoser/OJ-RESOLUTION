#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int grade[101];

int main()
{
	int t, n, m;
	while(cin >> t && t)
	{
		memset(grade, 0, sizeof(grade));
		for(int i = 0; i < t; ++i)
		{
			cin >> n;
			grade[n]++;	
		}	
		cin >> m;
		cout << grade[m] <<endl;
	}
	return 0;	
}