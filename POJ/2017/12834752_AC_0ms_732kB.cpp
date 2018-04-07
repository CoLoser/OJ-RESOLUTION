#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	while(cin >> t && t != -1)
	{
		int linecount = 0;
		int speed01, speed02, time01, time02;
		cin >> speed01 >> time01;
		linecount += speed01 * time01;
		for(int i = 1; i < t; ++i)
		{
			cin >> speed02 >> time02;
			
			linecount += (speed02) * (time02 - time01);
			
			time01 = time02;
		}
		cout << linecount << " miles" << endl;
	}
	return 0;
 } 