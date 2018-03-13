#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 10000;
const int MAXM = 1000000;

int next[MAXN];

void getNext(string pattern, int len)
{
	int k = -1;
	next[0] = -1;
	
	for(int i = 1; i < len; ++i)
	{
		while(k > -1 && pattern[k + 1] != pattern[i]) k = next[k];
		if(pattern[k + 1] == pattern[i]) k++;
		
		next[i] = k;
	}
}

int kmp(string pattern, int plen, string target, int tlen)
{
	int k = -1;
	int cnt = 0;
	
	for(int i = 0; i < tlen; ++i)
	{
		while(k > -1 && pattern[k + 1] != target[i]) k = next[k];
		if(pattern[k + 1] == target[i]) k ++;
		
		if(k == plen - 1) cnt ++, k = next[k];
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
    
	int t;
	string pattern, target;
	
	cin >> t;
	
	while(t--)
	{
		cin>> pattern >> target ;

		getNext(pattern, pattern.size());
		
		int m = kmp(pattern, pattern.size(), target, target.size());
		cout << m << endl;
	}	
}