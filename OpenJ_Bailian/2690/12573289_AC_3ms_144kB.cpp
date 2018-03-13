#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 100;
char key[MAXN];
 
int main()
{
	while(cin.getline(key, 80))
	{
		for(int i = 0; i < strlen(key); ++i)
		{
			if(i == 0 && islower(key[i])) key[i] = toupper(key[i]);
			else if(islower(key[i]) && key[i - 1] == ' ') key[i] = toupper(key[i]);	
		}	
		cout << key <<endl;
	}	
	return 0;
} 
