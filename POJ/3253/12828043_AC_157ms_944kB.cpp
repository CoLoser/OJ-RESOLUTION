#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

typedef long long ll;

int main()
{
	priority_queue<int, vector<int>, greater<int> > pq;
	
	ll ans;
	int n, t;
	
	while(cin >> n)
	{
		while(!pq.empty()) pq.pop();
		for(int i = 0; i < n; ++i)
		{
			cin >> t;
			pq.push(t);
		}
		
		ans = 0;
		
		while(pq.size() > 1)
		{
			ll a = pq.top();
			pq.pop();
			ll b = pq.top();
			pq.pop();
			
			pq.push(a + b);
			ans += (a + b);
		}
		
		cout << ans <<endl;
	}
 } 