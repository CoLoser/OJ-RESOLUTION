#include <iostream>
#include <map>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
int main(){
	map<string, int> m;
	int n;
	while(cin >> n && n){
		m.clear();
		string s;
		for(int i = 0; i < n; ++i){
			cin >> s;
			m[s]++;
		}
		int MAX = -1;
		for(map<string, int>::iterator it = m.begin(); it != m.end(); ++it){
			if(MAX < it->second){
				s = it->first;
				MAX = it->second;
			}
		}
		cout << s << endl;
	}
	
}
