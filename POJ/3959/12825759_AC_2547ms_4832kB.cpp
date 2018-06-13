#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;
const int MAXN = 1000;
int maxl[MAXN + 1];
vector<string> words[MAXN + 1];

int main()
{
	string str01, str02;
	memset(maxl, 0, sizeof(maxl));
	
	int len = 0;
	
	while(getline(cin, str01))
	{
		stringstream ss;
		ss << str01;
		
		int i = 0;
		while(ss >> str02)
		{
			maxl[i] = max((int)str02.size(), maxl[i]);
			words[len].push_back(str02);
			i++;
		}
		len++;
	}	
	
	cout << setiosflags(ios::left);
	for(int i = 0; i < len; ++i)
	{
		for(int j = 0; j < (int)words[i].size() - 1; ++j) cout << setw(maxl[j] + 1) << words[i][j];
		cout << words[i][(int)words[i].size() - 1] << endl;
	}
}