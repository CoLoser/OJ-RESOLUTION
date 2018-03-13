#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn = 1005;
ll result[maxn];
int main()
{
	string s = "";
	char key;
	while(cin>>s)
	{
		for(int i = 0; i < s.size(); ++i)
			if(s[i] == '5') s[i] = ' ';

		istringstream iss(s);
		stringstream ss;
		string tmp;
		int cnt = 0;
		
		while(iss>>tmp)
		{
			ss.clear();
			ss<<tmp;
			ss>>result[cnt++];
		}
		
		sort(result, result + cnt);
		
		for(int i = 0; i < cnt; ++i)
			printf("%lld%c", result[i], i == cnt - 1 ? '\n' : ' ');
	}
	return 0;
}