#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdio>
#include <string>

using namespace std;

char key[41];
string t;

int main()
{
	while(cin.getline(key, 40))
	{
		istringstream iss(key);
		string tmp;
		int len = 0;
		while(iss >> tmp)
		{
			if(len < tmp.size())
			{
				len = tmp.size();
				t = tmp;
			}
		}
		cout << t <<endl;
	}
}