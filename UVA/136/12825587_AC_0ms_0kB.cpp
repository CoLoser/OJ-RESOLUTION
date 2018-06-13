#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

priority_queue<ll, vector<ll>, greater<ll> > pq;
set<ll> lset;

const int ugly[] = {2, 3, 5};

int main()
{
	lset.insert(1);
	pq.push(1);
	
	for(int i = 1; ; i++)
	{
		ll a = pq.top();
		pq.pop();
		
		if(i == 1500){ 
			cout <<"The 1500'th ugly number is "<< a << "." <<endl;
			break;
		} 
		for(int j = 0; j < 3; ++j) 
		{
			ll tmp = a * ugly[j];
			if(lset.count(tmp) == 0) lset.insert(tmp), pq.push(tmp);			
		}
	}
	return 0;
}