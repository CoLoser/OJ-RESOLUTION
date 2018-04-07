#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 26;
int alpha[MAXN];


int main()
{
	string s;
	int cntline = 0, MAX;
	
	memset(alpha, 0, sizeof(alpha));
	
	while(getline(cin, s))
	{
		for(int i = 0; i < s.size(); ++i) if(isalpha(s[i])) alpha[s[i] - 'A']++;
		
		if(++cntline == 4)
		{
			MAX = 0;
			cntline = 0; 
			
			for(int i = 0; i < MAXN; ++i) MAX = max(MAX, alpha[i]);
			
			
			for(int i = MAX; i > 0; --i)
			{
				for(int j = 0; j < MAXN; ++j)
					if(alpha[j] >= i) cout << "* " ;
					else cout << "  ";
				cout << endl;
			}
			
			for(int i=0; i<MAXN; i++)  
                cout << (char)('A' + i) << " ";  
            cout << endl;  
		}
		
		
	}	
}