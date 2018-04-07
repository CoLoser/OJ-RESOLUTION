#include <iostream>
#include <cstdio>
#include <vector> 
using namespace std;

string Union(string s1, string s2)
{
	string s = "";
	for(int i = 0; i < s1.size(); ++i)s += s2[i], s+= s1[i];
	return s;
}
void Break(string &s1, string &s2, string s, int n)
{
	s1 = "";
	s2 = "";
	for(int i = 0; i < n; ++i) s1 += s[i];
	for(int i = n; i < 2*n; ++i) s2 += s[i];
	
//	cout << "---" <<endl;
//	cout << s1 << endl << s2 << endl;
//	cout << "---" <<endl; 
	return; 
 } 
int main()
{
	string s1, s2, s12, res, tmp;
	int t, n;
	cin >> t;
	int p = 1;
	 
	while(cin >> n)
	{
		cin >> s1 >> s2 >> res;
		
		int cnt = 0;
		int falg = 0;
		tmp = Union(s1, s2);
		
		while(1)
		{
			cnt ++;
			s12 = Union(s1, s2);
			//cout << s12 << endl;
			if(s12.compare(res) == 0)
			{
				printf("%d %d\n", p++, cnt);
				break;
			}
			if(s12.compare(tmp) == 0)
			{
				if(falg++)
				{
					printf("%d -1\n", p++);
					break;
				}
			}
			Break(s1, s2, s12, n); 
		}
	}	
	return 0;
}