#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
const int MAXN = 62;
const int INF = 0x3ffffff;

string key[11];
int next[MAXN];

void getNext(string str, int len)
{
	int k = -1;
	next[0] = -1;
	
	for(int i = 1; i < len; ++i)
	{
		while(k > -1 && str[k + 1] != str[i]) k = next[k];
		if(str[k + 1] == str[i]) k++;
		next[i] = k;	
	}
}

bool kmp(string pattern, int plen, string target, int tlen)
{
	int k = -1;
	
	for(int i = 0; i < tlen; ++i)
	{
		while(k > -1 && pattern[k + 1] != target[i]) k = next[k];
		if(pattern[k + 1] == target[i]) k++;
		if(k == plen - 1) return 1;
	 } 
	 return 0; 
}


int main()
{
	int t, m;
	cin >> t;
	while(t--)
	{	
		cin >> m;
		for(int i = 0; i < m; ++i) cin >> key[i];
		
		string ans = "";
		
		for(int i = 1; i <= key[0].size(); ++i)
		{
			for(int j = 0; j <= key[0].size() - i; ++j)
			{
				string tmp = key[0].substr(j, i);
				getNext(tmp, tmp.size());
				
				bool flag = 0;
				
				
				for(int k = 1; k < m; ++k)
				{
					if(!kmp(tmp, tmp.size(), key[k], key[k].size()) && tmp.size()) flag = 1; //不匹配
				}
				
				if(!flag)
				{
					if(ans.size() < tmp.size()) ans = tmp;
					else if(ans.size() == tmp.size()) ans = min(ans, tmp);
				 }
			}
		}
		
		if(ans.size() <= 2) cout << "no significant commonalities" <<endl;
		else cout << ans <<endl;
	}	
	return 0;
}