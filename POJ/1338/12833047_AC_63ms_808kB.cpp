#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
using namespace std;

typedef long long ll;

const int ugly[] = {2, 3, 5};

int main()
{
	int t;
	while(cin >> t && t != 0)
	{
		priority_queue<ll, vector<ll> , greater<ll> > pq;
		set<ll> lset;
		
		pq.push(1);
		lset.insert(1);
		
		for(int i = 1; ; i ++)
		{
			ll a = pq.top();
			pq.pop();
			
			if(i == t)
			{
				cout << a << endl;
				break;
			}
			
			for(int j = 0; j < 3; ++j)
			{
				ll x = ugly[j]*a;
				
				if(lset.count(x) == 0) pq.push(x), lset.insert(x);
			}
		}
	}
 } 