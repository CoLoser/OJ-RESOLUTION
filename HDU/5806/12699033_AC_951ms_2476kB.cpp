#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN = 200001;
int arr[MAXN];


int main()
{
	int t, n, m, k;
	
	cin >> t;
	
	ll cnt = 0;
	
	while(t--)
	{
		cnt = 0;
		int j = 0, num = 0;
		
		scanf("%d%d%d", &n, &m, &k);
		
		for(int i = 0; i < n; ++i) scanf("%d", &arr[i]);
		
		for(int i = 0; i < n; ++i)
		{
			while(j < n && num < k)
			{
				if(arr[j] >= m)	num++;
				
				j++;
			}	
			
			if(num >= k) cnt += n - j + 1;
			
			if(arr[i] >= m) num --;
			 
		}	
		printf("%lld\n", cnt);	
	}
	
		
	return 0;
 } 