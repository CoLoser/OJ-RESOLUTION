#include <iostream>
#include <cstdio>
#include <set>
#include <cstring> 
using namespace std;

int main()
{
	string str1, str2, t;
	int len;
	set<string> sset;
	
	while(cin >> t) sset.insert(t);
	
	for(set<string>::iterator it = sset.begin(); it != sset.end(); it++)
	{
		t = *it;
		
		len = t.length();
		
		for(int i = 0; i < len - 1; ++i)
		{
			str1 = t.substr(0, i+1);
			str2 = t.substr(i+1, len-1);
			
			if(sset.find(str1) != sset.end() && sset.find(str2) != sset.end())
			{
				cout << t <<endl;;
				break;
			}
		}
	}
	return 0;
}