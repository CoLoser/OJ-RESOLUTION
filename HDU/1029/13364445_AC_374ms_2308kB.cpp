#include <iostream>
#include <iostream>
#include <map>
using namespace std;

map<int, int> m;

int main(){
	cin.sync_with_stdio(false);
	cin.tie(0);
	int n, t;
	while(cin >> n){
		m.clear();
		int flag = -1;
		for(int i = 0; i < n; ++i){
			cin >> t;
			m[t]++;
			if(m[t] >= (n + 1)/2){
				flag = t;
			}
		}
		printf("%d\n", flag);
	}	
}