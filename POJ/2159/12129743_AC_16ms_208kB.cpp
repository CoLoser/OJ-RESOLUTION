#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
const int maxn = 105;

string key;

int main()
{
	int cipher[27];
	int clear[27];
	
	memset(cipher, 0, sizeof(cipher));
	memset(clear, 0, sizeof(clear));
	cin>>key;
	for(int i = 0; i < key.size(); ++i)
	{
		cipher[key[i] - 'A']++;
	}
	cin>>key;
	for(int i = 0; i < key.size(); ++i)
	{
		clear[key[i] - 'A']++;
	}
	sort(cipher, cipher + 26);
	sort(clear, clear + 26);
	
	for(int i = 0; i < 26; ++i)
	{
		//cout << "cipher = " << cipher[i] <<" clear = " << clear[i] <<endl;
		if(cipher[i] != clear[i])
		{
			cout << "NO" <<endl;
			return 0;
		}
	}
		cout << "YES" <<endl;
	return 0;
}