#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
const int MAXN = 50000;
int visit[MAXN];
int prime[MAXN / 5];
int cnt = 0;

void getPrime()
{
	memset(visit, 0, sizeof(visit));
	visit[0] = 1;
	visit[1] = 1;
	for(int i = 2; i <= sqrt(MAXN); ++i) if(!visit[i])
		for(int j = i * i; j <= MAXN; j += i) visit[j] = 1;
	
	for(int i = 2; i < MAXN; ++i)
	{
		if(!visit[i]) prime[cnt++] = i;
	}
	
}
int main()
{
	int t;
	getPrime();
	while(cin >> t && t)
	{
		int ans = 0;
		for(int i = 2; i <= t; ++i)
			ans = (ans + prime[t - i]) % i;  	//约瑟夫环 
		cout << ans + 1 <<endl; 
	}
	return 0;
} 