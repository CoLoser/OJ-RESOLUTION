#include <iostream>
#include <cstdio>
#include <map>
#include <string>
using namespace std;

int main()
{
	map<char, int> m;

	m['I'] = 1;
	m['V'] = 5;
	m['X'] = 10;
	m['L'] = 50;
	m['C'] = 100;
	m['D'] = 500;
	m['M'] = 1000;
	
	string key, s;
	int t;
	int t1, t2;
	cin >> t;
	while(t--)
	{
		cin >> s;
		int ans = t1 = m[s[s.size() - 1]];
		
		for(int i = s.size() - 2; i >= 0; --i)
		{
			t2 = m[s.at(i)];
			if(t1 <= t2) ans += t2;
			else ans -= t2;
			t1 = t2;
		}
		cout << ans <<endl;
	}
}