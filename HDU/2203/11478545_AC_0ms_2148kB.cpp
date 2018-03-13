#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>

using namespace std;

string s, t;

int main()
{
	int p;
	while(cin>>s)
	{
		cin>>t;
		s = s + s;
		
		p = s.find(t);
		printf("%s\n", p >= 0 ? "yes" : "no");
	}
}