#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	while(n--){
		string s1, s2;
		cin >> s1 >> s2;
		int len = s1.size();
		for(int i = 0; i < len; ++i){
			if(i == len/2){
				 
				 cout << s2;
				 cout << s1[i];
			}
			else cout << s1[i];
		}
		cout <<endl;
	}
}