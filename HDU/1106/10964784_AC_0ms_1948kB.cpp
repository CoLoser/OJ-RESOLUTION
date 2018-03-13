#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <sstream>
using namespace std;
const int maxn = 1002;
long long key[maxn];
int main(){
	string s;
	while(cin >> s){
		for(int i = 0; i != s.size(); ++i){
			if(s[i] == '5')
				s[i] = ' ';
		}
		istringstream iss(s);
		stringstream ss;
		string tmp;
		int n = 0;
		while(iss>>tmp){
			ss.clear();
			ss<<tmp;
			ss>>key[n];
			n++;
		}
		sort(key, key + n);
		for(int i = 0; i < n; ++i){
			printf("%lld", key[i]);
			printf("%c", i == n - 1 ? '\n' : ' ');
		}
	}
	return 0;
}