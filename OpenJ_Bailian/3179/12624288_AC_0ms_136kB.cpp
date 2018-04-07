#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
using namespace std;

int main()
{
	char key[210];
	int len = -1;
	string str;
	while(cin.getline(key, 210))
	{
		for(int i = 0; i < strlen(key); ++i) if(key[i] == '.' || key[i] == ',') key[i] = ' ';
		len = -1;
		istringstream iss(key);
		string tmp;
		
		while(iss >> tmp)
		{
			if((int)tmp.size() >= len) len = tmp.size(), str = tmp;
		}
		
		cout << str <<endl;	
	}	
}