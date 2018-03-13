#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1e5;

int dp[MAXN + 1];

// dp[i] = max(dp[i-1] + a[i], a[i]);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, t;
	int kase = 0;
	while(cin >> n)
	{
		int start, end, current, maxvalue;
		 
		while(n--)
		{
			cin >> t;
			for(int i = 0; i < t; ++i) cin >> dp[i];
			
			start = end = current = 0;
			maxvalue = dp[0];
			
			for(int i = 1; i < t; ++i)
			{
				
				if(dp[i - 1] >= 0)
				{
					dp[i] += dp[i - 1];
				}
				else{
					current = i;
				}
				
				if(dp[i] > maxvalue)
				{
					maxvalue = dp[i];
					start = current;
					end = i;
				}
				//cout << dp[i] <<endl;
			}
			
			if(kase) cout << endl;
			cout << "Case " << ++kase << ":"<<endl;
			cout << maxvalue << " " << start + 1 << " " << end + 1 << endl;	
		}		
	}		
} 