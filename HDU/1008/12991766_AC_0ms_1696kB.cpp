#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
	int t;
	int a, b;
	while(cin >> t && t)
	{
		int res = 0;
		a = 0;
		for(int i = 0; i < t; ++i){
			cin >> b;
			int x = b - a;
			res += 5;
			if(x > 0) res += 6*x;
			else if(x < 0) res += 4*(-x);
			a = b;
		}
		cout << res << endl;
	}
}
