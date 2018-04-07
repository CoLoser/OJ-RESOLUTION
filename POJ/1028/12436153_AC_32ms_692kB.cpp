#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;
const char VISIT[] = "VISIT";
const char BACK[] = "BACK";
const char FORWARD[] = "FORWARD";
const char QUIT[] = "QUIT";

stack<string> Stack1, Stack2;
char cmd[10];
string web;

void init()
{
	while(!Stack2.empty()) Stack2.pop();
}
int main()
{
	Stack1.push("http://www.acm.org/");
	while(cin >> cmd)
	{
		if(strcmp(cmd, QUIT) == 0) break;
		else if(strcmp(cmd, VISIT) == 0){
			cin >> web;
			Stack1.push(web);
			cout << web <<endl;
			init();
		}else if(strcmp(cmd, BACK) == 0)
		{
			if(Stack1.size() > 1)
			{
				Stack2.push(Stack1.top());
				Stack1.pop();
				cout << Stack1.top() <<endl;
				
			}else
				cout << "Ignored" <<endl;
		}else if(strcmp(cmd, FORWARD) == 0)
		{
			if(!Stack2.empty())
			{
				Stack1.push(Stack2.top());
				cout << Stack2.top() << endl;
				Stack2.pop();
			}else
				cout << "Ignored" <<endl;
		}
	}
}