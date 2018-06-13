#include <iostream>
#include <cstdio>
#include <cstring> 
using namespace std;


int main()
{
	string s;
	
	bool flag = true;
	while(getline(cin, s))
	{
		for(int i = 0; i < s.size(); ++i)
		{
			if(s[i] == '"')
			{
				if(flag) flag = false, cout << "``";
				else flag = true, cout << "''";
			}else cout << s[i];
		}
		cout << endl;
	}	
	return 0;
}