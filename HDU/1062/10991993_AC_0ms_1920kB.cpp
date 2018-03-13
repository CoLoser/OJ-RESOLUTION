#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
#include <cstring>
using namespace std;

stack<char> sta;
void init(){
	while(!sta.empty()){
		sta.pop();
	}
}
int main(){
	int n;
	string s = "";
	char key;
	scanf("%d", &n);
	getchar();
	while(n--){
		s = "";
		while(scanf("%c", &key) != EOF && key != '\n'){
			if(key != ' '){
				sta.push(key);
			}else{
				while(!sta.empty()){
					s += sta.top();
					sta.pop();
				}
				s += " ";
			}
		}
		while(!sta.empty()){
			s += sta.top();
			sta.pop();
		}
		cout << s <<endl;
	}
	return 0;
}