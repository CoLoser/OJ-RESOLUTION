#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

string init(string str)
{
	for(int i = 0; i < str.size(); ++i) if(isupper(str[i])) str[i] = tolower(str[i]);
	sort(str.begin(), str.end());
	return str;
}

int main()
{
	string strin, strtmp;
	set<string> sset, ans;
	map<string, int> strim;
	
	
	while(cin >> strin)
	{
		if(strin.size() == 1 && strin[0] == '#') break;
		strtmp = init(strin);
		strim[strtmp]++;
		sset.insert(strin);
	
	}	
	
	for(map<string, int>::iterator it = strim.begin(); it != strim.end(); ++it)
	{
		if(it->second == 1)
		{
			for(set<string>::iterator its = sset.begin(); its != sset.end(); ++its)
			{
				strtmp = init(*its);
				if(strtmp == it->first) ans.insert(*its); 
			}
		}
	}
	
	for(set<string>::iterator its = ans.begin(); its != ans.end(); ++its)
		cout << *its <<endl;
	return 0; 
}