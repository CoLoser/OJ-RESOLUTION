#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>

using namespace std;

map<char, double> m;
void init()
{
	m['C'] = 12.01;
	m['H'] = 1.008;
	m['O'] = 16.00;
	m['N'] = 14.01;
}

int main(){
	int t;
	char key[100];
	cin >> t;
	init();
	getchar();
	while(t--)
	{
		double ans = 0.0;
		int flag = 0;
		int count  = 0;
		char c, molar;
		while((c = getchar()) != '\n' && c != EOF)
		{
			//cout << count << "--" << molar <<endl;
			if(isalpha(c))
			{
				if(flag)
					ans += (count == 0 ? 1 : count) * m[molar];
				flag = 1;
				molar = c;
				count = 0;
			}else if(isdigit(c))
				count = count * 10 + c - '0';
		}
		if(flag)
			ans += (count == 0 ? 1 : count) * m[molar];
		if(flag)
			printf("%.3f\n",ans);
	}
	return 0;
}