#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int BASE_10 = 10;
const int START = 2;
const int END = 16;
 
int toDec(int val, int base)
{
	int ans = 0;
	int cnt = 1;
	while(val)
	{
		int t = val % BASE_10;
		val /= BASE_10;
		
		if(t >= base) return -1;
		
		ans += cnt * t;
		
		cnt *= base;	
	}	
	return ans;
 } 
 
int main()
{
	int p, q, r;
	
	int i;
	while(cin >> p >> q >> r)
	{
		for(i = START; i <= END; ++i)
		{
			int p01 = toDec(p, i);
			if(p01 < 0) continue;
			
			int q01 = toDec(q, i);
			if(q01 < 0) continue;
			
			int r01 = toDec(r, i);
			if(r01 < 0) continue;
			
			if(p01 * q01 == r01) break;
		}
		
		printf("%d\n", i <= END ? i : 0);
	}
	return 0;
 } 