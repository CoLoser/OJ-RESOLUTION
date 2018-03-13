#include <iostream>
#include <set>
#include <cstring>
#include <cstdio>
#include <string>
#include <sstream>
using namespace std;

set<string> sset;

void trim(string &s)
{

    if( !s.empty() )
    {
        s.erase(0,s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
    }

}
int main()
{
	string s;
	while(cin >> s)
	{
		for(int i = 0; i < s.size(); ++i)
		{ 
			if(!isalpha(s[i])) s[i] = ' ';
			if(isupper(s[i])) s[i] = tolower(s[i]);	
		 }
		stringstream ss;
		ss<<s;
		string buf;
		
		while(ss>>buf)
		{
			sset.insert(buf);
		}
	}	
	for(set<string>::iterator it = sset.begin(); it != sset.end(); ++it) cout << *it << endl;
	return 0;
 } 