#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

stack<string> s1, s2;
void init(){
	while(!s2.empty()) s2.pop();
}
int main(){
	string URL;
	string Order;
	s1.push("http://www.acm.org/");
	while(cin >> Order){
		if(Order[0] == 'V'){
			cin >> URL;
			s1.push(URL);
			cout << URL <<endl;
			init();
		}else if(Order[0] == 'B'){
			if(s1.size() > 1){
				s2.push(s1.top());
				s1.pop();
				cout << s1.top() <<endl;
			}else cout << "Ignored" <<endl;
		}else if(Order[0] == 'F'){
			if(!s2.empty()){
				s1.push(s2.top());
				cout << s2.top() <<endl;
				s2.pop();
			}else cout << "Ignored" <<endl;
		}else break;
		
	}
	return 0;
}