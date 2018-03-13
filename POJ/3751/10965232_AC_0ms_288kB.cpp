#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int main(){
	int n;
	int y, m, d, h, min, s;
	string ampm[] = {"am", "pm"};
	cin >> n;
	while(n--){
		int flag = 0;
		scanf("%d/%d/%d-%d:%d:%d", &y, &m, &d, &h, &min, &s);
		if(h >= 12) flag = 1;
		if(h == 0) h = 12;
		else if(h > 12) h -= 12;
		
		printf("%02d/%02d/%04d-%02d:%02d:%02d", m, d, y, h, min, s);
		cout << ampm[flag] <<endl;
	}
}